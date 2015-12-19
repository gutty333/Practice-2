/*********************************************************************
	Modified Bin Manager Class

	Modify  the BinManager class you wrote  for Programming Challenge  15 in Chapter 8 to overload  its 
	getQuantity, addParts, and removeParts functions  as shown here:

		bool addParts(string itemDescription, int q); 
		bool removeParts(string itemDescription, int q) 
		int getQuantity(string itemDescription);

	These new functions  allow  parts  to  be added,  parts  to  be removed,  and  the  quantity in 
	stock for a particular item to be retrieved  by using an item description,  rather  than  a bin 
	number,  as an argument. In addition to writing  the three  overloaded functions,  you will need to 
	create  a private BinManager class function  that  uses the item description as a search key to 
	locate the index of the desired bin.
	Test the new class functions  with the same client program you wrote for Programming Challenge  15  
	in Chapter 8, modifying  it to  call the  new functions.  Be sure to  use some descriptions  that 
	match bins in the array and some that do not.
	As you  did  in  the  previous  Bin  Manager program, if  an  add  or  remove  operation is 
	successfully carried out, make the function  return  true. If it cannot  be done—for  example, 
	because the string passed to it does not match any item description in the array—make the function  
	 return   false.  If  the  getQuantity function   cannot   locate  any  item  whose
	description matches the one passed to it, make it return  −1.
*********************************************************************/
#include <iostream>
using namespace std;

int main()
{




	return 0;
}