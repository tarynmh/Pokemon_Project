#ifndef SPLIT
#define SPLIT

#include <string>

using namespace std;

int split(string words, char del, string splits[], int len) // split helper function for readRoster
{
    int i = 0; // defines i as an integer equal to 0
    int j = 0; // defines j as an integer equal to 0
    string temp = ""; // creates a temp variable
    
    if(words == "") // check if words string is empty
    {
        return 0; // returns to the calling function
    }
    words += del;
    for(int i = 0; i < words.length(); i++)
    {
        if(words[i] != del)
        {
            temp += words[i];
        }
        else
        {
            if(words[i + 1] == del)
            {
                continue; // i++
            }
            if(temp != "")
            {
                splits[j] = temp;
                j++;
                temp = "";
            }
        }
    }
    return j; // returns to the calling function
}

#endif