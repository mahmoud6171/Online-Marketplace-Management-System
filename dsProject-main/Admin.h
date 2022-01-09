#pragma once
#include"Product.h"
class Admin
{

public:
	Product product;
	bool checkProductAtrribute(int id, float price, int seller_id, int Quantity);	
	
	void AdminRemove(Product& product);

};

