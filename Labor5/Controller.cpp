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

void Controller::print_movies() {
	vector <Film> all_movies = this->repo.get_movies();
	string answer;
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
	}
}

Controller::~Controller()
{
}
