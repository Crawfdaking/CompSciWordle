#using namespace std;
int LongerStreak = 0, CurrentStreak = 0;
	if(answer == result)
	    CurrentStreak++;
	else
	    CurrentStreak = 0;
	if(CurrentStreak > LongerStreak)
	    LongerStreak = CurrentStreak;
