#include "Product.h"
#include"Admin.h"
Product::Product()
{
	head = NULL;
}

void Product::Add_product()
{
	int id, seller;
	double price;
	string category, name;
	product_Node* node = new product_Node();
	product_Node* temp = head;
	Admin admin;
	cout << "\nEnter the product id: ";
	cin >> id;
	
	cout << "\n";
	cout << "Enter the product price: ";
	cin >> price;
	
	cout << "\n";
	cout << "Enter the product name: ";
	cin.ignore();
	getline(cin, name);
	
	
	cout << "\n";
	cout << "Enter the product category: ";
	cin >> category;
	
	cout << "\n";
	cout << "Enter the seller id: ";
	cin >> seller;
	int quantity;
	cout << "\nEnter Quantity: ";
	cin >> quantity;
	cout << "\n";
	if (admin.checkProductAtrribute(id, price, seller, quantity) == true)
	{
		node->Quantity = quantity;
		node->Product_Price = price;
		node->Seller_Id = seller;
		node->next = NULL;
		node->Product_ID = id;
		categerious.insert(category);
		node->Product_Category = category;
		node->Product_Name = name;
		cout << "\t\t\tThis product is inserted\n";
	}

	
	if (head == NULL)
	{
		
		head = node;
		tail = node;
	}
	else
	{
		
		tail->next = node;
		tail = node;

	}
	

}

bool Product::search(int val,int sold)
{
	product_Node* node = head;
	
	while (node != NULL)
	{
		if (node->Product_ID == val&& sold <= node->Quantity)
		{
			
			return true;		

		}
		node = node->next;
	}
	return false;
}
void Product::search(string category)
{
	product_Node* node = head;
	bool flag = false;
	cout << "\nProduct id   " << "Product name  " << "Product Price  \n\n";
	while (node != NULL)
	{
		if (node->Product_Category == category)
		{

			cout << node->Product_ID << "    " << node->Product_Name << "   " << node->Product_Price << "\n";


		}
		node = node->next;
	}
				
}

void Product::Rating()
{
	product_Node* node = head;
	int id;
	if (head == NULL) 
	{
		cout << "The List Is Empty......." << endl;
		
	}
	else 
	{
		cout << "Product ID : ";
		cin >> id;
		while (node!=NULL) 
		{
			if (id == node->Product_ID) 
			{
				cout << "The Name Of Product Is : " << node->Product_Name << endl;
				cout << "Enter Rate Of Product from(1:5): ";
				int star;
				cin >> node->stars;
				
				cout << "Thank You For Rating The Product " << node->stars << "Stars" << endl;
				return;
				
			}
			node = node->next;
		}

		cout << "\n\n";
		cout << "\n\n Product ID Is Invalid......." << endl;
		
	}
}

product_Node Product::getAllIteams(int id)
{
	product_Node* node = head;
	
	while (node != NULL)
	{
		if (node->Product_ID == id)
		{

			return *node;

		}
		node = node->next;
	}




	return *node;
}

void Product::display()
{
	if (head == NULL) {
		cout << "\n\n The List Is Empty.....\n";
		
	}
	else {
		product_Node* node = head;
		cout << "The existing products are: \n";
		cout << "=================================================================================================================|\n";
		cout << "  ID     Product Name    Product Price    Product Quantity    Product Category    Seller ID     Rate\n";
		cout << "=================================================================================================================|\n";
		while (node != NULL) {
			cout << "  " << node->Product_ID << "\t\t"
				<< node->Product_Name << "\t\t"
				<< node->Product_Price << "\t\t"
				<< node->Quantity << "\t\t"
				<< node->Product_Category << "\t\t"
				<< node->Seller_Id << "\t\t"
				<< node->stars << endl;
			node = node->next;
		}

	}
}

void Product::remove()
{
	cout << "Enter id\n";
	int id;
	cin >> id;
	if (head == NULL)
		cout << "\t\tThe product list is empty\n";

	else if (head->Product_ID == id)
	{
		product_Node* current = head;
		head = head->next;
		delete current;

	}
	else
	{
		product_Node* node = head;
		product_Node* prev = head->next;

		while (node != NULL)
		{
			if (node->Product_ID == id)
				break;
			else
			{
				prev = node;
				node = node->next;
			}
		}
		if (node == NULL)
			cout << "Can't remove value: no match found.\n";

		else
		{

			prev->next = node->next;
			delete node;
			cout << " Deleting done ";
		}

	}

}


void Product::update()
{
	product_Node* node = head;
	int id, found = 0;
	if (head == NULL) {
		cout << "The List Is Empty......." << endl;
		
	}
	else {
		cout << "Product ID : ";
		cin >> id;
		while (node != NULL) {
			if (id == node->Product_ID) {
				cout << "\n\n The Product Name Is: " << node->Product_Name << endl;;
				cout << " The New Product ID Is : ";
				cin >> node->Product_ID;
				cout << "\n\n The New Product Price Is : ";
				cin >> node->Product_Price;
				cout << "\n\n The New Product Name Is: ";
				cin >> node->Product_Name;
				cout << "\n\n The New Product Category Is : ";
				cin >> node->Product_Category;
				cout << "\n\n The New Seller ID is: ";
				cin >> node->Seller_Id;
				//node->next = NULL;
				//found++;
				cout << "\n\n\t\t\tUpdat Product Succesfully......." << endl;
				return;
			}
			node = node->next;
		}
		
			cout << "\n\n Product ID Is Invalid......." << endl;
		
	}

}

void Product::changeQuantity(int id, int sold)
{
	product_Node* node = head;

	while (node != NULL)
	{
		if (node->Product_ID == id)
		{

			node->Quantity -= sold;
			break;

		}
		node = node->next;
	}
}

product_Node::product_Node()
{
	next = NULL;
	stars = 0;
	Product_Price = -1;
}
