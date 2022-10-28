#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main()
{
	srand (time(NULL));
	char exit;
	int guess, randn;
	float correctCounter = 0;
	int sz = 1000;
	int guesses[sz];
	int randArray[sz];
	for(int i=0;i<sz;i++){
		randArray[i] = (rand()%5 + 1);  //Generate number between 1 to 5
	}
	cout << "This is a simulation of a test/quiz with " << sz << " questions that you guess randomly on. There are 5 answer choices(A-E) for each question." << endl;
	cout << "Strategy 1: Guess the same answer. For this we will use answer A." << endl;
	for(int i=0;i<sz;i++){
		if(randArray[i] == 1){
			correctCounter++;
		}
	}
	cout << correctCounter / (sz / 100) << "% of the answers were correct." << endl;
	cout << "Strategy 2: Guess a random letter each time." << endl;
	correctCounter = 0;
	for(int i=0;i<sz;i++){
		if(randArray[i] == (rand()%5 + 1)){
			correctCounter++;
		}
	}
	cout << correctCounter / (sz / 100) << "% of the answers were correct." << endl;
	cout << "Strategy 3: Guess a pseudo-random letter each time" << endl;
	for(int i=0;i<sz;i++){
		guess = 0;
		randn = rand()%5 + 1;
		if(guesses[i - 1] == randn && guesses[i - 2] == randn){
			guess = ((randn) % 5 + 1);
		}
		else if(guesses[i - 1] != 1 && guesses[i - 2] != 1 && guesses[i - 3] != 1 && guesses[i - 4] != 1 && guesses[i - 5] != 1 && guesses[i - 6] != 1 && guesses[i - 7] != 1){
			 guess = 1;
		}
		else if(guesses[i - 1] != 2 && guesses[i - 2] != 2 && guesses[i - 3] != 2 && guesses[i - 4] != 2 && guesses[i - 5] != 2 && guesses[i - 6] != 2 && guesses[i - 7] != 2){
			 guess = 2;
		}
		else if(guesses[i - 1] != 3 && guesses[i - 2] != 3 && guesses[i - 3] != 3 && guesses[i - 4] != 3 && guesses[i - 5] != 3 && guesses[i - 6] != 3 && guesses[i - 7] != 3){
			 guess = 3;
		}
		else if(guesses[i - 1] != 4 && guesses[i - 2] != 4 && guesses[i - 3] != 4 && guesses[i - 4] != 4 && guesses[i - 5] != 4 && guesses[i - 6] != 4 && guesses[i - 7] != 4){
			 guess = 4;
		}
		else if(guesses[i - 1] != 5 && guesses[i - 2] != 5 && guesses[i - 3] != 5 && guesses[i - 4] != 5 && guesses[i - 5] != 5 && guesses[i - 6] != 5 && guesses[i - 7] != 5){
			 guess = 5;
		}
		else{
			guess = randn;
		}
		guesses[i] = guess;
	}
	correctCounter = 0;
	for(int i=0;i<sz;i++){
		if(randArray[i] == guesses[i]){
			correctCounter++;
		}
	}
	cout << correctCounter / (sz / 100) << "% of the answers were correct." << endl;
	cout << "Strategy 4: Guess in an alternating pattern(A,B,C,etc.)." << endl;
	correctCounter = 0;
	for(int i=0;i<sz;i++){
		if(randArray[i] == ((i % 5) + 1)){
			correctCounter++;
		}
	}
	cout << correctCounter / (sz / 100) << "% of the answers were correct." << endl;
	while(1){
		int usleep(5000);
		cout << "type 'exit' to exit: ";
		cout.flush();
		cin >> exit;
		cout << "\r";
		if(exit == (char)'exit'){
			cout << "                     \r";
			return 0;
		}
	}
	getch();
	return 0;
}