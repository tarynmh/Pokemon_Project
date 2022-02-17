// CS1300 Fall 2019
// Author: Taryn Hovenkamp
// Recitation: 202 – Joewie Koh
// Project 3

#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Pokemon.h"
#include <string>
#include <vector>

using namespace std;

class Game
{
    private:
    Map map; // map object
    Trainer player;
    vector<Trainer> trainers; // defines a vector to hold the trainers
    vector<Pokemon> AllPkmn;
    
    // vector<Pokemon> wildPkmn; // holds the wild pokemon and their locations, --> when caught, pop back and push back int pokedex or the party if it isnt full
    
    
    public:
    Game(string mapFileName);
    void setPkmnInitialized(bool pkmnI);
    void welcomeMenu(); // initializes the player --> could possibly be combined with chooseStarter
    void turnMenu();
    void readMap(string fileName); // function to read the text file map // set up first row to be boundary and first column to be boundary
    void readPokemon(string fileName); // reads and splits pokemon
    void displayMap(); // function to print the map to the screen
    void displayMiniMap();
    void initializeTrainers();
    void initializeTrainerPkmn();
    void initializeWildPkmn();
    void wildPkmnMap();
    void travel(char direction);
    void moveWildPkmn();
    void checkWildPkmn();
    bool checkGym();
    bool checkPokeCenter();
    void pokeCenterMenu();
    void switchSuite(int pokedexIndex[6]); // for pokemon center --> option to switch pokemon in party
    // void switchSuiteBattle();
    void battleWildPkmn(Pokemon pokemon);
    void battleTrainer();
    void fightWild();
    void fightTrainer();
    void switchPkmn();
    void run();
    void tryLuck();
    void gymMenu();
    int write();
};

#endif