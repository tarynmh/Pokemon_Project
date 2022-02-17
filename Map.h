// CS1300 Fall 2019
// Author: Taryn Hovenkamp
// Recitation: 202 – Joewie Koh
// Project 3

#ifndef MAP_H
#define MAP_H
#include "Trainer.h"
#include <vector>
#include <string>

using namespace std;

class Map
{
    private:
        static const int ROWS = 25;
        static const int COLS = 16;
        char map[ROWS][COLS];
        vector<Pokemon> wildPkmn;
        bool wildPkmnEncountered = false;
        // int trainerPos[2];
        // int trainerposRow;
        // int trainerPosCol;
        
        // int vector of x pos and int vector of y pos
        // vector<Gym> gym;
    
    public:
        Map();
        // Map(Trainer playerin);
        int getTrainerPosRow();
        int getTrainerPosCol();
        void setTrainerPosRow(int posRow);
        void setTrainerPosCol(int posCol);
        void readMap(string fileName);
        void displayMap();
        void displayMiniMap(Trainer *playerptr); // trainer player
        string getTile(int row, int col);
        void initializeTrainers(vector<Pokemon> AllPkmn, vector<Trainer> *trainers);
        void initializeWildPkmn(vector<Pokemon> AllPkmn);
        void wildPkmnMap();
        void displayPkmnCenterMenu();
        void displayGymMenu();
        bool travel(Trainer *playerptr, char direction); // moves user.... trainer player, char direction
        void moveWildPkmn();
        Pokemon checkWildPkmn(Trainer *player);
        bool checkGym(Trainer player);
        bool checkPokeCenter(Trainer player);
        void tryLuck(Trainer *playerptr);
        void randEventSpawn(Trainer *playerptr);
        void hiddenTreasure(Trainer *playerptr);
        // void death(Trainer *playerptr);
        bool getwildPkmnEncountered();
        void setWildPkmnEncountered(bool flag);
        // void pokeCenterMenu(Trainer *Playerptr);
        void teleportPokeCenter(Trainer *playerptr);
        void erasePokemon(int index);
        void teleportPokemon(Pokemon poke);
};

#endif
