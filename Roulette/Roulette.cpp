/*Roulette game
Remake of project from CIS 1400
This time in C++
By Tom Nuzzarello
Tjnuzza on GitHub*/

#include <iostream>
#include <cstdlib>	//	To include support for random numbers
#include <ctime>	//	For the time function
#include <Windows.h>//	to include support for sleep, which is not portable from Windows to Mac
using namespace std;

//	Function prototypes
int menu(int);
int getBet(int);
int getOdds(int);
int getNum();
int spinWheel();
bool results(int, int, int);
int winLose(bool, int, int, int);

void main()
{
	int cash = 100, betChoice = 0, betNum = 0, betMoney = 0, betOdds = 0, ball = 0;
	//	betNum must be initialized because it is always sent to results()
	bool winner = true;
	srand(time(NULL));
	//	This seeds the rand() function using a number taken from system time
	//	It only needs to be seeded once, at the start of the program, or we will see the same numbers come up as before

	cout << "Welcome to Roulette" << endl;

	while (cash > 0 && betChoice != 7)
	{
		betChoice = menu(cash);
		if (betChoice != 7)
		{
			if (betChoice == 6)
				betNum = getNum();	//	This variable is only important if we bet on one number

			betMoney = getBet(cash);
			betOdds = getOdds(betChoice);
			ball = spinWheel();
			winner = results(betChoice, betNum, ball);
			cash = winLose(winner, cash, betMoney, betOdds);

			system("PAUSE");
			system("CLS");
		}
	}
	cout << "You have $" << cash << endl << "Goodbye.\n";
	system("PAUSE");
}
//	First we need to know what the bet is
//	Make sure we still have money to bet, and that the user selects a valid option
int menu(int cash)
{
	int menuChoice = 0;

	cout << "You have $" << cash << endl
		<< "1 for red/odd (pays 1:1)\n"//	I can print the whole menu with one cout object
		<< "2 for black/even (pays 1:1)\n"
		<< "3 for 1-12 (pays 2:1)\n"
		<< "4 for 13-24 (pays 2:1)\n"
		<< "5 for 25-36 (pays 2:1)\n"
		<< "6 for one number (pays 35:1)\n"
		<< "7 to quit\n\n";

	while (menuChoice < 1 || menuChoice > 7)
	{
		cout << "What is your choice? ";
		cin >> menuChoice;
		if (cin.fail())
		{
			cout << "That's not a number." << endl;
			// resets the value of menuChoice
			cin.clear();
			// Ignores input, preventing the infinite loop glitch
			cin.ignore();
		}
		else if (menuChoice < 1 || menuChoice > 7)
		{
			cout << "That's not a choice." << endl;
		}
	}

	return menuChoice;
}

// Here the user decides how much money they want to bet
int getBet(int cash)
{
	int bet = 0;
	do
	{
		cout << "How much would you like to bet? ";
		cin >> bet;
		if (cin.fail())
		{
			cout << "That's not a number." << endl;
			cin.clear();
			cin.ignore();
		}

		if (bet <= 0)
		{
			cout << "You cannot bet that amount.\n";
		}
		if (bet > cash)
		{
			cout << "You don't have that much money.\n";
		}
	} while (bet > cash || bet <= 0);

	return bet;
}

//	If the user decides to bet on one number, the select it here
int getNum()
{
	int bet = -1;

	do
	{
		cout << "What number will you bet on (0-36)? ";
		cin >> bet;
		if (cin.fail())
		{
			cout << "That's not a number." << endl;
			cin.clear();
			cin.ignore();
			//	Set a default value so the loop doesn't drop too early
			bet = -1;
		}
		else if (bet < 0 || bet > 36)
		{
			cout << "You cannot bet on that number\n";
			cin.clear();
			cin.ignore();
			bet = -1;
		}
	} while (bet < 0 || bet > 36);

	return bet;
}

//	Determine win multiplier here
int getOdds(int choice)
{
	switch (choice)
	{
	case 1:	//	You can't do something like '1 || 2', otherwise it appears it does nothing and just returns the original argument
	case 2:	//	But you can place several cases in sequence like this
		return 1;
	case 3:
	case 4:
	case 5:
		return 2;//	Break isn't necessary after a return statement
	case 6:
		return 35;
	}
	
	return 0;
}

//	A random number in range 0-36 is our result
//	Color can be inferred from the number
int spinWheel()
{
	cout << "Let's spin...";

	Sleep(3000);	//	Sleep needs to be capitalised
	//	This function takes milliseconds, so 3000 makes it wait for 3 seconds

	int roll = 0;
	roll = rand() % 37;	//	This allows a range of 0-36. It is a Euro-style roulette with no 00

	cout << "You rolled " << roll << ", ";

	if (roll == 0)
		cout << "green.\n";
	else if (roll % 2 == 1)
		cout << "red.\n";
	else
		cout << "black.\n";

	return roll;
}

//	Here the program decides if the user won or lost
bool results(int betChoice, int betNum, int ball)
{
	switch (betChoice)
	{
	case 1:
		return (ball % 2 == 1);
	case 2:
		return (ball % 2 == 0);
	case 3:
		return (ball >= 1 && ball <= 12);
	case 4:
		return (ball >= 13 && ball <= 24);
	case 5:
		return (ball >= 25 && ball <= 36);
	case 6:
		return (ball == betNum);
	}
	return false;
}

//	Adds or subtracts money accordingly
int winLose(bool win, int cash, int betMoney, int betOdds)
{
	if (win)
	{
		cout << "You win!\n";
		cash += betMoney * betOdds;
	}
	else {
		cout << "You lose...\n";
		cash -= betMoney;
	}
	return cash;
}