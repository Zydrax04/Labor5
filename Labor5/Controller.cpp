#include "Controller.h"
#include <iostream>
#include "Repository.h"
#include "Domain.h"
using namespace std;
Controller::Controller(Repository repo)
{
	this->repo = repo;
}

Controller::Controller()
{
}

bool Controller::add_film(Film film) {
	if (this->repo.find_film(film) > -1)
		return false;
	this->repo.add(film);
	return true;
}

bool Controller::remove_film(Film film) {
	if (this->repo.find_film(film) == -1)
		return false;
	this->repo.remove(film);
	return true;
}

bool Controller::modify_film(Film old_film, Film new_film) {
	if (this->repo.find_film(old_film) == -1)
		return false;
	this->repo.modify(old_film, new_film);
	return true;
}

void Controller::show_trailer(Film film) {
	ShellExecute(NULL, "open", film.get_trailer().c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void Controller::print_movies(int person, string client_choice) {
	vector <Film> all_movies = this->repo.get_movies();
	string answer;
	string choice;
	Film film;
	int count = 0, i = 0;
	bool ok=false;
	if (client_choice == "")
		ok = true;
	while (i < all_movies.size()) {
		film = all_movies[i];
		if ((person == 0) || (film.get_genre() == client_choice && ok == false) || ok == true) {
			cout << "Title: " << film.get_title() << endl;
			cout << "Genre: " << film.get_genre() << endl;
			cout << "Year: " << film.get_year() << endl;
			cout << "Likes: " << film.get_likes() << endl;
			cout << "Trailer: " << film.get_trailer() << endl;
			cout << "Would you like to watch the trailer? y/n: ";
			cin >> answer;
			if (answer == "y" || answer == "Y")
				this->show_trailer(film);
			cout << "----------------------------------------------" << endl;
			if (person == 1)
			{
				count += 1;
				cout << "Did you enjoy the trailer,would you like to add this movie to your watchlist?(y/n)" << endl;
				cin >> choice;
				if (choice == "y")
					this->add_film_watchlist(film);
				cout << "Would you like too see the next Film trailer ?" << endl;
				if (choice == "y")
					i += 1;
				else break;
			}
		}
		i += 1;
	}
}

bool Controller::add_film_watchlist(Film film) {
	if (this->repo.find_film_watchlist(film) > -1)
		return false;
	this->repo.add_watchlist(film);
	return true;
}

bool Controller::remove_film_watchlist(Film film) {
	if (this->repo.find_film_watchlist(film) == -1)
		return false;
	this->repo.remove_watchlist(film);
	return true;
}

void Controller::inc_like(Film film)
{
	this->repo.inc_like(film);
}

void Controller::print_watchlist()
{	
	int count = 0;
	Film film;
	vector<Film> watchlist = this->repo.get_watchlist();
	cout << "lungimea liste e: " << watchlist.size() << endl;
	for (int i = 0; i < watchlist.size(); i++)
	{
		film = watchlist[i];
		count += 1;
		cout << count << "." << " " << film.get_title()<<" "<<film.get_year()<< endl;
	}
}



Controller::~Controller()
{
}
