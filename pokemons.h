//
// Created by DAVARCI on 5.03.2020.
//

#ifndef ALGOTWO_POKEMONS_H
#define ALGOTWO_POKEMONS_H
#include <string>
#include "attacks.h"

using namespace std;

enum PokeType{
    None,
    Pika,
    Blast
};

class Pokemon{

private:
    int health_point;
    int power_point;
    PokeType type;
public:

    PokeType get_type(){
        return type;
    }

    int get_hp(){
        return health_point;
    };

    int get_pp(){
        return power_point;
    };

    bool is_alive(){
        return this->health_point > 0;
    }

    void set_hp(int hp){
        health_point = hp;
    };

    void set_pp(int pp){
        power_point = pp;
    };

    void do_skip(){
        AttackType a_type = Skip;
        PokeAttacks p_attack(a_type);
        this->set_pp(p_attack.pp + this->get_pp());
    };

    Pokemon() // default constructor
    {
        health_point = 0;
        power_point = 0;
        type = None;
    };

    explicit Pokemon(PokeType poke_type)
    {
        switch(poke_type){
            case Pika:
                health_point = 200;
                power_point = 100;
                type = Pika;
                break;
            case Blast:
                health_point = 200;
                power_point = 100;
                type = Pika;
                break;
            case None:
            default:
                health_point = 0;
                power_point = 0;
                type = None;
                break;
        }
    };
};

class Pikachu:public Pokemon{
public:
    Pikachu():Pokemon(Pika){
    }
    bool can_thundershock(){
        int tackle_pp = 10;
        return this->get_pp() >= tackle_pp;
    };

    bool can_skullbash(){
        int watergun_pp = 20;
        return this->get_pp() >= watergun_pp;
    };

    bool can_slam(){
        int bite_pp = 25;
        return this->get_pp() >= bite_pp;
    };

    void do_slam(Pokemon &p, bool success){
        AttackType a_type = Slam;
        PokeAttacks p_attack(a_type);
        if(success){
            p.set_hp(p.get_hp() - p_attack.damage);
        }
        this->set_pp(this->get_pp() - p_attack.pp);
    }

    void do_skullbash(Pokemon &p, bool success){
        AttackType a_type = SkullBash;
        PokeAttacks p_attack(a_type);
        if(success){
            p.set_hp(p.get_hp() - p_attack.damage);
        }
        this->set_pp(this->get_pp() - p_attack.pp);
    }

    void do_thundershock(Pokemon &p){
        AttackType a_type = Thundershock;
        PokeAttacks p_attack(a_type);
        p.set_hp(p.get_hp() - p_attack.damage);
        this->set_pp(this->get_pp() - p_attack.pp);
    }
};

class Blastoise:public Pokemon{
public:
    Blastoise():Pokemon(Blast){
    }
    bool can_tackle(){
        int tackle_pp = 10;
        return this->get_pp() >= tackle_pp;
    };

    bool can_watergun(){
        int watergun_pp = 20;
        return this->get_pp() >= watergun_pp;
    };

    bool can_bite(){
        int bite_pp = 25;
        return this->get_pp() >= bite_pp;
    };

    void do_bite(Pokemon &p){
        AttackType a_type = Bite;
        PokeAttacks p_attack(a_type);
        p.set_hp(p.get_hp() - p_attack.damage);
        this->set_pp(this->get_pp() - p_attack.pp);
    }

    void do_watergun(Pokemon &p){
        AttackType a_type = WaterGun;
        PokeAttacks p_attack(a_type);
        p.set_hp(p.get_hp() - p_attack.damage);
        this->set_pp(this->get_pp() - p_attack.pp);
    }

    void do_tackle(Pokemon &p){
        AttackType a_type = Tackle;
        PokeAttacks p_attack(a_type);
        p.set_hp(p.get_hp() - p_attack.damage);
        this->set_pp(this->get_pp() - p_attack.pp);
    }
};

#endif //ALGOTWO_POKEMONS_H
