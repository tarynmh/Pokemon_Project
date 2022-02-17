// CS1300 Fall 2019
// Author: Taryn Hovenkamp
// Recitation: 202 – Joewie Koh
// Project 3

#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <vector>
using namespace std;

class Pokemon
{
    private:
    int numPkmn; // keeps track of number of pokemon you currently have (in pokedex)
    string pkmnName;
    bool activePkmn = false;
    bool fainted = false; // if the pokemon is fainted
    bool dead = false; // if the pokemon dies by a random event
    bool isShiny = false;
    int lvl;
    int pkmnID; // the number the pokemon is in the pokedex
    int hp;
    int atk;
    int def;
    int spd;
    int max;
    int maxHp;
    string type1;
    string type2;
    int pkmnPosRow;
    int pkmnPosCol;
    
    
    public:
    Pokemon();
    int getPosRow();
    int getPosCol();
    void setPosRow(int y);
    void setPosCol(int x);
    string getName();
    void setName(string name);
    int getHp();
    void setHp(int hp1);
    int getMaxHp();
    void setMaxHp(int maxHp1);
    int getID();
    void setID(int id);
    int getAtk();
    void setAtk(int atk1);
    int getDef();
    void setDef(int def1);
    int getSpd();
    void setSpd(int spd1);
    int getMax();
    void setMax(int max1);
    string getType1();
    string getType2();
    void setType1(string t1);
    void setType2(string t2);
    void setActivePkmn(string pkmn); // sets active pokemon --> can only be a pokemon in the party
    void levelUp();
    void healPkmn(); // for pokemon center
    // bool getActivePokemon();
    // void setActivePkmn(bool flag);
};

#endif