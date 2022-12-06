using namespace std;
#include"wordle.cpp"
int main(){
	string file = "Test";
	initDisplay();
	int option = getMenuInput();
	if(option == 1){
		vector<string> words = readFile(file);
		string wordToGuess = toLowerCase(pickWordToGuess(words));
		displayGuesses();
		string guess = toLowerCase(getGuess());
		parseGuess(guess, wordToGuess);
	} else if (option == 2) {
		debugMain();

	} else {
		exit(0);
	}


}

