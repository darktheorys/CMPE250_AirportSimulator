//
// Created by Ömür on 8.11.2018.
//
#include "Counter.h"

Counter::Counter(int _N, bool _arrivalBased, bool _pass) {
    this->pass = _pass;
    this->arrivalBased = _arrivalBased;
    if(!arrivalBased){
        List = new BinaryHeap();
        List->arrival_based = _arrivalBased;
        ListCheck = new Simultaneity();
        ListCheck->arrive = true;
    }else{
        ListQ = new std::queue<Person*>;
    }
    this->N = _N;

}

bool Counter::useCounter(Person *p) {
    if((p->event == 0 && (!p->lug_pass || !pass)) || (p->event == 1 && (!p->vip_pass || !pass)) ) {
        if (N <= 0) {
            if (!arrivalBased) {
                List->insert(p);
            } else {
                ListQ->push(p);
            }
            return false;
        }
    }
    if(p->event == 0){
        if(!p->lug_pass || !pass) {
            N--;
            p->time = p->time + p->lug_spent;
        }
        p->event = 1;
        return  true;
    }
    if(p->event == 1){
        if(!p->vip_pass || !pass){
            N--;
            p->time = p->time + p->sec_spent;
        }
        p->event = 2;
        return  true;
    }
}

Person* Counter::freeCounter(int time){
    N++;
    Person* freed;
    if(!arrivalBased){
        if(!List->isEmpty()){
            freed = List->deleteMin();
            ListCheck->insert(freed);
            while (!List->isEmpty() && freed->board == List->findMin()->board) {
                ListCheck->insert(List->deleteMin());
            }
            freed = ListCheck->deleteMin();
            while (!ListCheck->isEmpty()) {
                List->insert(ListCheck->deleteMin());
            }
            freed->time = time;
            useCounter(freed);
            return freed;
        }
    }else{
        if(!ListQ->empty()){
            freed = ListQ->front();
            freed->time = time;
            ListQ->pop();
            useCounter(freed);
            return freed;
        }
    }
    return nullptr;
}
Counter::~Counter(){
    if(!arrivalBased){
        delete List;
        delete ListCheck;
    }
    else{
        delete ListQ;
    }
}