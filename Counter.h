//
// Created by Ömür on 8.11.2018.
//

#ifndef PROJECT2RENEWED_COUNTER_H
#define PROJECT2RENEWED_COUNTER_H
#include "BinaryHeap.h"
#include "Person.h"
#include <queue>
#include "Simultaneity.h"
class Counter {
public:

    BinaryHeap* List;
    std::queue<Person*>* ListQ;
    int N;
    bool pass,arrivalBased;
    Simultaneity* ListCheck;
    explicit Counter(int _N = 0, bool _arrivalBased = true, bool _pass = false);
    bool useCounter(Person* p);
    Person* freeCounter(int time);
    ~Counter();
};
#endif //PROJECT2RENEWED_COUNTER_H
