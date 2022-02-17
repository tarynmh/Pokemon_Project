#include "Pokemon.h"
#include <string>
#include <vector>
#include <cmath>

using namespace std;

Pokemon::Pokemon()
{
    numPkmn = 0; // keeps track of number of pokemon you currently have (in pokedex)
    pkmnName = "";
    activePkmn = false;
    fainted = false; // if the pokemon is fainted
    dead = false; // if the pokemon dies by a random event
    isShiny = false;
    lvl = 0;
    pkmnID = 0; // the number the pokemon is in the pokedex
    hp = 0;
    atk = 0;
    def = 0;
    spd = 0;
    max = 0;
    type1 = "";
    type2 ="";
    pkmnPosRow = 0;
    pkmnPosCol = 0;
}

int Pokemon::getPosRow()
{
    return pkmnPosRow;
}

int Pokemon::getPosCol()
{
    return pkmnPosCol;
}

void Pokemon::setPosRow(int y)
{
    pkmnPosRow = y;
}

void Pokemon::setPosCol(int x)
{
    pkmnPosCol = x;
}

string Pokemon::getName()
{
    return pkmnName;
}

void Pokemon::setName(string name)
{
    pkmnName = name;
}


int Pokemon::getHp()
{
    return hp;
}

void Pokemon::setHp(int hp1)
{
    
    hp = hp1;
    if(hp1 < 0)
    {
        hp = 0;
    }
}

int Pokemon::getAtk()
{
    return atk;
}

void Pokemon::setAtk(int atk1)
{
    atk = atk1;
}

int Pokemon::getDef()
{
    return def;
}

void Pokemon::setDef(int def1)
{
    def = def1;
}

int Pokemon::getSpd()
{
    return spd;
}

void Pokemon::setSpd(int spd1)
{
    spd = spd1;
}

int Pokemon::getMax()
{
    return max;
}

void Pokemon::setMax(int max1)
{
    max = max1;
}

int Pokemon::getID()
{
    return pkmnID;
}

void Pokemon::setID(int id)
{
    pkmnID = id;
}


string Pokemon::getType1()
{
    return type1;
}

string Pokemon::getType2()
{
    return type2;
}

void Pokemon::setType1(string t1)
{
    type1 = t1;
}

void Pokemon::setType2(string t2)
{
    type2 = t2;
}

int Pokemon::getMaxHp()
{
    return maxHp;
}

void Pokemon::setMaxHp(int maxHp1)
{
    maxHp = maxHp1;
}

void Pokemon::setActivePkmn(string pkmn)
{
    // sets active pokemon --> can only be a pokemon in the party
}

void Pokemon::levelUp()
{
    bool flagFull = (hp == maxHp);
    setMaxHp(round(getMaxHp()*0.02 + getMaxHp()));
    if(flagFull)
    {
        hp = maxHp;
    }
    setSpd(round(getSpd()*0.02 + getSpd()));
    
    if(getAtk() <= getMax())
    {
        setAtk(round(getAtk()*0.02 + getAtk()));
    }
    if(getDef() <= getMax())
    {
        setDef(round(getDef()*0.02 + getDef()));
    }
    // levels up the pokemon and increases stats
}

void Pokemon::healPkmn()
{
    // heals all pokemon --> for the pokemon center
}

// bool Pokemon::getActivePokemon()
// {
//     return activePkmn;
// }

// void Pokemon::setActivePkmn(bool flag)
// {
//     activePkmn = flag;
// }

