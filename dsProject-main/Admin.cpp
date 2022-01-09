#include "Admin.h"

bool Admin::checkProductAtrribute(int id, float price, int seller_id, int Quantity)
{
    
    return (id>0&&price>0&&seller_id>0&&Quantity>0);
}



void Admin::AdminRemove(Product& product)
{
    product.remove();
}
