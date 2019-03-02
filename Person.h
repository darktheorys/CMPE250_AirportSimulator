//
// Created by Ömür on 8.11.2018.
//

#ifndef PROJECT2RENEWED_PERSON_H
#define PROJECT2RENEWED_PERSON_H
class Person{
public:
    int event = 0;
    int time = 0;
    int arrive, board, lug_spent, sec_spent;
    bool vip_pass , lug_pass;
    Person(int _arrive, int _board, int _lug_spent, int _sec_spent, char _has_vip, char _has_lug);
};
#endif //PROJECT2RENEWED_PERSON_H
