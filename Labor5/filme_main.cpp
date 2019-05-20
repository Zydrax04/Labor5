#include <iostream>
#include "Ui.h"
#include "Repository.h"
#include "Controller.h"
#include "Test.h"
using namespace std;

Repository add_filme() {
	Repository repo;
	Film film1("Slender Man", "Horror", 2018, 1234, "https://www.youtube.com/watch?v=ySy8mcceTno");
	repo.add(film1);
	Film film2("American Sniper", "Military", 2014, 2345, "https://www.youtube.com/watch?v=99k3u9ay1gs");
	repo.add(film2);
	Film film3("ShutterIsland", "Psychological", 2009, 7423, "https://www.youtube.com/watch?v=5iaYLCiq5RM");
	repo.add(film3);
	Film film4("22 Jump Street", "Comedy", 2014, 7343, "https://www.youtube.com/watch?v=v9S_dYuq0vE");
	repo.add(film4);
	return repo;
}

int main() {
	Test test;
	test.testAll();

	Repository repo = add_filme();
	Controller contr(repo);
	Ui ui(contr);
	ui.choose_menu();
	return 0;
}