/* Forward Declarations below this multiline comment:
 * Allows for cyclical dependancies (This file and wordle.cpp) without
 * causing recursion at the complier/linker level.
 * !!Please copy any new function definitions from wordle.cpp to this file as well!!
 */
void initDisplay();
vector<string> readFile(string);
void displayGuesses();
string pickWordToGuess(vector<string>);
string getGuess();
void parseGuess(string, string);
string toLowerCase(string);
void debugMain();
bool testToLowerCase();

void debugMain(){
	cout << "Testing toLowerCase function" << endl;
	testToLowerCase();
}

bool testToLowerCase(){
	cout << toLowerCase("Hello") << endl;
	return true;
}
