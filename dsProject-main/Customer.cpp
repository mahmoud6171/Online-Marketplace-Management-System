#include "Customer.h"

Customer::Customer()
{
	id = NULL;
	phone_number="";
	name = "";
	email = "";
	address = "";
}

void Customer::set_data_customer(int id, string phone_num, string name, string email, string address)
{
	this->id = id;
	this->phone_number = phone_num;
	this->name = name;
	this->email = email;
	this->address = address;
}
