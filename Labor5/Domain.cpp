#include "Domain.h"

Film::Film() {
	this->title = "";
	this->genre = "";
	this->year = 0;
	this->likes = 0;
	this->trailer = "";
}

Film::Film(string title, string genre, int year, int likes, string trailer) {
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

Film::~Film() {

}