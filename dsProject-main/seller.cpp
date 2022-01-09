
#include <iostream>
#include <string>
#include "seller.h"
#include <cstddef>
using namespace std;
seller::seller()
{
	id = NULL;
	email = "";
	name = "";
}

void seller::set_Data(int id, string name, string email)
{
	if (id > 0)
	{
		this->id = id;
		this->name = name;
		this->email = email;

	}
}
