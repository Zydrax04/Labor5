#pragma once
#include <iostream>
#include <vector>
#include "Domain.h"

using namespace std;

class Repository
{
private:
	vector <Film> movies;
public:
	Repository();

	//add new movie to the list
	void add(Film new_film);

	//remove movie from the list
	void remove(Film film);

	//getter
	vector <Film> get_movies();

	//modifies a film from the list
	void modify(Film old_film, Film new_film);

	//find film from the list
	//returns index of the film in the list or -1 if not found
	int find_film(Film film);

	~Repository();
};

