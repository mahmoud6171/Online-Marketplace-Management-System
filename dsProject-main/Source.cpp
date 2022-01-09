#include<iostream>
#include"Customer.h"
#include"Product.h"
#include"Cart.h"
#include"seller.h"
#include"Admin.h"
using namespace std;
int answer;
void welcome()
{
	cout << "**********************Welcome in our system****************************\n";
	cout << "1-Login As customer (Enter 1)\n";
	cout << "2-Login As seller(Enter 2)\n";
	cout << "3-Login As Admin(Enter 3)\n";
	cout << "4-Exist(Enter 4)\n";
	cin >> answer;
}
int main()
{
	
		
	Customer customer;
	Product product;
	Cart cart;
	seller seler;
	Admin admin;
	char Continue;
	welcome();
	while (answer != 4)
	{
		string name;
		cout << "Please Enter Your First Name\n";
		cin >> name;
		cout << "Enter Your Id\n";
		int id;
		cin >> id;
		string email;
		cout << "Enter Your Email (not include space)\n";
		cin >> email;
		if (answer == 1)
		{
			string addres;
			cout << "Please Enter Your addres\n";
			cin.ignore();
			getline(cin, addres);
			cout << "Enter Your Phone number\n";
			string phone_number;
			
				cin >> phone_number;
			customer.set_data_customer(id, phone_number, name, email, addres);
			int counter = 1;
			cout << "If You want to see all produts(enter 1)\n";
			cout << "If You want to see all categerious(enter 2)\n";
			int ans1;
			cin >> ans1;
			string nameCategory;
			if (ans1 == 1)
			{
				
				product.display();
			}
			else if (ans1 == 2)
			{
				
				for (auto it = product.categerious.begin(); it != product.categerious.end(); it++)
				{
					cout << counter << " " << *it << "  ";
					if (counter == 3)
						cout << "\n\n";
					counter++;

				}

				cout << "\nEnter name of category\n";
				cin >> nameCategory;


			}
			
			char ans;
			
			if (product.categerious.size() > 0)
			{

				do
				{
					if (ans1 == 2)
					{
						product.search(nameCategory);
					}
					cout << "\nDo You want to buy products ? (y/n) \n";
					cin >> ans;
					if (ans == 'n')
					{
						break;
					}
					int idOfProduct, quantity;
					cout << "Now You can add products in your cart\n";
					cout << "please enter id   of product\n";
					cin >> idOfProduct;
					cout << "please enter quantity of product\n";
					
					cin >> quantity;
					if (cart.check_id(idOfProduct, quantity, product) == false)
					{
						cout << "Information Not Valid\n";
					}
					cout << "Do you want to continue ? Enter (y or n)\n";

					cin >> ans;
				} while (ans != 'n');
			}
			if (cart.product_id.size() > 0)
			{
				cart.calculate(product);
				char ansOfRating;
				do
				{
					cout << "\n Please Rating Our Products\n";
					product.Rating();
					cout << "Do You Want to continue?(Enter y or n)\n";
					
					cin >> ansOfRating;

				} while (ansOfRating!='n');
			}

		}
		else if (answer == 2)
		{
			char c;
			seler.set_Data(id, name, email);
			product.Add_product();
			cout << "If You Want to Add more Enter y\n";
			cout << "If You Want to stop for Adding  Enter n\n";
			cin >> c;
			while (c!='n')
			{
				product.Add_product();
				cout << "If You Want to Add more Enter y\n";
				cout << "If You Want to stop for Adding  Enter n\n";
				cin >> c;
			}
		}
		else if (answer == 3&&name=="Admin"&&email=="Admin@gmail.com")
		{
			
			cout << "Enter Password\n";
			int password;
			cin >> password; 
			if (password == 123)
			{
				
				do
				{
					cout << "If You want to \n";
					cout << "1- Remove product (Enter 1)\n";
					cout << "2- updat product (Enter 2)\n";
					int ans;
					cin >> ans;
					if (ans == 1)
					{

						admin.AdminRemove(product);
						
					}
					else if (ans == 2)
					{
						admin.product.update();
					}
					cout << "IF You Want To Continue As Admin Enter y \n";
					cout << "IF You Want To Logout Enter n \n";
					cin >>Continue;
				} while (Continue!='n');
				
			}
			
		}
		welcome();
	}




}