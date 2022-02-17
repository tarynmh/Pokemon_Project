// CS1300 Fall 2019
// Author: Taryn Hovenkamp
// Recitation: 202 – Joewie Koh
// Project 3

#ifndef TRAINER_H
#define TRAINER_H
#include "Pokemon.h"
#include <vector>
#include <string>

using namespace std;

class Trainer
{
    private:
    int numPokeballs; // defines the number of pokeballs that the player has
    int numBadges; // defines the number of badges that the player has
    double points; // defines the number of points that the player has
    vector<Pokemon> party; // creates a vector of pokemon class that will be used to hold the user's party pokemon
    vector<Pokemon> pokedex;
    int trainerPosRow;
    int trainerPosCol;
    bool trainerDefeated;
    string trainerName;
    
    public:
    Trainer();
    Trainer(string tname, int posrow, int poscol);
    string getTrainerName();
    void setTrainerName(string tName);
    int getNumPokeballs();
    void setNumPokeballs(int pokeballs);
    int getNumBadges();
    void setNumBadges(int badges);
    int getPoints();
    void setPoints(int pts);
    void addPartyPkmn(Pokemon pokemon);
    void printPartyPkmn();
    void printPokedex();
    void setPartySize(int size);
    int getTrainerPosCol();
    int getTrainerPosRow();
    void setTrainerPosCol(int x);
    void setTrainerPosRow(int y);
    int getPartySize();
    void setParty(vector<Pokemon> pkmn);
    vector<Pokemon> getParty();
    void rest();
    void restPokeCenter();
    bool checkActivePkmn(vector<Pokemon> pokemon);
    void switchSuite(int pokeIndex[6]);
    void switchSuiteBattle();
    void printPkmnBattle();
    void death();
    void hiddenTreasure();
    void switchBattle(int numberI);
    void takeDamage(int x);
    void levelUpActive();
    bool partyDead();
    bool checkTypeWin();
};


#endif