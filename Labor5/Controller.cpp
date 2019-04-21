#include "Controller.h"

Controller::Controller(Repository repo)
{
	this->repo = repo;
}

Controller::Controller()
{
}

bool Controller::add_film(Film film) {
	return true;
}

bool Controller::remove_film(Film film) {
	return true;
}

bool Controller::modify_film(Film old_film, Film new_film) {
	return true;
}

Controller::~Controller()
{
}
