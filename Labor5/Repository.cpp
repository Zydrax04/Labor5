#include "Repository.h"



Repository::Repository()
{
}

int Repository::find_film(Film film) {
	//function searches a film in the movies list
	//parameters: the film to search for
	//return: the index of the film in the list or -1 if not found
	unsigned int i;
	for (i = 0; i < this->movies.size(); i++) {
		if (this->movies[i].get_title() == film.get_title())
			if (this->movies[i].get_year() == film.get_year())
				return i;
	}
	return -1;
}

void Repository::add(Film new_film) {
	//function adds a new film to the movies list
	//parameters: the new film
	//return: void
	this->movies.push_back(new_film);
}

void Repository::remove(Film film) {
	//function erases one film from the movies list
	//parameters: the film to remove
	//return: void
	int index = this->find_film(film);
	this->movies.erase(this->movies.begin() + index);
}

void Repository::modify(Film old_film, Film new_film) {
	//function modifies an old film with a new one
	//parameters: old film and the new film
	//return:: void
	int i = this->find_film(old_film);
	this->movies[i].set_title(new_film.get_title());
	this->movies[i].set_genre(new_film.get_genre());
	this->movies[i].set_year(new_film.get_year());
	this->movies[i].set_likes(new_film.get_likes());
	this->movies[i].set_trailer(new_film.get_trailer());
}

Repository::~Repository()
{
}
