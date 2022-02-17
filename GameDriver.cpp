// Taryn Hovenkamp
// CSCI 1300 - 202
// Pokemon Project


#include "Game.h"
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include "Game.h"
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main()
{
    Game g1 = Game("mapPoke.txt");
    g1.readPokemon("pokemon.txt");
    g1.welcomeMenu();
    g1.initializeTrainers();
    g1.initializeWildPkmn();
    g1.wildPkmnMap();
    
    g1.turnMenu();
    
    cout << endl;
  
}

