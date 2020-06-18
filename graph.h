//
// Created by DAVARCI on 8.03.2020.
//

#ifndef ALGOTWO_GRAPH_H
#define ALGOTWO_GRAPH_H

#include <bits/stdc++.h>
#include <vector>
#include "pokemons.h"
#include "battle_manager.h"
#include <string.h>
#include <cstdlib>

class Node{
public:
    Battle battle;
    int level;
    vector<Node*> childs;
    Node *parent;
    bool effective;
    AttackType last_attack;

    Node() : parent(), effective(){
        last_attack = NoAttack;
        level = 0;
        parent = NULL;
        effective = false;
    }
};

class Tree{
public:
    Node *root;
    int level;
    int counter;
    int max_level;
    string find;
    double dfs_prob;
    int nodes;
    int levelcount;
    vector<Node*> paths;

    Tree() : root(){
        root = new Node();
        level = 0;
        counter = 0;
        max_level = 0;
        find = "None";
        dfs_prob = 0;
        nodes = 0;
        levelcount = 0;
    }
    ~Tree(){
        delete root;
    }

    void find_easist(){
        int size = paths.size();
        if(size == 0){
            return;
        }
        Node *trav = paths[0];
        int _lvl = max_level;
        for (int i = 0; i < size; ++i) {
            if(paths[i]->level < _lvl){
                _lvl = paths[i]->level;
                trav = paths[i];
            }
        }

        if(find == "pikachu"){
            int _levelcount = trav->level;
            this->dfs_prob = trav->battle.prob;
            while(trav->parent){
                string effectiveness;
                if(trav->effective){
                    effectiveness = "effective.";
                }else{
                    effectiveness = "noneffective.";
                }
                switch (trav->last_attack){
                    case SkullBash:
                        cout << "Pikachu used Skullbash. It's " << effectiveness << endl;
                        break;
                    case Slam:
                        cout << "Pikachu used Slam. It's " << effectiveness << endl;
                        break;
                    case Skip:
                        cout << "Used Skip. It's " << effectiveness << endl;
                        break;
                    case Tackle:
                        cout << "Pikachu used Tackle. It's " << effectiveness << endl;
                        break;
                    case WaterGun:
                        cout << "Blastoise used WaterGun. It's " << effectiveness << endl;
                        break;
                    case Bite:
                        cout << "Blastoise used Bite It's ." << effectiveness << endl;
                        break;
                    case NoAttack:
                        cout << "PP is not enough. It's " << effectiveness << endl;
                        break;
                    case Thundershock:
                        cout << "Pikachu used Thundershock. It's " << effectiveness << endl;
                        break;
                }
                trav = trav->parent;
            }
            this->levelcount = _levelcount;
            return;
        }else if(find == "blastoise"){
            int _levelcount = trav->level;
            this->dfs_prob = trav->battle.prob;
            while(trav->parent){
                string effectiveness;
                if(trav->effective){
                    effectiveness = "<effective>.";
                }else{
                    effectiveness = "<noneffective>.";
                }
                switch (trav->last_attack){
                    case SkullBash:
                        cout << "Pikachu used Skullbash." << effectiveness << endl;
                        break;
                    case Slam:
                        cout << "Pikachu used Slam. It's " << effectiveness << endl;
                        break;
                    case Skip:
                        cout << "Used Sklip. It's " << effectiveness << endl;
                        break;
                    case Tackle:
                        cout << "Pikachu used Tackle. It's " << effectiveness << endl;
                        break;
                    case WaterGun:
                        cout << "Blastoise used WaterGun. It's " << effectiveness << endl;
                        break;
                    case Bite:
                        cout << "Blastoise used Bite. It's " << effectiveness << endl;
                        break;
                    case NoAttack:
                        cout << "PP is not enough. It's " << effectiveness << endl;
                        break;
                    case Thundershock:
                        cout << "Pikachu used Thundershock. It's " << effectiveness << endl;
                        break;
                }
                trav = trav->parent;
            }
            this->levelcount = _levelcount;
            return;
        }
    }

    void bfs(Node *ptr)
    {
        int _nodes = 0;  // Initialize result

        // If root is empty, return
        if (ptr == NULL){
            this->nodes = _nodes;
        }

        // Create a queue and enqueue root to it.
        queue<Node *>q;
        q.push(ptr);
        // Level order traversal.
        while (!q.empty())
        {
            // Dequeue an item from queue
            Node *p = q.front();
            q.pop();
            _nodes += 1;
            // Enqueue all children of the dequeued item
            int size = p->childs.size();
            for (int i=0; i < size; i++){
                Node *trav = p->childs[i];
                if(find == "pikachu"){
                    if(!trav->battle.blast.is_alive()){
                        paths.push_back(trav);
                    }
                }else if(find == "blastoise"){
                    if(!trav->battle.pika.is_alive()){
                        paths.push_back(trav);
                    }
                }
                q.push(p->childs[i]);
            }
        }

        this->nodes = _nodes;
    }

    void dfs(Node *ptr)
    {
        if (ptr)
        {
            int N = ptr->childs.size();
            if(find == "pikachu"){
                if(!ptr->battle.blast.is_alive()){
                    paths.push_back(ptr);
                }
            }else if(find == "blastoise"){
                if(!ptr->battle.pika.is_alive()){
                    paths.push_back(ptr);
                }
            }
            this->nodes += 1;

            for (int i = 0; i < N; i++) {
                dfs(ptr->childs[i]);
            }
        }
    }

    void traverseToLevelOrder(Node *ptr)
    {
        if (ptr)
        {
            int N = ptr->childs.size();
            if(ptr->level == max_level){
                ptr->battle.print();
            }

            for (int i = 0; i < N; i++) {
                traverseToLevelOrder(ptr->childs[i]);
            }
        }
    }

    void pc(){
        cout << this->counter << endl;
    }

    void insertion(Node *ptr){

        if(ptr)
        {
            if(ptr->childs.empty()){
                this->level = ptr->level + 1;
            }
            int N;
            if(this->level % 2 == 1){
                N = 5;
                for (int i = 0; i < N; i++){
                    Node *p = new Node();
                    p->level = this->level;
                    p->battle.pika = ptr->battle.pika;
                    p->battle.blast = ptr->battle.blast;
                    p->parent = ptr;
                    if(this->level > 2){
                        p->battle.prob = ptr->battle.prob * 1/4;
                    }else{
                        p->battle.prob = ptr->battle.prob * 1/3;
                    }
                    ptr->childs.push_back(p);
                }

                if(ptr->level > 2){
                    Node *skip = new Node();
                    skip->level = this->level;
                    skip->battle.pika = ptr->battle.pika;
                    skip->battle.blast = ptr->battle.blast;
                    skip->parent = ptr;
                    ptr->childs.push_back(skip);
                    N = N +1;
                    skip->battle.prob = ptr->battle.prob * 1/N;
                }

                for (int j = 0; j < N; ++j) {
                    switch (j){
                        case 0:
                            if(ptr->childs[j]->battle.pika.can_thundershock()){
                                ptr->childs[j]->battle.pika.do_thundershock(ptr->childs[j]->battle.blast);
                                ptr->childs[j]->last_attack = Thundershock;
                                ptr->childs[j]->effective = true;
                            }else{
                                ptr->childs[j]->effective = false;
                                ptr->childs[j]->last_attack = NoAttack;
                            }
                            break;
                        case 1:
                            if(ptr->childs[j]->battle.pika.can_skullbash()){
                                ptr->childs[j]->battle.pika.do_skullbash(ptr->childs[j]->battle.blast, true);
                                ptr->childs[j]->effective = true;
                                ptr->childs[j]->battle.prob *= 0.7f;
                                ptr->childs[j]->last_attack = SkullBash;
                            }else{
                                ptr->childs[j]->battle.prob *= 0.7f;
                                ptr->childs[j]->effective = false;
                                ptr->childs[j]->last_attack = NoAttack;
                            }
                            break;
                        case 2:
                            if(ptr->childs[j]->battle.pika.can_skullbash()) {
                                ptr->childs[j]->battle.pika.do_skullbash(ptr->childs[j]->battle.blast, false);
                                ptr->childs[j]->battle.prob *= 0.3f;
                                ptr->childs[j]->effective = false;
                                ptr->childs[j]->last_attack = SkullBash;
                            }else{
                                ptr->childs[j]->battle.prob *= 0.3f;
                                ptr->childs[j]->effective = false;
                                ptr->childs[j]->last_attack = NoAttack;
                            }
                            break;
                        case 3:
                            if(ptr->childs[j]->battle.pika.can_slam()){
                                ptr->childs[j]->battle.pika.do_slam(ptr->childs[j]->battle.blast, true);
                                ptr->childs[j]->battle.prob *= 0.8f;
                                ptr->childs[j]->effective = true;
                                ptr->childs[j]->last_attack = Slam;
                            }else{
                                ptr->childs[j]->battle.prob *= 0.8f;
                                ptr->childs[j]->effective = false;
                                ptr->childs[j]->last_attack = NoAttack;
                            }
                            break;
                        case 4:
                            if(ptr->childs[j]->battle.pika.can_slam()){
                                ptr->childs[j]->battle.pika.do_slam(ptr->childs[j]->battle.blast, false);
                                ptr->childs[j]->battle.prob *= 0.2f;
                                ptr->childs[j]->effective = false;
                                ptr->childs[j]->last_attack = Slam;
                            }else{
                                ptr->childs[j]->battle.prob *= 0.2f;
                                ptr->childs[j]->effective = false;
                                ptr->childs[j]->last_attack = NoAttack;
                            }
                            break;
                        case 5:
                            if(this->level > 2){
                                ptr->childs[j]->effective = true;
                                ptr->childs[j]->battle.blast.do_skip();
                                ptr->childs[j]->last_attack = Skip;
                            }
                        default:
                            break;
                    }
                }

            }else{
                N = 3;
                for (int i = 0; i < N; i++){
                    Node *p = new Node();
                    p->level = this->level;
                    p->battle.pika = ptr->battle.pika;
                    p->battle.blast = ptr->battle.blast;
                    p->parent = ptr;
                    if(this->level > 2){
                        p->battle.prob = ptr->battle.prob * 1/4;
                    }else{
                        p->battle.prob = ptr->battle.prob * 1/3;
                    }
                    ptr->childs.push_back(p);
                }

                if(ptr->level > 2){
                    Node *skip = new Node();
                    skip->level = this->level;
                    skip->battle.pika = ptr->battle.pika;
                    skip->battle.blast = ptr->battle.blast;
                    skip->parent = ptr;
                    ptr->childs.push_back(skip);
                    N = N +1;
                    skip->battle.prob = ptr->battle.prob * 1/N;
                }

                for (int k = 0; k < N; ++k) {
                    switch (k){
                        case 0:
                            if(ptr->childs[k]->battle.blast.can_bite()){
                                ptr->childs[k]->battle.blast.do_bite(ptr->childs[k]->battle.pika);
                                ptr->childs[k]->effective = true;
                                ptr->childs[k]->last_attack = Bite;
                            }else{
                                ptr->childs[k]->effective = false;
                                ptr->childs[k]->last_attack = NoAttack;
                            }
                            break;
                        case 1:
                            if(ptr->childs[k]->battle.blast.can_watergun()){
                                ptr->childs[k]->battle.blast.do_watergun(ptr->childs[k]->battle.pika);
                                ptr->childs[k]->effective = true;
                                ptr->childs[k]->last_attack = WaterGun;
                            }else{
                                ptr->childs[k]->effective = false;
                                ptr->childs[k]->last_attack = NoAttack;
                            }
                            break;
                        case 2:
                            if(ptr->childs[k]->battle.blast.can_tackle()){
                                ptr->childs[k]->battle.blast.do_tackle(ptr->childs[k]->battle.pika);
                                ptr->childs[k]->effective = true;
                                ptr->childs[k]->last_attack = Tackle;
                            }else{
                                ptr->childs[k]->effective = false;
                                ptr->childs[k]->last_attack = NoAttack;
                            }
                            break;
                        case 3:
                            if(this->level > 2){
                                ptr->childs[k]->effective = true;
                                ptr->childs[k]->battle.blast.do_skip();
                                ptr->childs[k]->last_attack = Skip;
                            }
                        default:
                            break;
                    }
                }

            }

            for (int j = 0; j < N; ++j) {
                if(ptr->childs[j]->level < this->max_level && ptr->childs[j]->battle.pika.is_alive()
                                                            && ptr->childs[j]->battle.blast.is_alive()){
                    insertion(ptr->childs[j]);
                }else{
                    return;
                }
            }
        }
    }
};

#endif //ALGOTWO_GRAPH_H
