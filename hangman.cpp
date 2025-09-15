#include <iostream>
#include <cstring>

using namespace std;

char guessing(char word[30], int word_len, char tempword[30]) {

    cout << "\ninput a charcater: ";
    char guessed;
    cin >> guessed;

    char upper = toupper(guessed);
    char lower = tolower(guessed);
    
    bool correct = false;

    //checking if the letter is on the word 
    for (int x = 0; x <= word_len; x++) {
        if (word[x] == lower || word[x] == upper){
            if (tempword[x] == word[x]){
                cout << "The letter is already Entered\n";
                return tempword[10];    
            }
            tempword[x] = word[x];
            correct = true;
        }
    }
    //showing the guessed letters and blank if unguessed
    for (int y = 0; y < word_len; y++){
        if(tempword[y] != 0) {
            cout << tempword[y];
        } else {
            cout << "_ ";
        }
    }
    cout << '\n';

    //retuns -1 if guessed wrong and retuns tempword if guessed right 
    
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

    char word[30];

    cout << "ENTER THE WORD TO BE GUESSED: ";
    cin >> word;


    int word_len =  strlen(word); // the length 
    char tempword[30];

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

        //comparing the two words if they are identical
        if (strcmp(tempword, word) == 0){
            cout << "\nYOU SAVED THE MAN LESGO\n";
            gameover = true;
        } 

    } while(!gameover);
   
    return 0;
}