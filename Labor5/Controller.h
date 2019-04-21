#pragma once
#include <iostream>
#include "Repository.h"
#include "Domain.h"
using namespace std;

class Controller
{
private:
	Repository repo;
public:
	Controller(Repository repo);
	Controller();

	bool add_film(Film film);
	bool remove_film(Film film);
	bool modify_film(Film old_film, Film new_film);
	void print_movies();

	~Controller();
};

