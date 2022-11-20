#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void initDisplay();
vector<string> readFile(string);
void displayGuesses();
string pickWordToGuess(vector<string>);
string getGuess();
void parseGuess(string, string);
int main(){
	string file = "Test";
	initDisplay();
	vector<string> words = readFile(file);
	string wordToGuess = pickWordToGuess(words);
	displayGuesses();
	string guess = getGuess();
	cout << guess;
	parseGuess(guess, wordToGuess);

}


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

void initDisplay(){
	int option = 0;
	cout << "Welcome to Worldle. To begin the game press 1 or to exit press 2: ";
	cin >> option;
	while(option < 1 || option > 2){
		cout << "Sorry that is not a valid option. Please press 1 to start game or 2 to exit: ";
		cin >> option;
	}
	if(option == 2){
		exit(0);
	}
}


void displayGuesses(){
	int size = 5;
	for(int i = 0 ; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << setw(3) << "h^";
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

void parseGuess(string guess, string wordToGuess){

}
