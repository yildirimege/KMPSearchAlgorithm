
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <ctime>
#include <ostream>
#include "header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	clock_t startTime = clock();
	int l = 0;
	int x = 0;
	const int arraysize = 81902;
	char inputText[arraysize];
	char sampleText[500];
	ifstream input("the_truman_show_script.txt");
	ifstream sample("statements.txt");
	ifstream count("statements.txt");
	string line;
	int numLines=0;
	bool thereIsMatch= false;


	while (getline(count, line)) {

		numLines++;   //Counting number of lines in statements.txt



	}
	count.close();

	

	if (input.is_open()) { //Inputting truman show script txt
		while (!input.eof()) {

			input.get(inputText[l]);
			l++;
		}

	}
	input.close();
	string inputText_Str(inputText); //Converting inputText to string

	if (sample.is_open()) { //Inputting  statements txt
		while (!sample.eof()) {

			sample.get(sampleText[x]); 
			x++;
		}
	}

	string sampleText_Str(sampleText);

	underscorePos(sampleText); //Finding positions of underscores in statements txt.

	for (int i = 0; i < numLines; i++) {
		KMPsearch(inputText_Str, q[i]);
		printAnswer(position, inputText);
		cout << endl;
	}

	cout << "---------------------------------------------------" << endl;



	for (int i = 0; i < sizeof(sampleText)-124; i++) {
		dummy += sampleText[i];
		cout << sampleText[i];
	}
	cout << endl;

	for (int i=0; i < 6; i++) {
		string replace = answers[i];
		findAndReplaceAll(dummy, underscores, replace);//Replacing underscores with answers
	}

	cout << "--------------------------------------------------- "<<endl;
	cout << dummy; //String without underscores
	cout << endl;
	clock_t endTime = clock();

	//cout << endl << "Number of lines is in statement.txt is: " << numLines << endl;



	                                           
	clock_t clockTicksTaken = endTime - startTime;                        
	double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;      
	cout <<endl << "Spent time: [" << timeInSeconds <<"]"<<" seconds"<< endl;
}