#pragma once
#include <string>
#include <stack>
using namespace std;
class Customer
{
private:
	int id;
	string phone_number;
	string name;
	string email;
	string address;
public:
	Customer();
	void set_data_customer(int id,string phone_number, string name, string email, string address);
	



};
