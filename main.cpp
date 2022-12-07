using namespace std;
#include"wordle.cpp"
#include "streaktime.cpp"
int main(){
	string file = "wordlist";
	string guessesWithSymbols[5];
	time();
	initDisplay();
	int option = getMenuInput();
	if(option == 1){
		vector<string> words = readFile(file);
		string wordToGuess = toLowerCase(pickWordToGuess(words));
		displayGuesses(guessesWithSymbols);
		for(int i = 0; i < 5; i++){
			string guess = getGuess("Please enter your guess");
			while(!isValidInput(guess)){
				guess = getGuess("Your guess must be exactly 5 letter and contain no spaces or anyother character. Please re-eneter your guess");
			}
			guessesWithSymbols[i] = parseGuess(guess, wordToGuess);
			displayGuesses(guessesWithSymbols);
			if(validateGuess(guess, wordToGuess)){
				cout << "You win! It took you " << i << " attempt(s) to guess the word" << endl;
				streak();
				playagain();
				break;
			}

		}
		cout << "You lost. The word was " << wordToGuess << ". Try again tomorrow." << endl;
		playagain();
	} else if (option == 2) {
		debugMain();

	} else {
		exit(0);
	}


}

