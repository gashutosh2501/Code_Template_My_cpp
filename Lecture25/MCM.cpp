#include<iostream>
#include<vector>
using  namespace std;
#define int long long
#define mod 1000000000
int k;
int n;
vector<int>a, b, c;


/*
	Motivation: Solving Linear Recurrences
	in  O(k ^ 3 log(n)) time.

	f(i) = f(i - 1) + f(i - 2);
	k = 2;

	f(i) = f(i - 1) + f(i - 2) + f(i - 4);
	k = 4;

	RR: f(i)=f(i-1)+f(i-2);

	Steps:
	1. Find the value of k.
		(In this scenario k=2).
	2.Find the First k Terms.(Given)
		F1[0]
		  [1]
	3. Find the Transformation Matrix.
		Size Will always be (k*k).

	F(n) = T.F(n-1);
		 = T.T.F(n-2);

	F(n) = (T^n-1) * F1;


	How Do we Find out the Transformation Matrix:

		F(i) = 1* F(i-1)+ 2*F(i-2)+ 4 *F(i-4)+ d;

		T * f(i-4)   F(i-3)
			f(i-3) = F(i-2)
			f(i-2)	 F(i-1)
			f(i-1)   F(i)
			 d        d

		Above Case Transfomation Matrix=

		0 1 0 0 0
		0 0 1 0 0
		0 0 0 1 0
		4 0 2 1 1
		0 0 0 0 1


		Fast Power Multiplication:
		T^n = (T^n/2)^2 for Even n.
            = (T^n/2)^2 * T for Odd n.
*/


vector<vector<int>>Multiply(vector<vector<int>>A,
vector<vector<int>>B) {

	//To Store the output I am Creating C vector.
	vector<vector<int>>C(k + 1, vector<int>(k + 1));

	//Logic For Matrix Multiplication
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int x = 1; x <= k; x++) {
				C[i][j] = (C[i][j] + ((A[i][x] % mod) * (B[x][j] % mod))) % mod;
				// C[i][j] %= mod;
			}
		}
	}
	return C;
}

vector<vector<int>>power(vector<vector<int>>A, int p) {

	//Base Condition
	if (p == 1) {
		return A;
	}

	//If p is odd
	if (p & 1) {
		return Multiply(A, power(A, p - 1));
	}

	/*
		odd:
		x* (Power)^2
		(Power^2)
	*/

	//If Pow is Even just take the square
	// A*A
	vector<vector<int>>x = power(A, p / 2);
	return Multiply(x, x);

}

int Compute(int n) {

	//Base Condition:
	if (n == 0) {
		return 0;
	}

	//For the first k terms
	if (n <= k) {
		return b[n - 1];
	}

	//If not Then Use Matrix Chain Exponentiation.

	// Step 1: Create F1 vector.
	vector<int>F1(k + 1);//I follow 1 based Indexing.
	for (int i = 1; i <= k; i++) {
		F1[i] = b[i - 1];
	}

	//Step 2: Create your Transformation Matrix
	vector<vector<int>>T(k + 1, vector<int>(k + 1));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (i < k) {
				//Add 0s or 1s.
				if (j == i + 1) {
					T[i][j] = 1;
				} else {
					T[i][j] = 0;
				}

			} else {

				//Add the Coefficients
				T[i][j] = c[k - j];
			}
		}
	}

	// Step 3: Power of Transformation Matrix.
	T = power(T, n - 1);

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			cout << T[i][j] << " ";
		}
		cout << endl;
	}

	//Step 4: Mutiply Transformation Matrix with F1 to Create A.
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		ans = (ans + (T[1][i] * F1[i]) % mod) % mod;
		ans %= mod;
	}

	return ans;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> k;

		//Initial Values for F1 vector
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			b.push_back(x);
		}

		//Coefficient for the Linear Recurrences.
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			c.push_back(x);
		}

		cin >> n;

		//This is the term we need to find out.
		cout << Compute(n) << endl;

		b.clear();
		c.clear();
	}

}




