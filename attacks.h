//
// Created by DAVARCI on 8.03.2020.
//

#ifndef ALGOTWO_ATTACKS_H
#define ALGOTWO_ATTACKS_H

enum AttackType{
    Thundershock,
    SkullBash,
    Slam,
    Skip,
    Tackle,
    WaterGun,
    Bite,
    NoAttack
};

class PokeAttacks{
public:
    int pp;
    int accuracy;
    int damage;
    int usage_level;

    PokeAttacks(int pp, int accuracy, int damage, int usage_level){
        this->pp = pp;
        this->accuracy = accuracy;
        this->damage = damage;
        this->usage_level = usage_level;
    };

    explicit PokeAttacks(AttackType type){
        switch(type){
            case Thundershock:
                this->pp = 10;
                this->accuracy = 100;
                this->damage = 40;
                this->usage_level = 0;
                break;
            case SkullBash:
                this->pp = 15;
                this->accuracy = 70;
                this->damage = 50;
                this->usage_level = 0;
                break;
            case Slam:
                this->pp = 20;
                this->accuracy = 80;
                this->damage = 60;
                this->usage_level = 0;
                break;
            case Skip:
                this->pp = 100;
                this->accuracy = 100;
                this->damage = 0;
                this->usage_level = 3;
                break;
            case Tackle:
                this->pp = 10;
                this->accuracy = 100;
                this->damage = 30;
                this->usage_level = 0;
                break;
            case WaterGun:
                this->pp = 20;
                this->accuracy = 100;
                this->damage = 40;
                this->usage_level = 0;
                break;
            case Bite:
                this->pp = 25;
                this->accuracy = 100;
                this->damage = 60;
                this->usage_level = 0;
                break;
            case NoAttack:
                break;
        }
    }
};

#endif //ALGOTWO_ATTACKS_H
