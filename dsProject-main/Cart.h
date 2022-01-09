#include<vector>
#include"Product.h"
using namespace std;

class Cart
{

	
public:
	vector<pair<int, int>>product_id;
	bool check_id(int id, int quantity, Product product);
	void calculate(Product product);
	
};
