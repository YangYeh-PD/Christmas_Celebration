#include <iostream>
#include <bits/stdc++.h>
#include "christmas.h"
using namespace std;

void Christmas::setnum_layers(int number) {
	num_layers = number;
}
void Christmas::settop_length(int number) {
	top_length = number;
}
void Christmas::setgrowth(int number) {
	growth = number;
}
void Christmas::setwidth(int number) {
	width = number;
}
void Christmas::setheight(int number) {
	height = number;
}
void Christmas::check(void) {
	while (num_layers < 2 || num_layers > 5) {
		cout << "***The layers is invalid, please try again***\n";
		cout << "Enter the number of layers (2 to 5) = ";
		cin >> num_layers;
	}
	while ((width < 3 || width > 9) || (width % 2 == 0)) {
		cout << "***The trunk width is invalid, please try again***\n";
		cout << "Enter the trunk width (odd number, 3 to 9) = ";
		cin >> width;
	}
	while (height < 4 || height > 10) {
		cout << "***The trunk height is invalid, please try again***\n";
		cout << "Enter the trunk height (4 to 10) = ";
		cin >> height;
	}
}
void Christmas::print(void) {
	middle = mid();
	// The First layer
	cout << string(middle - 1, ' ') << "#" << endl;
	for (int i = 2; i <= top_length; i++) {
		 if (i != top_length) {
			 cout << string(middle - i, ' ') << "#" << string((2 * (i - 1)) - 1, '@') << "#" << endl;
		 } else {
			cout << string(middle - i, ' ') << string((2 * i) - 1, '#') << endl;
		 }
	}
	// Following layers
	for (int i = 2; i <= num_layers; i++) {
		int j = 1;
		for (; j < (top_length - 1) + growth * (i - 1); j++) {
			cout << string(middle - j - 1, ' ') << "#" << string(2 * j - 1, '@') << "#" << endl; 
		}
		cout << string(middle - j - 1, ' ') << string(2 * j + 1, '#') << endl;
	}
	// Trunk
	for (int i = 1; i <= height; i++) {
		cout << string(middle - width / 2 - 1, ' ') << string(width, '|') << endl;
	}
}
int Christmas::mid() {
	return (top_length - 1) + ((num_layers - 1) * growth) + 1;
}