#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include"tests.cpp"
void initDisplay();
bool isValidInput(string);
vector<string> readFile(string);
void displayGuesses();
string pickWordToGuess(vector<string>);
string getGuess();
void parseGuess(string, string);
string toLowerCase(string);
int getMenuInput();

vector<string> readFile(string fileName){
	ifstream inputFile;
	vector<string> words;
	string word = "";
	inputFile.open(fileName);
	while(inputFile >> word){
		words.push_back(word);
	}
	inputFile.close();
	return words;
}

int getMenuInput(){
	int option = 0;
	cin >> option;
	while(option < 1 || option > 3){
		cout << "Sorry that is not a valid option. Please press 1 to start game, 2 to run automated tests, 3 to exit: ";
		cin >> option;
	}
	return option;
}

void initDisplay(){
	cout << "Welcome to Worldle. To begin the game press 1, press 2 to run tests, press 3 to exit: ";
}

void displayGuesses(){
	int size = 5;
	for(int i = 0 ; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << setw(3) << "_";
		}
	cout << endl;
	}

}

string pickWordToGuess(vector<string> words){
	srand(time(0));
	int randIndex = rand() % words.size();
	return words.at(randIndex);

}

string getGuess(){
	string guess = "";
	cout << "Please enter your guess: ";
	cin >> guess;
	return guess;

}

void parseGuess(const string guess, const string wordToGuess){
	const char correct = '^';		//Correct letter and placement
	const char wrongPlace = '*'; 	//Correct letter but wrong placement
	const char wrong = 'X'; 		//Letter does not exist
	const int width = 2;

	for(int i = 0; i < guess.length(); i++){
		bool correctLetterPlace = false;
		bool correctLetterWrongPlace = false;
		for(int j = 0; j < wordToGuess.length(); j++){
			if(guess[i] == wordToGuess[j] && i == j){
				correctLetterPlace = true;
			}
			else if (guess[i] == wordToGuess[j]){
				correctLetterWrongPlace = true;
			}
		}
		if(correctLetterPlace){
			cout << setw(width) << correct << guess[i];
		}
		else if(correctLetterWrongPlace){
			cout << setw(width) << wrongPlace << guess[i];
		}
		else{
			cout << setw(width) << wrong << guess[i];
		}
	}
}

string toLowerCase(string word){
	for(int i = 0; i < word.length(); i++){
		if(word[i] >= 65 && word[i] <= 90){
			word[i] = (char) ((int) word[i] + 32);
		}
	}
	return word;
}

//Makes sure word correct length and has only letters and no spaces
bool isValidInput(string guess){
	for(int i = 0; i < guess.length(); i++){
		if(guess.length() > 5 || guess[i] < 65 || guess[i] >  90 && guess[i] < 97){
			return false;
		}
	}
	return true;
}
