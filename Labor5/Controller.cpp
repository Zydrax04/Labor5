#include "Controller.h"
#include <iostream>
#include "Repository.h"
#include "Domain.h"
Controller::Controller(Repository repo)
{
	this->repo = repo;
}

Controller::Controller()
{
}

bool Controller::add_film(Film film) {
	if (this->repo.find_film(film) == -1)
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

void Controller::print_movies() {
	vector <Film> all_movies = this->repo.get_movies();
	string answer;
	string choice;
	Film film;
	for (unsigned int i = 0; i < all_movies.size(); i++) {
		film = all_movies[i];
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
		cout << "Did you enjoy the trailer,would you like to add this movie to your watchlist?(y/n)"
			cin >> choice;
		if (choice == "y")
		{
			this->contr.add_film_watchlist(this->contr.w)
		}
	}
}

void Controller::print_movies_genre(string str) {
	vector <Film> all_movies = this->repo.get_movies();
	int count = 0;
	string choice;
	for (int i = 0; i < all_movies.size(); i++)
	{
		if (all_movies[i].get_genre() == str) {
			cout << "Title: " << all_movies[i].get_title() << endl;
			cout << "Year: " << all_movies[i].get_year() << endl;
			cout << "Likes: " << all_movies[i].get_likes() << endl;
			cout << "Trailer: " << all_movies[i].get_trailer() << endl;
			cout << "Would you like to watch the trailer? y/n: ";
			cin >> answer;
			if (answer == "y" || answer == "Y")
				this->show_trailer(all_movies[i]);
			cout << "----------------------------------------------" << endl;
			count += 1;
			cout << "Did you enjoy the trailer,would you like to add this movie to your watchlist?(y/n)"
				cin >> choice;
			if (choice == "y")
			{
				this->contr.add_film_watchlist(all_movies[i])
			}
		}
	}
	if (count != 0)
	{
		cout << "There is no Film with such genre" << endl;
	}
}

bool Controller::add_film_watchlist(Film film) {
	if (this->repo.find_film_watchlist(film) == -1)
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

Controller::~Controller()
{
}
