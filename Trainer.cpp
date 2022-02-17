#include "Trainer.h"
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Trainer::Trainer()
{
    vector<Pokemon> party;
    trainerPosRow = 0;
    trainerPosCol = 0;
    trainerDefeated = false;
    trainerName = "";
}

Trainer::Trainer(string tname, int posrow, int poscol)
{
    vector<Pokemon> party;
    trainerPosRow = posrow;
    trainerPosCol = poscol;
    trainerDefeated = false;
    trainerName = tname;
}

string Trainer::getTrainerName()
{
    return trainerName;
}

void Trainer::setTrainerName(string tName)
{
    trainerName = tName;
}

int Trainer::getNumPokeballs()
{
    return numPokeballs;
}

void Trainer::setNumPokeballs(int pokeballs)
{
    numPokeballs = pokeballs;
}

int Trainer::getNumBadges()
{
    return numBadges;
}

void Trainer::setNumBadges(int badges)
{
    numBadges = badges;
}

int Trainer::getPoints()
{
    return points;
}

void Trainer::setPoints(int pts)
{
    points = pts;
}

void Trainer::addPartyPkmn(Pokemon pokemon)
{
    if(party.size() < 6)
    {
        party.push_back(pokemon);
    }
    
    pokedex.push_back(pokemon);
}

bool Trainer::checkActivePkmn(vector<Pokemon> pokemon)
{
    for(int i = 0; i < pokemon.size(); i++)
    {
        if(i == 0)
        {
            return true;
        }
        // if(pokemon[i].getActivePokemon() == true)
        // {
        //     return true;
        // }
    }
}

void Trainer::printPartyPkmn()
{
    cout << "NAME: " << party[0].getName() << " (ACTIVE)" << ", HP: " << party[0].getHp() << ", ATK: " << party[0].getAtk();
    cout << ", DEF: " << party[0].getDef() << ", SPD: " << party[0].getSpd() << ", MAX: " << party[0].getMax() << endl;
    for(int i = 1; i < party.size(); i++)
    {
        cout << "NAME: " << party[i].getName() << ", HP: " << party[i].getHp() << ", ATK: " << party[i].getAtk();
        cout << ", DEF: " << party[i].getDef() << ", SPD: " << party[i].getSpd() << ", MAX: " << party[i].getMax() << endl;
    }
}

void Trainer::printPokedex()
{
    for(int i = 0; i < pokedex.size(); i++)
    {
        cout << i + 1 << ". " << pokedex[i].getName() << ", " << pokedex[i].getType1() << " " << pokedex[i].getType2() << endl;
    }
}

void Trainer::printPkmnBattle()
{
    for(int i = 0; i < party.size(); i++)
    {
        cout << i + 1 << ". " << party[i].getName() << endl;
    }
}

void Trainer::setPartySize(int size)
{
    // sets the party size of the trainers (for gyms)
}

int Trainer::getTrainerPosCol()
{
    return trainerPosCol;
}

void Trainer::setTrainerPosCol(int x)
{
    trainerPosCol = x;
}

int Trainer::getTrainerPosRow()
{
    return trainerPosRow;
}

void Trainer::setTrainerPosRow(int y)
{
    trainerPosRow = y;
}

int Trainer::getPartySize()
{
    return party.size();
}

void Trainer::setParty(vector<Pokemon> pkmn)
{
    party = pkmn;
}

void Trainer::rest()
{
    if(getNumPokeballs() > 0)
    {
        for(int i = 0; i < party.size(); i++)
        {
            party[i].setHp(party[i].getHp()+1);
        }
        setNumPokeballs(getNumPokeballs()-1);
    }
    else
    {
        cout << "You're out of pokeballs!" << endl;
    }
    
}

void Trainer::restPokeCenter()
{
    for(int i = 0; i < party.size(); i++)
    {
        party[i].setHp(party[i].getMaxHp());
    }
}

void Trainer::switchSuite(int pokedexIndex[6])
{
    while(party.size() != 0)
    {
        party.pop_back();
    }
    for(int i = 0; i < 6 && pokedexIndex[i] >= 0; i++) 
    {
        if(pokedexIndex[i] > 0 && pokedexIndex[i] <= pokedex.size()) // cant be less than zero
        {
            party.push_back(pokedex[pokedexIndex[i]-1]); // -1 because your printed message displays the index + 1
        }
    }
    
    // only available when at a pokemon center
    // allows the user to switch pokemon
    // utilizes pop_back functions
}

vector<Pokemon> Trainer::getParty()
{
    return party;
}

void Trainer::death()
{
    srand(time(nullptr));
    int value = rand() % 6;
    for(int i = 1; i < party.size(); i++)
    {
        if(value == i)
        {
            cout << "Terrible news... your " << party[i].getName() << " died due to a mysterious illness." << endl << "You'll never forget the adventures you've been on together. Rest in peace, dear friend." << endl;
            cout << endl;
            party.erase(party.begin()+i);
            pokedex.erase(pokedex.begin()+i);
        }
    }
}

void Trainer::hiddenTreasure()
{
    srand(time(nullptr));
    int value = rand() % 2; // 50% chance
    string number;
    int numberI = 0;
    if(value == 0)
    {
        setNumPokeballs(getNumPokeballs()+1);
        cout << "Wow! You've stumbled upon a secret stash of pokeballs. You now have " << getNumPokeballs() << " pokeballs." << endl;
        cout << endl;
    }
    if(value == 1)
    {
        cout << "Wow! You found a rare candy! Who will you feed it to?" << endl;
        for(int i = 0; i < party.size(); i++)
        {
            cout << i + 1 << ". " << party[i].getName() << endl;
        }
        getline(cin, number);
        numberI = stoi(number);
        party[numberI-1].levelUp();
        cout << endl;
        cout << party[numberI-1].getName() << " leveled up!" << endl;
        cout << endl;
    }
}

void Trainer::switchBattle(int numberI)
{
  
    Pokemon held;
    held = party[0];
    // player.getParty().push_back(held[0]);
    // player.getParty()[number-1]
    
    party[0] = party[numberI-1];
    party.erase(party.begin()+numberI-1); //
    party.push_back(held);
}

void Trainer::takeDamage(int x)
{
    party[0].setHp(party[0].getHp()-x);
}

void Trainer::levelUpActive()
{
    party[0].levelUp();
    for(int i = 0; i < pokedex.size(); i++)
    {
        if(pokedex[i].getName() == party[0].getName())
        {
            pokedex[i].levelUp();
        }
    }
}

bool Trainer::partyDead()
{
    for(int i = 0; i < party.size(); i++)
    {
        if(party[i].getHp() != 0)
        {
            return false;
        }
    }
    return true;
}

bool Trainer::checkTypeWin()
{
    vector<string> types;
    bool flag1 = true;
    bool flag2 = true;
    for(int i = 0; i < pokedex.size(); i++)
    {
        string type1 = pokedex[i].getType1();
        string type2 = pokedex[i].getType2();
        for(int j = 0; j < types.size(); j++)
        {
            if(types[i] == type1)
            {
                flag1 = false;
            }
            if(types[i] == type2)
            {
                flag2 = false;
            }
        }
        if(flag1)
        {
            types.push_back(type1);
        }
        if(flag2)
        {
            types.push_back(type2);
        }
    }
    if(types.size() >= 8)
    {
        return true;
    }
    return false;
}