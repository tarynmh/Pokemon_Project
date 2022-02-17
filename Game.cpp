#include "Game.h"
#include "Map.cpp"
#include "Pokemon.h"
#include "Trainer.h"
#include "split.cpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Game::Game(string mapFileName)
{
    vector<Pokemon> AllPkmn;
    vector<Trainer> trainers;
    // map = Map(player);
    map.readMap(mapFileName);
    // set everything to zero or empty
}

void Game::welcomeMenu()
{
    // displays the menu at the start of the game
    // initializes the player --> adds player name and starter pokemon to respective vectors
    string name;
    string starterChoice;
    int starterChoiceI;
    cout << "Welcome to the wonderful world of Pokemon!" << endl << endl << "I'm Professor Cyprus. And you are?" << endl;
    getline(cin, name);
    cout << endl;
    cout << name << "... that's a lovely name! Pleased to meet you!" << endl;
    player.setTrainerName(name);
    cout << "Alright " << name << ", before you can begin your journey, you need a companion!" << endl;
    cout << endl;
    cout << "Will it be the grass-type, Bulbasaur, the fire-type, Charmander, the water-type, Squirtle, or the electric-type, Pikachu?" << endl;
    cout << endl;
    cout << "Choose wisely. This will be your partner, after all!" << endl;
    cout << "1. Bulbasaur" << endl;
    cout << "2. Charmander" << endl;
    cout << "3. Squirtle" << endl;
    cout << "4. Pikachu" << endl;
    getline(cin, starterChoice);
    starterChoiceI = stoi(starterChoice);
    switch(starterChoiceI)
    {
        case 1:
            player.addPartyPkmn(AllPkmn[0]);
            player.setTrainerPosRow(12);
            player.setTrainerPosCol(9);
            break;
        case 2:
            player.addPartyPkmn(AllPkmn[3]);
            player.setTrainerPosRow(12);
            player.setTrainerPosCol(7);
            break;
        case 3:
            player.addPartyPkmn(AllPkmn[6]);
            player.setTrainerPosRow(12);
            player.setTrainerPosCol(8);
            break;
        case 4:
            player.addPartyPkmn(AllPkmn[24]);
            player.setTrainerPosRow(12);
            player.setTrainerPosCol(9);
            break;
        default:
            cout << "Please choose a valid option!" << endl;
            break;
    }
    cout << "A wonderful choice! I have a feeling you two are going to become best friends!" << endl;
    cout << endl;
    cout << "You're just about ready to leave. Here are some pokeballs to aid you in your journey." << endl;
    cout << endl;
    cout << "[ You received 10 pokeballs! ] " << endl;
    cout << endl;
    player.setNumPokeballs(10);
    cout << "These are very important! You can heal your Pokemon with them." << endl << "You'll get more if you beat trainers at gyms or successfully catch Pokemon, so be sure to do both!" << endl;
    cout << endl;
    cout << "Now then, that's enough of my rambling... you have a whole world ahead of you filled with Pokemon!" << endl << "Trust in your partner, and good luck!" << endl;
    cout << endl;
    cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl << endl;
}



void Game::readMap(string fileName)
{
    // function to read the text file map --> sets up first and last row to be a boundary and the first and last column to be a boundary
}

void Game::readPokemon(string fileName)
{
    ifstream inFile; // creates an input file stream
    inFile.open(fileName); // opens the file with the file stream
    string line = "";
    string temp_array[9];
    
    while(getline(inFile, line))
    {
        if(line != "" && line[0] != '#')
        {
            split(line, ',', temp_array, 9); // splitting up id, name, and stats of pokemon
            Pokemon p;
            p.setID(stoi(temp_array[0])); // setting id
            p.setName(temp_array[1]); // setting name
            p.setHp(stoi(temp_array[2])); // setting hp value
            p.setMaxHp(stoi(temp_array[2])); // setting max hp value
            p.setAtk(stoi(temp_array[3])); // setting attack value
            p.setDef(stoi(temp_array[4])); // setting defense value
            p.setSpd(stoi(temp_array[5])); // setting speed value
            p.setMax(stoi(temp_array[6])); // setting max value
            p.setType1(temp_array[7]); // setting first type
            p.setType2(temp_array[8]); // setting second type (if any)
            AllPkmn.push_back(p); // pushing everything back into a vector with all of the pokemon
            // pkmnInitialized = true; // all of the pokemon are now initialized!
        }
    }
    inFile.close(); // closes the file
}

void Game::turnMenu()
{
    string choice;
    int choiceI = 0;
    
    while(choiceI != 4)
    {
        map.displayMiniMap(&player);
        cout << endl;
        cout << "It's a perfect day for an adventure, " << player.getTrainerName() << "!" << endl;
        cout << endl;
        cout << "You currently have " << player.getNumPokeballs() << " pokeballs and your Pokemon are ready for anything!" << endl;
        cout << endl;
        player.printPartyPkmn();
        cout << endl;
        cout << endl;
        string direction;
	    cout << endl;
	    cout << "Choose an option: " << endl;
        cout << "1. Travel" << endl << "2. Rest" << endl << "3. Try Your Luck" << endl << "4. Quit the Game" << endl;
	    getline(cin, choice); // prompts user for choice input
	    switch(choice[0])
	    {
            case '1':
            {
                cout << "Choose a direction to travel: " << endl;
                cout << "North - w" << endl;
                cout << "East - d" << endl;
                cout << "South - s" << endl;
                cout << "West - a" << endl;
                getline(cin, direction);
                while(map.travel(&player, direction[0]) != true)
                {
                    getline(cin, direction);
                }
                
                moveWildPkmn();
                Pokemon wildPokemon = map.checkWildPkmn(&player);
                if(wildPokemon.getName() != "") 
                {
                    battleWildPkmn(wildPokemon);
                }
                
                if(map.checkGym(player) == true)
                {
                    for(int i = 0; i < 15; i++)
                    {
                        if(trainers[i].getTrainerPosCol() == player.getTrainerPosCol() && trainers[i].getTrainerPosRow() == player.getTrainerPosRow())
                        {
                            cout << endl;
                            cout << "You've arrived at a gym!" << endl << endl << trainers[i].getTrainerName() << " would like to battle!" << endl << endl;
                        }
                    }
                }
                
                if(map.checkPokeCenter(player) == true)
                {
                    pokeCenterMenu();
                }
                
                srand(time(nullptr));
                if(rand() % 100 < 30)
                {
                    map.randEventSpawn(&player);
                }
                if(rand() % 100 < 25)
                {
                    player.hiddenTreasure();
                }
                if(player.checkTypeWin())
                {
                    cout << "Fantastic, you've collected Pokemon of all 8 types! You win!" << endl;
                    write();
                    exit(0); // ends the game
                }
                if(rand() % 100 < 20)
                {
                    player.death();
                }
                break;
	        }
            case '2':
            {
                player.rest();
                break;
            }
            case '3':
            {
                map.tryLuck(&player);
                break;
            }
            
            case '4':
            {
                cout << "Goodbye!" << endl;
                write();
                return;
            }
            default:
            {
                cout << "Invalid option. Please enter a valid option!" << endl;
                break;
            }
                
	    }
       
    }
}

void Game::displayMap()
{
    map.displayMap();
}

void Game::displayMiniMap()
{
    map.displayMiniMap(&player); // map.displayMiniMap(player);
}

void Game::initializeTrainers()
{
    map.initializeTrainers(AllPkmn, &trainers);
}

void Game::initializeTrainerPkmn()
{
    int count = 0;
    srand(time(nullptr));
    while(count < 15)
    {
        int value = rand() % 151 + 1; // random number between 1-151
        int randValue = rand() % 6 + 1;
        for(int j = 0; j < randValue; j++)
        {
            for(int i = 0; i < 151; i++)
            {
                    if(AllPkmn[i].getID() == value)
                    {
                        trainers[count].addPartyPkmn(AllPkmn[i]);
                    }
            }
        }
        count++;
    }
    // for(int m = 0; m < 15; m++)
    // {
    //     cout << trainers[m].
    // }
}

void Game::initializeWildPkmn()
{
    map.initializeWildPkmn(AllPkmn);
}

void Game::wildPkmnMap()
{
    map.wildPkmnMap();
}

void Game::travel(char direction)
{
    map.travel(&player, direction); // map.travel(&player);
}

void Game::moveWildPkmn()
{
    map.moveWildPkmn();
}

void Game::checkWildPkmn()
{
    map.checkWildPkmn(&player);
}

bool Game::checkGym()
{
    map.checkGym(player);
}

bool Game::checkPokeCenter()
{
    map.checkPokeCenter(player);
}

void Game::battleWildPkmn(Pokemon pokemon)
{
    bool battleDone = false;
    cout << endl;
    cout << "You've encountered a wild " << pokemon.getName();
    cout << "!" << endl;
    cout << endl;
    bool playerFirst = player.getParty()[0].getSpd() >= pokemon.getSpd();
    
    while(!battleDone)
    {
        cout << "NAME: " << pokemon.getName() << ", HP: " << pokemon.getHp() << ", ATK: " << pokemon.getAtk() << ", DEF: " << pokemon.getDef() << ", SPD: " << pokemon.getSpd() << ", MAX: " << pokemon.getMax() << endl;
        cout << endl << endl;
        player.printPartyPkmn();
        cout << endl << endl;
        cout << "What will you do?" << endl;
        cout << "1. Fight" << endl << "2. Switch Active Pokemon" << endl << "3. Run" << endl;
        string choice;
        getline(cin, choice);
        switch(choice[0])
        {
            case '1':
            {
                srand(time(nullptr));
                if(rand() % 100 < 60)
                {
                    //for loop through party size and if all are 0 then go to one thing and if just active is 0 go to another
                    // for(int i = 0; i < player.getParty(); i++)
                    // {
                        
                    // }
                    // not 0 raise a flag and break;
                    if(playerFirst) // active pokemon attacks first
                    {
                        int A = rand() % player.getParty()[0].getAtk(); // random value between 0 and attacker's atk value
                        int D = rand() % pokemon.getDef(); // random value between 0 and defender's def value
                        cout << player.getParty()[0].getName() << " attacks first!" << endl;
                        if(A > D)
                        {
                            int damage = A - D;
                            pokemon.setHp(pokemon.getHp()-damage);
                            cout << player.getParty()[0].getName() << " deals " << damage << " damage!" << endl << endl;
                        }
                        else if(A <= D)
                        {
                            cout << "The attack missed!" << endl;
                            cout << endl;
                        }
                    }
                    else // wild pokemon attacks first
                    {
                        int D = rand() % player.getParty()[0].getAtk();
                        int A = rand() % pokemon.getDef();
                        cout << pokemon.getName() << " attacks first!" << endl << endl;
                        if(A > D)
                        {
                            int damage = A - D;
                            player.takeDamage(damage);
                            cout << pokemon.getName() << " deals " << damage << " damage!" << endl << endl;
                        }
                        else if(A <= D)
                        {
                            cout << "The attack missed!" << endl;
                            cout << endl;
                        }
                    }
                    playerFirst = !playerFirst; // resets bool
                    if(pokemon.getHp() == 0)
                    {
                        pokemon.setHp(pokemon.getMaxHp());
                        player.addPartyPkmn(pokemon);
                        player.levelUpActive();
                        player.setPoints(player.getPoints()+10);
                        player.setNumPokeballs(player.getNumPokeballs()-1);
                        cout << "You caught " << pokemon.getName() << "!" << endl;
                        battleDone = true;
                    }
                    if(player.partyDead())
                    {
                        cout << "All of your pokemon fainted." << endl;
                        cout << endl;
                        battleDone = true;
                        break;
                    }
                    if(player.getParty()[0].getHp() == 0 )
                    {
                        pokemon.levelUp(); // wild pokemon levels up
                        cout << "Your " << player.getParty()[0].getName() << " fainted!" << endl << "Choose another active Pokemon!" << endl;
                        string choice;
                        int numberI = 0;
                        while(true)
                        {
                            player.printPartyPkmn();
                    
                            getline(cin, choice);
                            numberI = stoi(choice); // -1
                            if(player.getParty()[numberI].getHp() == 0)
                            {
                                cout << player.getParty()[numberI].getName() << " cannot battle!" << endl;
                            }
                            else
                            {
                                break;
                            }
                        }
                        player.switchBattle(numberI);
                    
                        // battleDone = true;
                    }
                    
                }
                else
                {
                    bool escaped = false;
                    int C = 0;
                    int speed = pokemon.getSpd(); // wild pkmn speed
                    int speedActive = (player.getParty()[0].getSpd() / 4) % 256;
                    int count = 0;
                    
                    while(escaped == false)
                    {
                        if(speed > speedActive)
                        {
                            cout << "The wild pokemon escaped!" << endl;
                            cout << endl;
                            map.teleportPokemon(pokemon);
                            battleDone = true;
                            escaped = true;
                            // transport to nearest pokecenter
                        }
                        else
                        {
                            srand(time(nullptr));
                            int value = rand() % 255; //0-255
                            C = (((speed*32)/speedActive) + 30)*C;
                            if(C > 255)
                            {
                                cout << "The wild pokemon escaped!" << endl;
                                cout << endl;
                                map.teleportPokemon(pokemon);
                                battleDone = true;
                                escaped = true;
                            }
                            else
                            {
                                if(C > value)
                                {
                                    cout << "It tried to escape but failed!" << endl;
                                    cout << endl;
                                    count++;
                                }
                                else if(C < value)
                                {
                                    cout << "The wild pokemon escaped!" << endl;
                                    cout << endl;
                                    map.teleportPokemon(pokemon);
                                    escaped = true;
                                    battleDone = true;
                                }
                                
                            }
                        }
                    }
                }
                
                break;
            }
            case '2':
            {
                // get party vector
                // put in temp
                // push back
                // swap first and last
                Pokemon held[1];
    
                cout << "Choose an active pokemon:" << endl << endl;
                // player.printPartyPkmn();
                string number;
                int numberI = 0;
                player.printPartyPkmn();
                
                getline(cin, number);
                numberI = stoi(number); // -1
                player.switchBattle(numberI);
                
                break;
            }
            case '3':
            {
                bool escaped = false;
                int C = 0;
                int speed = player.getParty()[0].getSpd();
                int speedWild = (map.checkWildPkmn(&player).getSpd() / 4) % 256;
                int count = 0;
                
                while(escaped == false)
                {
                    if(speed > speedWild)
                    {
                        cout << "You got away safely!" << endl;
                        battleDone = true;
                        escaped = true;
                        // transport to nearest pokecenter
                    }
                    else
                    {
                        srand(time(nullptr));
                        int value = rand() % 255; //0-255
                        C = (((speed*32)/speedWild) + 30)*C;
                        if(C > 255)
                        {
                            cout << "You got away safely!" << endl;
                            battleDone = true;
                            escaped = true;
                        }
                        else
                        {
                            if(C > value)
                            {
                                cout << "You couldn't get away!" << endl;
                                count++;
                            }
                            else if(C < value)
                            {
                                cout << "You got away safely!" << endl;
                                escaped = true;
                                battleDone = true;
                            }
                            
                        }
                    }
                }
                break;
            }
        }
    }
}

void Game::fightWild()
{
    // function for fighting wild pokemon
    // if wild pokemon decides to flee --> option 1
    // if both sides attack --> option 2
}

void Game::fightTrainer()
{
    // function for fighting trainers
    // similar to fightWild() but pokemon are unable to flee
}

void Game::switchPkmn()
{
    // occurs during battle
    // gives player the option to switch their active pokemon (using their party vector)
}

void Game::run()
{
    // occurs during wild pokemon battles
    // gives player the option to run
}

void Game::battleTrainer()
{
    // bigger function that will incorporate helper functions (fight, switch, run)
    // occurs when battling a trainer
    // displays menu
}

void Game::tryLuck()
{
    map.tryLuck(&player); // passing by reference so player is updated
    // player location remains unchanged
    // check if wild pokemon is within 7x7
    // 50% of catching pokemon for free
}

void Game::gymMenu()
{
    if(map.checkGym(player))
    {
        cout << "Welcome to the gym!";
    }
}

void Game::pokeCenterMenu()
{
    if(map.checkPokeCenter(player))
    {
        cout << "You've arrived at a Pokemon center!" << endl << "Your party has been healed and your pokemon feel refreshed." << endl;
        cout << endl;
        player.restPokeCenter();
        cout << "Would you like to reorganize your party?" << endl;
        cout << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        string choice;
        getline(cin, choice);
        switch(choice[0])
        {
            case '1':
            {
                do {
                    cout << "These are the pokemon in your pokedex." << endl;
                    player.printPokedex();
                    cout << endl << "Who are you taking with you?" << endl << "The first one you choose will be your active pokemon!" << endl << "[ Choose up to 6 Pokemon ] " << endl;
                    string numbers;
                    getline(cin, numbers);
                    int pokedexIndex[6] = {-1, -1, -1, -1, -1, -1}; // 
                    string temp[6];
                    int numsplits = split(numbers, ' ', temp, 6);
                    for(int i = 0; i < numsplits; i++) // so you dont get an error if it's empty at a point
                    {
                        try
                        {
                            pokedexIndex[i] = stoi(temp[i]);
                            for(int j = 0; j < i; j++) // dont want to make first one in array zero...we want the second one to be equal to 0
                            {
                                if(pokedexIndex[i] == pokedexIndex[j]) // to make sure you dont have duplicates
                                {
                                    pokedexIndex[j] = 0;
                                }
                            }
                        }
                        catch(invalid_argument& e)
                        {
                            pokedexIndex[i] = 0;
                            // cout << "Catch" << endl;
                        }
                    }
                    player.switchSuite(pokedexIndex);
                    if(player.getPartySize() == 0)
                    {
                        cout << "No legal pokemon. Please try again!" << endl;
                    }
                }
                while(player.getPartySize() == 0);
                break;
            }
            
            case '2':
            {
                cout << "You're all set!" << endl;
                break;
            }
            default:
                cout << "Please choose a valid option!" << endl;
                break;
        }
        // function call to switch
    }
}

int Game::write()
{
    // ofstream out; // for writing
    // string filename = "resultsPokemon.txt";
    // out.open("resultsPokemon.txt");
    // ofstream out_file;
    // out_file.open("output.txt");
    // if(in_file.fail()) { return 0; }
    // out_file << name << " " << value << endl;
    // cout << "<Name>    <Won>   <points>" << endl;
    // cout << endl;
    // cout << player.getTrainerName() << "   " << "N" << "   " << player.getPoints() << endl;
    // out.close();
    
    ofstream file;
    file.open ("resultsPokemon.txt", ios::out | ios::app);
    file << endl << player.getTrainerName() << "    " << "N" << "       " << player.getPoints() << endl;
    file.close();
  return 0;
}