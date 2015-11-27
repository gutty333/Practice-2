/*********************************************************************
	Assume a class named  Inventory keeps track  of products in stock for a company.  It
	has member  variables  prodID, prodDescription, and  qtyInStock. Write  a constructor  that   
	initializes   a  new  Inventory object   with   the  values  passed   as arguments, but which also 
	includes a reasonable  default  value for each parameter.

	Write  a remove member  function  that  accepts  an argument for a number  of units
	and  removes  that  number  of units  of an  item  from  inventory.  If the  operation is completed
	successfully it should  return  the number  of units remaining  in stock for that  item.  However,
	if the number  of units  passed  to the function  is less than  the number  of units  in stock,
	it should  not  make the removal  and  should  return  –1 as
	an error  signal.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Inventory
{
	// Member Variables
	private:
		int prodID;
		string description;
		int quantity;
	
	// Member functions
	public:
		Inventory(int id = 0, string name = "new", int amount=0) // Construct passing default values to members
		{
			prodID = id;
			description = name;
			quantity = amount;
		}
		int remove(int units)
		{
			if (units < quantity)
			{
				return -1;
			}

			return quantity -= units;
		}
};