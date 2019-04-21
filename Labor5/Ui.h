#pragma once
#include <iostream>
#include "Controller.h"
#include "Domain.h"
using namespace std;

class Ui
{
private:
	Controller contr;
public:
	Ui(Controller contr);
	Ui();

	Film read_film_data();

	void add();
	void remove();
	void modify();
	void see_all_movies();
	void print_menu();

	void admin_menu();

	void choose_menu();

	~Ui();
};

