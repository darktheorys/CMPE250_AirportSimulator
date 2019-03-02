//
// Created by Ömür on 8.11.2018.
//

#ifndef PROJECT2RENEWED_DAY_H
#define PROJECT2RENEWED_DAY_H
#include "BinaryHeap.h"
#include "Person.h"
#include "Counter.h"
#include "Simultaneity.h"
class Day{
public:
    int time = 0;
    int boarded = 0;
    int missed = 0;
    int totalwait = 0;
    Simultaneity* sm;
    std::vector<Person*> arrayBackup;
    BinaryHeap *eventQueue;
    Simultaneity *sameTimeCheck;
    Counter* lc;
    Counter* sc;
    Day();
    explicit Day(int _luggage_counter = 0, int _security_counter = 0, BinaryHeap* _people = nullptr, bool arrivalBased = true, bool vipPass = false, bool OTpass = false);
    void start(Person *p = nullptr);
    void checkEvents(Person* sent);
    void board(Person* p);
    ~Day();
};
#endif //PROJECT2RENEWED_DAY_H
