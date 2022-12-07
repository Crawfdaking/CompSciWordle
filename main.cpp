using namespace std;
#include"wordle.cpp"
int main(){
	string file = "wordlist";
	string guessesWithSymbols[5];
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
		}
	} else if (option == 2) {
		debugMain();

	} else {
		exit(0);
	}


}

