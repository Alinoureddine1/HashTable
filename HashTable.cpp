#include "HashTable.h"
#include <iostream>
#include <list>
#include <cstring>
using namespace std;


bool HashTable::isempty()const {
	int sum{};
	for (auto x : table) {
		sum += x.size();
	
	}
	if (!sum) {
		return true;
	}
	return false;



}

int HashTable::hashfunc(int key) {

	return key % nbofgroups;


}
void HashTable::insert(int key, string value) {

	int hashvalue = hashfunc(key);
	auto& cell = table[hashvalue];
	auto itr = begin(cell);
	bool keyexists = false;
	for (; itr != end(cell); itr++) {
		if (itr->first == key) {
			keyexists= true;
			itr->second = value;
			cout << "[Key exists. Value replaced]" << endl;
			break;
		}
	
	}

	if (!keyexists) {
		cell.emplace_back(key, value);
	}

}
void HashTable::remove(int key) {

	int hashvalue = hashfunc(key);

	auto& cell = table[hashvalue];
	auto itr = begin(cell);
	bool keyexists = false;
	for (; itr != end(cell); itr++) {
		if (itr->first == key) {
			keyexists = true;
			itr = cell.erase(itr);
			cout << "[Item Removed]" << endl;
			break;
		}
	
	}
	if (!keyexists) {
		cout << "[Key Not Found]" << endl;
	}


}
string  HashTable::lookfor(int key) {

	int hashvalue = hashfunc(key);
	auto& cells = table[hashvalue];
	auto itr = begin(cells);
	for (; itr != end(cells); itr++) {
		if (itr->first == key) {
			return itr->second;
		}

	
	}
	cout << "[There is no match for the Key " << key << "]"<<endl;
	return "";

}
void  HashTable::printt() {
	for (int i{}; i < nbofgroups; i++) {
		if (table[i].size() == 0) {
			continue;
		}

		auto itr = table[i].begin();
		for (; itr != table[i].end(); itr++) {
			cout << "key: " << itr->first << " Value: " << itr->second << endl;
		
		}

	
	}


}