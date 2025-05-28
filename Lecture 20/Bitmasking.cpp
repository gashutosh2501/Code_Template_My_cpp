#include<iostream>
using  namespace std;

/*
	Bitwise Operators: Work on bits

	& : And
	| : Or
	~ : Not
	^ : xor

	1's Complement/2's Complement :

	And:

	0 & 1 = 0
	1 & 0 = 0
	0 & 0 = 0
	1 & 1 = 1

	Or:

	0 | 0 = 0
	0 | 1 = 1
	1 | 0 = 1
	1 | 1 = 1

	Not:

	Bit ko reverse: ~

	Xor:

	0 ^ 0 = 0
	0 ^ 1 = 1
	1 ^ 0 = 1
	1 ^ 1 = 0


	Left Shift:(<<)

	00010100 << 2

	01010000

	(a<<b) : (a*(2^b))


	Right Shift: (>>)

	00010100 >> 2

	(a>>b) : (a/(2^b))

*/

int main() {
	cout << (~0) << endl;
	int x;
	cin >> x;
	if ((x & 1) == 1) {
		cout << "Odd" << endl;
	} else {
		cout << "Even" << endl;
	}



}











