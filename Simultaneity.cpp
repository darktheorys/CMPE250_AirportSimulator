//
// Created by Ömür on 8.11.2018.
//

#include "Simultaneity.h"


Simultaneity::Simultaneity(int capacity) {
    currentSize=0;
    array = std::vector<Person*>(capacity);
}

Simultaneity::~Simultaneity() {
    if(!isEmpty()){
        for(int i = 1; i <= currentSize;i++){
            delete array[i];
        }
    }
}
Person* Simultaneity::getFirst() {
    if( isEmpty( ) ){
        return 0;
    }

    return array[1];
}

bool Simultaneity::isEmpty( ) {
    return currentSize == 0;
}

void Simultaneity::insert( Person* x )
{
    if(!arrive) {
        if (currentSize == array.size() - 1) {
            array.resize(array.size() * 2);
        }

        // Percolate up
        int hole = ++currentSize;
        for (; hole > 1 && x->event > array[hole / 2]->event; hole /= 2) {
            array[hole] = std::move(array[hole / 2]);
        }
        array[hole] = std::move(x);
    }else{
        if (currentSize == array.size() - 1) {
            array.resize(array.size() * 2);
        }

        // Percolate up
        int hole = ++currentSize;
        for (; hole > 1 && x->arrive < array[hole / 2]->arrive; hole /= 2) {
            array[hole] = std::move(array[hole / 2]);
        }
        array[hole] = std::move(x);


    }
}

Person* Simultaneity::deleteMin()
{
    if( isEmpty( ) ){
        return 0;
    }

    Person* minItem = array[ 1 ];
    array[ 1 ] = std::move( array[ currentSize-- ] );
    percolateDown( 1 );
    return minItem;
}

void Simultaneity::percolateDown( int hole )
{
    if(!arrive){
        int child;
        Person* tmp = std::move( array[ hole ] );
        for( ; hole * 2 <= currentSize; hole = child )
        {
            child = hole * 2;
            if( child != currentSize && array[ child + 1 ]->event > array[ child]->event )
                ++child;
            if( array[ child ]->event > tmp->event )
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
            if( child != currentSize && array[ child + 1 ]->arrive < array[ child]->arrive )
                ++child;
            if( array[ child ]->arrive < tmp->arrive )
                array[ hole ] = std::move( array[ child ] );
            else
                break;
        }
        array[ hole ] = std::move( tmp );
    }


}

