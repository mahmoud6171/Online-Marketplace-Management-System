#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;

class product_Node
{
public:
	product_Node();
	int Product_ID;
	double Product_Price;
	string Product_Name;
	string Product_Category;
	int Seller_Id;
	int Quantity;
	product_Node* next;
	int stars;
};
class Product
{
private:
	product_Node* head;
	product_Node* tail;
	
public:
	set<string>categerious;
	Product();
	void Add_product();
	bool search(int id, int sold);
	product_Node getAllIteams(int id);
	void display();
	void remove();
	void update();
	void changeQuantity(int id, int sold);
	void search(string category);
	void Rating();
	

};