#include "header.h"
using namespace std;

clock_t start;
clock_t end;
string pattern;
int patSize = pattern.size();
int n = patSize;
int position;
int lengLPS;
string q[6] = { "","","","","","" };//For storing unique keys
string h = "";
int v = 0;
string answers[6];//For storing the answers
int dum = 0;
string underscores = "___";
string dummy;


void computeLPS(string& pattern, int* lps) {

	int len = 0;  // lenght of the previous longest prefix suffix

	lps[0] = 0; // lps[0] is always 0

	int i = 1;



	// the loop calculates lps[i] for i = 1 to M-1

	while (i < pattern.length()) {

		if (pattern[i] == pattern[len]) {

			++len;

			lps[i] = len;

			++i;

		}

		else {

			if (len != 0) {

				len = lps[len - 1];

			}

			else {

				lps[i] = 0;
				++i;

			}

		}

	}

}

void KMPsearch(string &text, string &pattern) {
	int i = 1; int j = 0;
	patSize = pattern.size();
	int lps[50];
	computeLPS(pattern, lps);

	if (sizeof(text) == 0 || pattern.size() == 0) { //Text or pattern can't be empty strings
		cout << "Text or pattern can't be empty.";
	}

	while (i < 81902) {
		if (pattern[j] == text[i]) {
			i++;
			j++;
		}

		if (j == 15) {
			//cout << "Found pattern at position: " << i - j << endl;
			position = i - j;
			j = lps[j - 1];
		}

		else if (pattern[j] != text[i]) {

			if (j != 0) j = lps[j - 1];
			else i += 1;
		}
	}
}

void underscorePos(string inputText) { //searches for underscore in text

	for (int k = 0; k <= inputText.size(); k++) {
		if (inputText[k] == '_') {
			//cout << "Underscore is found at position: " << k << endl;
			int y = k - 16;
			k += 10;

			for (int i = 0; i < 15; i++) {
				h += inputText[y];
				y++;
			}
			q[v].append(h);
			//cout << "*****" << q[v] << "*****" << endl;
			h = ""; v++;

		}

	}

	
}

void printAnswer(int pos, char text[]) {
	cout << "Answer: ";
	for (int i = pos + 16; i < 9999999; i++) {
		if (text[i + 1] == ' ' || text[i + 1] == '.') {
			cout << text[i];
			answers[dum] += text[i];
			dum++;
			break;
		}
		else {
			cout << text[i];
			answers[dum] += text[i];
		}
	}
}


string findAndReplaceAll(string & data, string toSearch, string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
	// Repeat till end is reached

	data.replace(pos, toSearch.size(), replaceStr);
	

	return data;
}
