#include <iostream>
#include <list>
#include <cstring>
using namespace std;
#pragma once


class HashTable
{
private:
	static const int nbofgroups = 20;
	list<pair<int, string>>table[nbofgroups];

public:
	bool isempty()const;
	int hashfunc(int);
	void insert(int,string);
	void remove(int);
	string lookfor(int);
	void printt();

};

