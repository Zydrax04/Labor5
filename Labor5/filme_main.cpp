#include <iostream>
#include "Ui.h"
#include "Repository.h"
#include "Controller.h"
using namespace std;

Repository add_filme() {
	Repository repo;
	Film film1("Slender Man", "Horror", 2018, 1234, "https://www.youtube.com/watch?v=ySy8mcceTno");
	repo.add(film1);
	Film film2("American Sniper", "Military", 2014, 2345, "https://www.imdb.com/title/tt2179136/videoplayer/vi3484134937?ref_=tt_ov_vi");
	repo.add(film2);
	return repo;
}

int main() {
	Repository repo = add_filme();
	Controller contr(repo);
	Ui ui(contr);
	ui.choose_menu();
	return 0;
}