#include <iostream>
#include <cstring>

using namespace std;

char guessing(char word[10], int word_len, char tempword[10]) {

    cout << "\ninput a charcater: ";
    char guessed;
    cin >> guessed;

    char upper = toupper(guessed);
    char lower = tolower(guessed);
    
    bool correct = false;

    for (int x = 0; x <= word_len; x++) {
        if (word[x] == lower || word[x] == upper){
            tempword[x] = word[x];
            correct = true;
        }
    }

    for (int y = 0; y < word_len; y++){
        if(tempword[y] != 0) {
            cout << tempword[y];
        } else {
            cout << "_ ";
        }
    }
        cout << '\n';

    if (correct == true){
        return tempword[10];
    } 

    return -1;
}

void theman(int no_mistakes){
    switch (no_mistakes){
    case 1:
    cout << "    +---+\n";
    cout << "    |   |\n";
    cout << "    O   |\n";
    cout << "        |\n";
    cout << "        |\n";
    cout << "        |\n";
    cout << "=========\n";
        break;
    case 2:
    cout << "    +---+\n";
    cout << "    |   |\n";
    cout << "    O   |\n";
    cout << "    |   |\n";
    cout << "        |\n";
    cout << "        |\n";
    cout << "=========\n";
        break;
    case 3:
    cout << "    +---+\n";
    cout << "    |   |\n";
    cout << "    O   |\n";
    cout << "   /|   |\n";
    cout << "        |\n";
    cout << "        |\n";
    cout << "=========\n";
        break;
    case 4:
    cout << "    +---+\n";
    cout << "    |   |\n";
    cout << "    O   |\n";
    cout << "   /|>  |\n";
    cout << "        |\n";
    cout << "        |\n";
    cout << "=========\n";
        break;
    case 5: 
    cout << "    +---+\n";
    cout << "    |   |\n";
    cout << "    O   |\n";
    cout << "   /|\\  |\n";
    cout << "   / \\  |\n";
    cout << "        |\n";
    cout << "=========\n";
        break;
    default:
    cout << "    +---+\n";
    cout << "    |   |\n";
    cout << "        |\n";
    cout << "        |\n";
    cout << "        |\n";
    cout << "        |\n";
    cout << "=========\n";
       break;
    }
}

int main(){

    char word[10] = {"Cartolina"};//the word
    int word_len =  strlen(word); // the length 
    char tempword[10];

    int no_mistakes = 0;
    bool gameover = false;

    cout << "GUESS THE WORD\n";

    for (int z = 0; z < word_len; z++){
            cout << "_ ";
    }

    do {
        
        if(guessing(word, word_len, tempword) == -1){
            no_mistakes++;
            cout << "\nThe letter you entered is not on the word\n";
            cout << "\nno of mistakes[" << no_mistakes << "/5]\n";
        }
            theman(no_mistakes);

        if (no_mistakes == 5){
            cout << "\nYOU ARE NOT THE SAVIOR\n";
            gameover = true;
        }

        if (strcmp(tempword, word) == 0){
            cout << "\nYOU SAVED THE MAN LESGO\n";
            gameover = true;
        } 

    } while(!gameover);
   
    return 0;
}