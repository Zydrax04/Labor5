#pragma once
#include <iostream>
#include <string>
using namespace std;

class Film {
private:
	string title;
	string genre;
	int year;
	int likes;
	string trailer;
public:
	Film();
	Film(string title, string genre, int year, int likes, string trailer);
	~Film();
};

