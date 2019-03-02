//
// Created by Ömür on 8.11.2018.
//
#include "Day.h"

Day::Day(){;
}

Day::Day(int _luggage_counter, int _security_counter, BinaryHeap* _people, bool arrivalbased, bool vipPass, bool OTpass) {
    lc = new Counter(_luggage_counter, arrivalbased, OTpass);
    sc = new Counter(_security_counter, arrivalbased, vipPass);
    eventQueue =  _people;
    arrayBackup = std::vector<Person*>(_people->array.size());
    sm = new Simultaneity();
    sameTimeCheck = new Simultaneity();
    sameTimeCheck->arrive = true;
}

    void Day::start(Person* sent) {
        if (sent == nullptr && !eventQueue->isEmpty()) {
            time = eventQueue->findMin()->time;
        } else if (sent != nullptr) {
            time = sent->time;
            checkEvents(sent);
        }
        if (!eventQueue->isEmpty()) {
            Person *star = eventQueue->deleteMin();
            sm->insert(star);
            while (!eventQueue->isEmpty() && star->time == eventQueue->findMin()->time) {
                sm->insert(eventQueue->deleteMin());
            }

            star = sm->deleteMin();

            sameTimeCheck->insert(star);

            while(!sm->isEmpty() && star->event == sm->getFirst()->event){
                sameTimeCheck->insert(sm->deleteMin());
            }
            star = sameTimeCheck->deleteMin();

            while(!sameTimeCheck->isEmpty()){
                eventQueue->insert(sameTimeCheck->deleteMin());
            }

            while (!sm->isEmpty()) {
                eventQueue->insert(sm->deleteMin());
            }

            start(star);
        }
    }

    void Day::checkEvents(Person *p) {
        if (p->event == 0) {
            if (lc->useCounter(p)) {
                eventQueue->insert(p);
            }
        } else if (p->event == 1) {
            if (!p->lug_pass || !lc->pass) {
                Person *freed = lc->freeCounter(time);
                if (freed != nullptr) {
                    eventQueue->insert(freed);
                };
            }
            if (sc->useCounter(p)) {
                eventQueue->insert(p);
            }
        } else if (p->event == 2) {
            if (!p->vip_pass || !sc->pass) {
                Person *freed = sc->freeCounter(time);
                if (freed != nullptr) {
                    eventQueue->insert(freed);
                };
            }
            board(p);
        }
    }

    void Day::board(Person *p) {
        if(p->time <= p->board){
            boarded++;
        }else{
            missed++;
        }
        totalwait+= p->time-p->arrive;
        p->time = p->arrive;
        p->event = 0;
        arrayBackup[boarded+missed] = std::move(p);
    }

    Day::~Day() {
        delete lc;
        delete sc;;
        delete sm;
    }
