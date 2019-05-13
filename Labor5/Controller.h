#pragma once
#include <iostream>
#include "Repository.h"
#include "Domain.h"
#include <string>
#include <Windows.h>
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
	void print_movies(int person,string clien_choice);//0-admin,1-client
	void show_trailer(Film film);
	bool add_film_watchlist(Film film);
	bool remove_film_watchlist(Film film);
	void inc_like(Film film);
	void print_watchlist();

	~Controller();
};

