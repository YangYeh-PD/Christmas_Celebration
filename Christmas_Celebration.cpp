#include <iostream>
#include "christmas.h"
using namespace std;

int main(void)
{
	int num;
	Christmas tree;
	cout << "Enter the number of layers (2 to 5) = ";
	cin >> num;
	tree.setnum_layers(num);
	cout << "Enter the side length of the top layer = ";
	cin >> num;
	tree.settop_length(num);
	cout << "Enter the growth of each layer = ";
	cin >> num;
	tree.setgrowth(num);
	cout << "Enter the trunk width (odd number, 3 to 9) = ";
	cin >> num;
	tree.setwidth(num);
	cout << "Enter the trunk height (4 to 10) = ";
	cin >> num;
	tree.setheight(num);

	tree.check();
	tree.print();
	
	return 0;
}
