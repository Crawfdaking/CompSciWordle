using namespace std;
void time(){
	 auto clock_end = std::chrono::system_clock::now();
	    std::time_t clock_end_time = std::chrono::system_clock::to_time_t(clock_end);
	    std::cout << "The current system date and time is: " << std::ctime(&clock_end_time)<< std::endl;
}
void playagain(){
	cout<<"you can play again after midnight ;)"<<endl;
	exit(0);
}

