//
// Created by Ömür on 8.11.2018.
//
#include "Person.h"

Person::Person(int _arrive, int _board, int _lug_spent, int _sec_spent, char _has_vip, char _has_lug){
    this->arrive = _arrive;
    this->board = _board;
    this->lug_spent = _lug_spent;
    this->sec_spent = _sec_spent;
    this->vip_pass  = _has_vip == 'V';
    this->lug_pass  = _has_lug == 'N';
    this->time = _arrive;
}