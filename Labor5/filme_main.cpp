#include <iostream>
#include "Ui.h"
#include "Repository.h"
#include "Controller.h"
using namespace std;

int main() {
	Repository repo;
	Controller contr(repo);
	Ui ui(contr);
	ui.choose_menu();
	return 0;
}