#include "Map.h"
#include "Trainer.h"
#include <iostream>
#include <fstream>

Map::Map()
{
    
}

// Map::Map(Trainer playerin)
// {
//     Trainer player = playerin;
// }

void Map::readMap(string fileName)
{
    ifstream inFile; // creates an input file stream
    inFile.open(fileName); // opens the file with the file stream
    string line = "";
    int i = 0; // this is equivalent to the rows
    while(getline(inFile, line))
    {
        if(line != "")
        {
            for(int j = 0; j < COLS; j++) // goes through the columns
            {
                map[i][j] = line[j*2]; // setting the map array equal to the line at j*2 (the columns multiplied by 2) so this skips the commas
            }
            i++; // increases the row
        }
    }
    inFile.close();
}

void Map::displayMap()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void Map::displayMiniMap(Trainer *playerptr) // displayMiniMap(Trainer player)
{
    int row = playerptr->getTrainerPosRow();
    int col = playerptr->getTrainerPosCol();
    int rowcen = row; // the center of the minimap will be relative to the player's position
    int colcen = col; // the center of the minimap will be relative to the player's position
    
    if(rowcen < 3) // xcen cannot be less than 3 (this would make the value negative)
    {
        rowcen = 3; // if it is, set xcen to 3 so it will simply equal 0
    }
    if(colcen < 3) // ycen cannot be less than 3 (this would make the value negative)
    {
        colcen = 3; // if it is, set ycen to 3 so it will simply equal 0
    }
    if(rowcen > 21) // xcen can also not be greater than 21 because 21+4 = 25 and that is the number of rows
    {
        rowcen = 21; // if it is, set xcen to 21 so it will simply equal 25
    }
    if(colcen > 12) // ycen can also not be greater than 12 because 12+4 is 16 and that is the number of columns
    {
        colcen = 12; // if it is, set ycen to 12 so it will simply equal 16
    }
    for(int i = rowcen-3; i < rowcen+4; i++) // i cant be greater than 25
    {
        for(int j = colcen-3; j < colcen+4; j++) // y cant be greater than 16
        {
            if(i == row && j == col) // check where the player's position is
            {
                cout << "@"; // this marks the player
            }
            else if(map[i][j] == 'p')
            {
                cout << "*";
            }
            else if(map[i][j] == 'w')
            {
                cout << "~";
            }
            else
            {
                cout << map[i][j];
            }
        }
        cout << endl;
    }
}

string Map::getTile(int row, int col)
{
    // string tile;
    // for(int i = 0; i < ROWS; i++)
    // {
    //     for(int j = 0; j < COLS; j++)
    //     {
    //         if(i == row && j == col)
    //         {
    //             tile = map[i][j];
    //         }
    //     }
    // }
    // return tile;
}

void Map::initializeTrainers(vector<Pokemon> AllPkmn, vector<Trainer> *trainersptr)
{
    trainersptr->push_back(Trainer("Claude", 1, 7));
    trainersptr->push_back(Trainer("Amelia", 1, 14));
    trainersptr->push_back(Trainer("Blaire", 3, 2));
    trainersptr->push_back(Trainer("Becca", 4, 11));
    trainersptr->push_back(Trainer("Ashe", 7, 15));
    trainersptr->push_back(Trainer("Lyra", 8, 1));
    trainersptr->push_back(Trainer("Jamie", 10, 8));
    trainersptr->push_back(Trainer("Willow", 11, 11));
    trainersptr->push_back(Trainer("Gale", 12, 15));
    trainersptr->push_back(Trainer("Dimitri", 13, 2));
    trainersptr->push_back(Trainer("Rhea", 17, 1));
    trainersptr->push_back(Trainer("Walter", 19, 8));
    trainersptr->push_back(Trainer("Forrest", 21, 12));
    trainersptr->push_back(Trainer("Diane", 22, 6));
    trainersptr->push_back(Trainer("Robin", 23, 1));
    
    srand(time(nullptr));
    for(int i = 0; i < trainersptr->size(); i++)
    {
        int numPokemon = rand() % 6 + 1;
        for(int j=0; j<numPokemon; j++)
        {
             int value = rand() % 151; // random number between 0-150
            (*trainersptr)[i].addPartyPkmn(AllPkmn[value]);
        }
    }
}

void Map::initializeWildPkmn(vector<Pokemon> AllPkmn)
{
    int count = 0;
    srand(time(nullptr));
    while(count < 20)
    {
        int value = rand() % 151 + 1; // random number between 1-151
        for(int i = 0; i < 151; i++)
        {
            if(value != 144 && value != 145 && value != 146 && value != 150 && value != 151)
            {
                if(AllPkmn[i].getID() == value)
                {
                    wildPkmn.push_back(AllPkmn[i]);
                }
            }
        }
        count++;
    }
    // for(int i = 0; i < 20; i++)
    // {
    //     cout << wildPkmn[i].getPosRow() << ", " << wildPkmn[i].getPosCol() << endl;
    // }
}

void Map::wildPkmnMap()
{
    int count = 0;
    srand(time(nullptr));
    while(count < 20)
    {
        int rowPos = rand() % 25; // random number between 1-25
        int colPos = rand() % 16;
        
        if(map[rowPos][colPos] == 'p')
        {
            wildPkmn[count].setPosRow(rowPos);
            wildPkmn[count].setPosCol(colPos);
            count++;
        }
    }
    
    
    // for(int m = 0; m < 20; m++)
    // {
    //     cout << wildPkmn[m].getPosRow() << ",";
    //     cout << wildPkmn[m].getPosCol() << endl;
    // }
        
}

void Map::displayPkmnCenterMenu()
{
    
    // only occurs when pkmncenter bool is true
    // opens up menu to heal or switch pokemon
}

void Map::displayGymMenu()
{
    // only occurs when gym bool is true
    // opens up a menu to fight the trainer
}

bool Map::travel(Trainer *playerptr, char direction) // w a s d ... travel(Trainer player, char direction)
{
    int row = playerptr->getTrainerPosRow();
    int col = playerptr->getTrainerPosCol();
    switch(direction)
    {
        case 'w':
            row--;
            break;
        
        case 'a':
            col--;
            break;
        
        case 's':
            row++;
            break;
            
        case 'd':
            col++;
            break;
    }
    if(map[row][col] == 'w') 
    {
        cout << "You can't go in the water!" << endl << "Please enter another option." << endl;
        return false;
    }
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        cout << "You can't go outside the map!" << endl << "Please enter another direction." << endl;
        return false;
    }
    playerptr->setTrainerPosRow(row);
    playerptr->setTrainerPosCol(col);
    return true;
    
    // moves the user and the pokemon in their party
    // north, east, south, west
}

void Map::moveWildPkmn()  // moves wild pokemon and updates their positions
{
    srand(time(nullptr));
    int i = 0;
    while(i < 20)
    {
        int row = wildPkmn[i].getPosRow();
        int col = wildPkmn[i].getPosCol();
        // cout<<row<<", "<<col<<endl;
        do 
        {
            row = wildPkmn[i].getPosRow();
            col = wildPkmn[i].getPosCol();
            int value = rand() % 4 + 1;
            // cout << value << endl;
            switch(value)
            {
                case 1: // up one
                    row--;
                    break;
            
                case 2: // left one
                    col--;
                    break;
            
                case 3: // down one
                    row++;
                    break;
                
                case 4: // right one
                    col++;
                    break;
            }
        }
        while (map[row][col] != 'p' || row < 0 || row >= ROWS || col < 0 || col >= COLS); // making sure it moves if the first time it runs it doesnt stand still
        wildPkmn[i].setPosRow(row);
        wildPkmn[i].setPosCol(col);
        // cout << wildPkmn[i].getPosRow() << ",";
        // cout << wildPkmn[i].getPosCol()<<endl;
        i++;
    }
   
}

Pokemon Map::checkWildPkmn(Trainer *player)
{
    int row = player->getTrainerPosRow();
    int col = player->getTrainerPosCol();
    for(int i = 0; i < wildPkmn.size(); i++)
    {
        if(row-2 <= wildPkmn[i].getPosRow() && row+2 >= wildPkmn[i].getPosRow() && col-2 <= wildPkmn[i].getPosCol() && col+2 >= wildPkmn[i].getPosCol())
        {
            Pokemon poke = wildPkmn[i];
            wildPkmn.erase(wildPkmn.begin()+i); // erases the wild pokemon after encountering it
            
            return poke; // returns which pokemon is near you
        }
    }
    return Pokemon();
 }
 
bool Map::checkGym(Trainer player)
 {
    int row = player.getTrainerPosRow();
    int col = player.getTrainerPosCol();
    return map[row][col] == 'G'; // returns as true
 }
 
 
 bool Map::checkPokeCenter(Trainer player)
 {
    int row = player.getTrainerPosRow();
    int col = player.getTrainerPosCol();
    return map[row][col] == 'C'; // returns as true
 }
 
void Map::tryLuck(Trainer *playerptr)
 {
    srand(time(nullptr));
    int value = rand() % 2; // 50% chance
    
    if(value == 0)
    {
        int row = playerptr->getTrainerPosRow();
        int col = playerptr->getTrainerPosCol();
        for(int i = 0; i < wildPkmn.size(); i++) // checking for each wild pokemon
        {
            if(row-7 <= wildPkmn[i].getPosRow() && row+7 >= wildPkmn[i].getPosRow() && col-7 <= wildPkmn[i].getPosCol() && col+7 >= wildPkmn[i].getPosCol())
            {
               cout << "A wild " << wildPkmn[i].getName() << " appeared and joined your team!" << endl;
               playerptr->addPartyPkmn(wildPkmn[i]); // adds the wild pokemon to the player's party or pokedex
               wildPkmn.erase(wildPkmn.begin()+i); // takes wild pokemon off the map
               return;
            }
        }
    }
    cout << "No luck, sorry!" << endl;
    cout << endl;
 }
 
void Map::randEventSpawn(Trainer *playerptr)
{
    srand(time(nullptr));
    int value = rand() % 20;
    for(int i = 0; i < wildPkmn.size(); i++)
    {
        if(value == i)
        {
            cout << "a wild " << wildPkmn[i].getName() << " appeared!" << endl;
            cout << "Would you like to:" << endl;
            cout << "1. Catch it" << endl;
            cout << "2. Release it" << endl;
            string choice;
            getline(cin,choice);
            switch(choice[0])
            {
                case '1':
                {
                    cout << "Great! " << wildPkmn[i].getName() << " joined your team!" << endl;
                    playerptr->addPartyPkmn(wildPkmn[i]);
                    wildPkmn.erase(wildPkmn.begin()+i);
                    playerptr->setNumPokeballs(playerptr->getNumPokeballs()-1);
                    break;
                }
                case '2':
                {
                    cout << "You watch " << wildPkmn[i].getName() << " vanish into the tall grass." << endl;
                    cout << endl;
                    break;
                }
                default:
                {
                    cout << "Please enter a valid option!" << endl;
                    break;
                }
            }
        }
    }
}
 
bool Map::getwildPkmnEncountered()
{
    return wildPkmnEncountered;
}



void Map::setWildPkmnEncountered(bool flag)
{
    wildPkmnEncountered = flag;
}

void Map::teleportPokeCenter(Trainer *playerptr)
{
    
}

void Map::erasePokemon(int index)
{
    wildPkmn.erase(wildPkmn.begin()+index);
}


void Map::teleportPokemon(Pokemon poke)
{
    srand(time(nullptr));
    
    while(true) // keeps going infinitely
    {
        int row = rand() % 25; // 25 rows max
        int col = rand() % 16; // 16 columns max
        
        if(map[row][col] == 'p')
        {
            poke.setPosRow(row);
            poke.setPosCol(col);
        }
        break;
    }
    wildPkmn.push_back(poke);
}

