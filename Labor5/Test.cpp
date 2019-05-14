#include "Ui.h"
#include "Domain.h"
#include "Repository.h"
#include "Controller.h"
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

void TestAll()
{
	Film test("John", "Action", 2019, 23, "http");
	assert(test.get_title()=="John");
	assert(test.get_likes()==23);
	assert(test.get_genre()=="Action");
	assert(test.get_year()==2019);
	assert(test.get_trailer()=="http");
}

int main()
{
	TestAll();
	return 0;
}