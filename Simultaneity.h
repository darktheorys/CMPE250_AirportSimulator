//
// Created by Ömür on 9.11.2018.
//

#ifndef PROJECT2_SiMULTANEiTY_H
#define PROJECT2_SiMULTANEiTY_H

#include <vector>
#include "Person.h"


class Simultaneity
{
public:
    explicit Simultaneity( int capacity = 10 );
    bool isEmpty( );
    void insert( Person * x );
    Person* deleteMin();
    Person* getFirst();
    bool arrive = false;
    ~Simultaneity();
    std::vector<Person*> array; // The heap array
    int currentSize; // Number of elements in heap
private:
    void percolateDown( int hole );
};


#endif //PROJECT2_SiMULTANEiTY_H
