#include "Ui.h"
#include <iostream>
#include "Controller.h"
#include "Domain.h"
Ui::Ui(Controller contr)
{
	this->contr = contr;
}

Ui::Ui()
{
}

Film Ui::read_film_data() {
	string title;
	string genre;
	int year;
	int likes;
	string trailer;
	cout << "Title: ";
	cin >> title;
	cout << endl;
	cout << "Genre: ";
	cin >> genre;
	cout << endl;
	cout << "Year: ";
	cin >> year;
	cout << endl;
	cout << "Likes: ";
	cin >> likes;
	cout << endl;
	cout << "Trailer: ";
	cin >> trailer;
	cout << endl;
	Film film(title, genre, year, likes, trailer);
	return film;
}

void Ui::add() {
	Film film = this->read_film_data();
	this->contr.add_film(film);
}

void Ui::remove() {
	Film film = this->read_film_data();
	this->contr.remove_film(film);
}

void Ui::modify() {
	cout << "Old film: " << endl;
	Film old_film = this->read_film_data();
	cout << "New film: " << endl;
	Film new_film = this->read_film_data();
	this->contr.modify_film(old_film, new_film);
}

void Ui::see_all_movies() {
	string a;
	this->contr.print_movies(0,a);
}

void Ui::print_menu() {
	cout << "Welcome to Admin Menu" << endl;
	cout << "To add a movie press: 1" << endl;
	cout << "To remove a movie press: 2" << endl;
	cout << "To modify a movie press: 3" << endl;
	cout << "To see all movies press: 4" << endl;
	cout << "To exit press: q" << endl;
}

void Ui::admin_menu() {
	string option;
	while (option != "q") {
		this->print_menu();
		cin >> option;
		if (option == "1")
			this->add();
		if (option == "2")
			this->remove();
		if (option == "3")
			this->modify();
		if (option == "4")
			this->see_all_movies();
	}
}

void Ui::print_client_menu() {
	cout << "Welcome to Client Menu" << endl;
	cout << "To see the trailer of a movie of a certain genre press:1" << endl;
	cout << "To delete a movie from the watchlist press:2" << endl;
	cout << "To see your watchlist press:3" << endl;
}

void Ui::client_menu() {
	string option;
	while (option != "q") {
		this->print_client_menu();
		cin >> option;
		if (option == "1")
			this->client_watch();
		if (option == "2")
			this->delete_client_movie();
		if (option == "3")
			this->watch_list();
	}
}

void Ui::choose_menu() {
	cout << "Welcome to the Movie App" << endl;
	cout << "For Admin user press: 1" << endl;
	cout << "For normal user press: 2" << endl;
	string choice;
	while (true) {
		cin >> choice;
		if (choice == "1" || choice == "2")
			break;
	}
	if (choice == "1")
		this->admin_menu();
	else
		this->client_menu();
}

void Ui::client_watch()
{
	string genre;
	cin >> genre;
	this->contr.print_movies(1, genre);
}

void Ui::watch_list()
{
	this->contr.print_watchlist();
}
void Ui::delete_client_movie()
{
	string ans;
	Film deleted_film = this->read_film_data();
	if (this->contr.remove_film_watchlist(deleted_film) == true)
	{
		cout << "Did you like the movie?";
		if (ans == "y")
			this->contr.inc_like(deleted_film);
		else cout << "No such movie" << endl;
	}
}

Ui::~Ui()
{
}
