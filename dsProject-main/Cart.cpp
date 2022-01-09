#include "Cart.h"
#include"Product.h"
#include<iostream>
using namespace std;
bool Cart::check_id(int id,int sold, Product product)
{
	
	if (product.search(id,sold) == true)
	{
		product_id.push_back(make_pair(id,sold));
		return true;
	}
	return false;
	
}
void Cart::calculate(Product product)
{
	
	float total_price = 0;
	for (int i = 0; i < product_id.size(); i++)
	{
		
			string name = product.getAllIteams(product_id[i].first).Product_Name;
			float price = product.getAllIteams(product_id[i].first).Product_Price* product_id[i].second;
			total_price += price;
			cout << product_id[i].first << "  " << name << "   " << price << "\n";
		
	}
	while (true)
	{
		cout << "Total Price is " << total_price << "\n";
		cout << "If You want to\n";
		cout << "Confirm  Enter 1" << "\n";
		cout << "Remove Element Enter 2" << "\n";
		int answer;
		cin >> answer;
		if (answer == 1)
		{
			cout << "Done!..........\n";
			for (int i = 0; i < product_id.size(); i++)
			{
				product.changeQuantity(product_id[i].first, product_id[i].second);
			}
			product_id.clear();
			break;
		}
		else 
		{
			int Id,sold;
			cout << "Enter Id\n";
			cin >> Id;
			for (int i = 0; i < product_id.size(); i++)
			{
				if (Id == product_id[i].first)
				{
					sold = product_id[i].second;
					product_id.erase(product_id.begin() + i);
					break;
				}
			}
			total_price -= product.getAllIteams(Id).Product_Price*sold;

		}
	}
	
	
}