//
// Created by Ömür on 8.11.2018.
//

#include "BinaryHeap.h"


BinaryHeap::BinaryHeap(int capacity) {
    currentSize=0;
    array = std::vector<Person*>(capacity);
    arrival_based = true;
}

BinaryHeap::~BinaryHeap() {
    if(!isEmpty()){
        for(int i = 1; i <= currentSize;i++){
            delete array[i];
        }
    }
}

bool BinaryHeap::isEmpty( ) {
    return currentSize == 0;
}

void BinaryHeap::insert( Person* x )
{
    if(arrival_based){
        if( currentSize == array.size( ) - 1 ){
            array.resize( array.size( ) * 2 );
        }

        // Percolate up
        int hole = ++currentSize;
        for( ; hole > 1 && x->time < array[ hole / 2 ]->time; hole /= 2 ){
            array[ hole ] = std::move( array[ hole / 2 ] );
        }
        array[ hole ] = std::move( x );
    }else{
        if( currentSize == array.size( ) - 1 ){
            array.resize( array.size( ) * 2 );
        }


        // Percolate up
        int hole = ++currentSize;
        for( ; hole > 1 && x->board < array[ hole / 2 ]->board; hole /= 2 ){
            array[ hole ] = std::move( array[ hole / 2 ] );
        }

        array[ hole ] = std::move( x );
    }

}

Person* BinaryHeap::findMin( )
{
    if(isEmpty()){
        return nullptr;
    }
    return array[ 1 ];
}

Person* BinaryHeap::deleteMin()
{
    if(isEmpty()){
        return nullptr;
    }

    Person* minItem = array[ 1 ];
    array[ 1 ] = std::move( array[ currentSize-- ] );
    percolateDown( 1 );
    return minItem;
}

void BinaryHeap::percolateDown( int hole )
{
    if(arrival_based){
        int child;
        Person* tmp = std::move( array[ hole ] );
        for( ; hole * 2 <= currentSize; hole = child )
        {
            child = hole * 2;
            if( child != currentSize && array[ child + 1 ]->time < array[ child]->time )
                ++child;
            if( array[ child ]->time < tmp->time )
                array[ hole ] = std::move( array[ child ] );
            else
                break;
        }
        array[ hole ] = std::move( tmp );
    }else{
        int child;
        Person* tmp = std::move( array[ hole ] );
        for( ; hole * 2 <= currentSize; hole = child )
        {
            child = hole * 2;
            if( child != currentSize && array[ child + 1 ]->board < array[ child]->board )
                ++child;
            if( array[ child ]->board < tmp->board )
                array[ hole ] = std::move( array[ child ] );
            else
                break;
        }
        array[ hole ] = std::move( tmp );
    }

}

void BinaryHeap::buildHeap( )
{
    for( int i = currentSize / 2; i > 0; --i )
        percolateDown( i );
}
