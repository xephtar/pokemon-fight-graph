//
// Created by DAVARCI on 8.03.2020.
//

#ifndef ALGOTWO_BATTLE_MANAGER_H
#define ALGOTWO_BATTLE_MANAGER_H

#include "pokemons.h"
#include "attacks.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Battle{
public:
    Pikachu pika;
    Blastoise blast;
    double prob;

    Battle(){
        prob = 1;
    }

    void print(){
        cout << "P_HP:" << pika.get_hp() << " P_PP:" << pika.get_pp();
        cout << " B_HP:" << blast.get_hp() << " B_PP:" << blast.get_pp();
        cout << " PROB:" << setprecision(7) << float(this->prob) << endl;
    };
};

#endif //ALGOTWO_BATTLE_MANAGER_H
