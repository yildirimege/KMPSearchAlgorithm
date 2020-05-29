#ifndef HEADER_H
#define HEADER_H
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <ctime>
#include <ostream>

extern clock_t start;
extern clock_t end;
extern string pattern;
extern int patSize;
extern int n;
extern int position;
extern int lengLPS;
extern string q[6];
extern string h;
extern int v;
extern string answers[6];
extern int dum;
extern string underscores;
extern string dummy;

void computeLPS(string& pattern, int* lps);

void KMPsearch(string &text, string &pattern);

void underscorePos(string inputText);

void printAnswer(int pos, char text[]);

string findAndReplaceAll(string & data, string toSearch, string replaceStr);
#endif