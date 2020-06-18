// 150160048 Ömer Faruk DAVARCI

#include <iostream>
#include <cstring>
#include "pokemons.h"
#include "attacks.h"
#include "battle_manager.h"
#include "graph.h"
#include <cstdlib>
#include <sstream>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
    Tree Great_Tree;

    if(argc == 1){
        cout << "Given arguments are not correct!" << endl;
        cout << "You can modify the given arguments from below" << endl;
        cout << "part1 <level>" << endl;
        cout << "part2 <level> bfs/dfs" << endl;
        cout << "part3 pikachu/blastoise" << endl;
    }else if(argc > 2){
        if(strcmp(argv[1], "part1") == 0){
            istringstream iss( argv[2] );
            int val;
            if (iss >> val)
            {
                Great_Tree.max_level = val;
            }

            Great_Tree.insertion(Great_Tree.root);
            Great_Tree.traverseToLevelOrder(Great_Tree.root);
        }else if(strcmp(argv[1], "part2") == 0 && (strcmp( argv[3], "dfs") == 0 || strcmp( argv[3], "bfs") == 0)){
            auto started = chrono::high_resolution_clock::now();

            istringstream iss( argv[2] );
            int val;
            if (iss >> val)
            {
                Great_Tree.max_level = val;
            }

            Great_Tree.insertion(Great_Tree.root);

            if(strcmp( argv[3], "dfs") == 0){
                Great_Tree.dfs(Great_Tree.root);
                cout << "The visited node count is: " <<Great_Tree.nodes << endl;
            }else if(strcmp( argv[3], "bfs") == 0){
                Great_Tree.bfs(Great_Tree.root);
                cout << "The visited node count is: " <<Great_Tree.nodes << endl;
            }else{
                cout << "Wrong argument choose bfs or dfs!" << endl;
                return 0;
            }

            auto done = std::chrono::high_resolution_clock::now();

            cout << "The process time is(milliseconds): "<< chrono::duration_cast<chrono::milliseconds>(done-started).count() << endl;
        }else if(strcmp(argv[1], "part3") == 0){
            Great_Tree.max_level = 8; // i have calculated that the closest level to both pokemons can be died

            string _find = argv[2];

            Great_Tree.find = _find;

            Great_Tree.insertion(Great_Tree.root);

            Great_Tree.dfs(Great_Tree.root); // i have selected the dfs because it finds faster the closest path

            Great_Tree.find_easist();

            cout << "Level Count: " << Great_Tree.levelcount << endl;
            cout << "Probability: " << Great_Tree.dfs_prob << endl;
        }

    }

    return 0;
}