/* Forward Declarations below this multiline comment:
 * Allows for cyclical dependancies (This file and wordle.cpp) without
 * causing recursion at the complier/linker level.
 * !!Please copy any new function definitions from wordle.cpp to this file as well!!
 */
void initDisplay();
bool isValidInput(string);
vector<string> readFile(string);
void displayGuesses();
string pickWordToGuess(vector<string>);
string getGuess();
void parseGuess(string, string);
string toLowerCase(string);
int getMenuInput();
void debugMain();
bool testToLowerCase();
bool testIsValidInput();
bool testParseGuess();
void debugMain(){
	cout << "Testing toLowerCase function:" << endl;
	if(testToLowerCase()){
		cout << "All toLowerCase tests PASSED" << endl;
	}
	cout << "Testing isValidInput function:" << endl;
	if(testIsValidInput()){
		cout << "All isVaildInput tests PASSED" << endl;
	}
	testParseGuess();
}

bool testToLowerCase(){
	string test1 = "Hello";
	string test2 = "TRUCK";
	string test3 = "pants";
	int testsPassed = 0;
	int totalTests = 3;
	if(toLowerCase(test1) == "hello"){
		cout << "Test 1: PASSED" << endl;
		testsPassed++;
	}
	if(toLowerCase(test2) == "truck"){
		cout << "Test 2: PASSED" << endl;
		testsPassed++;
	}
	if(toLowerCase(test3) == "pants"){
		cout << "Test 3: PASSED" << endl;
		testsPassed++;
	}
	return testsPassed == totalTests;
}

bool testIsValidInput(){
	string test1 = "hello world";
	string test2 = "helloworld";
	string test3 = "He$$owor$d";
	string test4 = "pants";
	string test5 = "truck";
	int testsPassed = 0;
	int totalTests = 5;
	if(isValidInput(test1) == false){
		cout << "Test 1: PASSED" << endl;
		testsPassed++;
	}
	if(isValidInput(test2) == false){
		cout << "Test 2: PASSED" << endl;
		testsPassed++;
	}
	if(isValidInput(test3) == false){
		cout << "Test 3: PASSED" << endl;
		testsPassed++;
	}
	if(isValidInput(test4)){
		cout << "Test 4: PASSED" << endl;
		testsPassed++;
	}
	if(isValidInput(test5)){
		cout << "Test 5: PASSED" << endl;
		testsPassed++;
	}
	return testsPassed == totalTests;

}

bool testParseGuess(){
	vector<string> words = readFile("Test");
	string word = pickWordToGuess(words);
	return false;
}
