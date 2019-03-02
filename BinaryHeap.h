//
// Created by Ömür on 8.11.2018.
//

#ifndef PROJECT2RENEWED_BiNARYHEAP_H
#define PROJECT2RENEWED_BiNARYHEAP_H

#include <vector>
#include "Person.h"

class BinaryHeap
{
public:
    explicit BinaryHeap( int capacity = 16 );
    bool isEmpty( );
    Person* findMin( );
    void insert( Person * x );
    Person* deleteMin();
    bool arrival_based = true;
    ~BinaryHeap();
    std::vector<Person*> array; // The heap array
    int currentSize; // Number of elements in heap
    void buildHeap( );
private:
    void percolateDown( int hole );
};
#endif //PROJECT2RENEWED_BiNARYHEAP_H
