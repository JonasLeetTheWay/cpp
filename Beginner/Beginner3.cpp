#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <charconv>

#define MAX_DIGITS 10

// for-loop exercises
// https://www.w3resource.com/cpp-exercises/for-loop/index.php

using namespace std;



void ex1(int& n) {
	// find the first 10 natural numbers
	// set n=10
	for (int i = 1; i < n+1; i++) {
		cout << i << " ";
	}
	cout << endl << endl;
}
void ex2() {
	// find the sum of first 10 natural numbers
	int sum = 0;
	for (int i = 1; i < 11; i++) {
		sum += i;
		
	}
	cout << sum << endl;
	cout << endl << endl;
}
void ex3() {
	// display n terms of natural number and their sum
	int n;
	cout << "Input a number of terms: ";
	cin >> n;
	cout << "The natural numbers up to " << n << "th terms are:" << endl;
	ex1(n);
	cout << endl << endl;
}
void ex4() {
	// find the perfect numbers between 1 and 500
	// https://www.w3resource.com/w3r_images/cpp-for-loop-image-exercise-4.png
	
	int count = 0;
	auto findPerfectNum = [&](int& n) {
		// find divisor
		int limit = (int)n / 2;
		vector<int> res;
		for (int i = 1; i <= limit; i++) {
			count++;
			if (n % i == 0) {
				count++;
				res.push_back(i);
			}
		}
		// check if array element can sum up to be the same last divisor
		int sum = 0; 
		for (auto it = res.cbegin(); it != res.cend(); it++) {
			cout << "curr loop: " << count++ << ", " << *it << endl;
			sum += *it;
		}
		res.clear();
		if (sum == n) return true;
		else return false;
	};
	
	for (int i = 1; i <= 500; i++) {
		if (findPerfectNum(i)) {
			cout << i << " is a perfect number" << endl;
		}
	}
}
void ex4_2() {
	// find the perfect numbers between 1 and 500
	// https://www.w3resource.com/w3r_images/cpp-for-loop-image-exercise-4.png
	
	int count = 0;
	auto findPerfectNum = [&](int& n) {
		// find divisor
		int limit = (int) sqrt(n);
		vector<int> res;
		for (int i = 1; i <= limit; i++) {
			count++;
			if (n % i == 0) {
				count++;
				res.push_back(i);
				if (n != (n / i)) {
					count++;
					res.push_back(n / i);
				}
			}
		}
		// check if array element can sum up to be the same last divisor
		int sum = 0;
		for (auto it = res.cbegin(); it != res.cend(); it++) {
			cout << "curr loop: " << count++ << ", " << *it << endl;
			sum += *it;
		}
		res.clear();
		if (sum == n) return true;
		else return false;
	};

	for (int i = 1; i <= 500; i++) {
		if (findPerfectNum(i)) {
			cout << i << " is a perfect number" << endl;
		}
	}
}
void ex4_3() {
	cout << "\n\n Find the perfect numbers between 1 and 500:\n";
	cout << "------------------------------------------------\n";
	int i = 1, u = 1, sum = 0, count = 0;
	cout << "\n The perfect numbers between 1 to 500 are: \n";
	while (i <= 500)
	{
		while (u <= 500)
		{
			if (u < i)
			{
				if (i % u == 0)
					sum = sum + u;
			}
			u++;
		}
		if (sum == i) {
			cout << i << "  " << "\n";
		}
		i++;
		u = 1;
		sum = 0;
	}
	
}
bool isPrime(int n) {
	// check whether a number is prime or not
	if (n == 2 || n == 3)
		return true;

	if (n <= 1 || n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}

	return true;
}
void ex6() {	
	int low, high;
	cout << "Input number for starting range: "; cin >> low;
	cout << "Input number for ending range: "; cin >> high;

	for (int target=low; target < high; target++) {
		if (isPrime(target)) { cout << "prime num: " << target << endl; }
	}
}
void ex7() {
	// find the factorial of a number
	int n, res=1;
	cout << "Input a number to find the factorial : "; cin >> n; cout << endl;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	cout << "The factorial of the given number is : " << res << endl;
	cout << endl << endl;
}
void ex8() {
	// find the last prime number occur before the entered number
	int n;
	vector<int> primenums;
	cout << "Input a number to find the last prime number occurs before the number : "; cin >> n; cout << endl;
	
	for (int i = 1; i < n; i++) {
		if (isPrime(i)) { primenums.clear(); primenums.push_back(i); }
	}
	cout << primenums.back() << " is the last prime number before " << n;
	cout << endl << endl;
}
void gcd() {
	int a, b;
	cout << "Input the first number : "; cin >> a;
	cout << "Input the second number : "; cin >> b;
	int R;
	while ((a % b) > 0) {
		R = a % b;
		a = b;
		b = R;
	}
	cout << "The Greatest Common Divisor is : " << b;
	cout << endl << endl;
}
void ex10() {
	// find the sum of digits of a given number
	int n, res=0;
	cout << "Input a number : "; cin >> n;
	string s = to_string(n);
	const char* carr = s.c_str();
	for (int i = 0; *carr != '\0'; carr++) {
		res += *carr - '0';
	}
	cout << "The sum of digits of " << s <<" is : " << res;
	cout << endl << endl;
}
void ex11() {
	// find the sum of the series 1 + 1/2^2 + 1/3^3 + ..+ 1/n^n
	int n;
	double res;
	double res_final=0;
	cout << "Input the value for nth term: "; cin >> n;
	for (int i = 1; i <= n; i++) {
		res = 1 / (pow(i,i));
		res_final += res;
		cout << "1/" << i << "^" << i << " = " << res << endl;
	}
	cout << "The sum of the above series is: " << res_final << endl;
	cout << endl << endl;
}
void ex12() {
	// calculate the sum of the series (1*1) + (2*2) + (3*3) + (4*4) + (5*5) + ... + (n*n)
	int n;
	double res;
	double res_final = 0;
	cout << "Input the value for nth term: "; cin >> n;
	for (int i = 1; i <= n; i++) {
		res = i*i;
		res_final += res;
		cout << i << "*" << i << " = " << res << endl;
	}
	cout << "The sum of the above series is: " << res_final << endl;
	cout << endl << endl;
}
void ex13() {
	// calculate the series (1) + (1+2) + (1+2+3) + (1+2+3+4) + ... + (1+2+3+4+...+n)
	int n;
	int temp=0, final=0;
	vector<int> res;
	cout << "Input the value for nth term : "; cin >> n;
	for (int i = 1; i <= n; i++) {
		res.push_back(i); // collect elements based on loop num
		for (auto it = res.cbegin(); it != res.cend(); it++) {
			temp += *it;
			if (*it != res.back()){ cout << *it << " + "; }
			else { cout << *it; }
		}
		//cout << res.back();
		cout << " = " << temp << endl;
		final += temp; // track "sum of temp"
		//res.clear(); // reset
		temp = 0; // reset
	}
	res.clear();
	cout << "The sum of the above series is : " << final;
	cout << endl << endl;
}
void ex14() {
	// find the sum of series 1 - X^2 /2! + X^4 /4!-.... upto nth term
	/*
	Input the value of X: 3
	Input the value for nth term: 4
	term 1 value is: 1
	term 2 value is: -4.5
	term 3 value is: 3.375
	term 4 value is: -1.0125
	The sum of the above series is: -1.1375
	*/
	int x, n;
	int j;
	float temp;
	float res=1; // initialize as first term of series

	auto factorial = [&](int& q) {
		int fact = 1;
		for (int k = 1; k <= q; k++) {
			fact *= k;
		}
		return fact;
	};

	////////////////////////// START HERE ////////////////////////
	cout << "Input the value of X : "; cin >> x;
	cout << "Input the value for nth term : "; cin >> n;
	
	cout << "term 1 value is: " << res << endl;
	for (int i = 1; i < n; i++) {
		j = 2 * i;
		if (i % 2 != 0) {
			res += -pow( x,j )/factorial(j);
			temp = -pow(x, j) / factorial(j);
		}
		else {
			res += pow(x, j)/factorial(j);
			temp = pow(x, j)/factorial(j);
		}
		cout << "term " << i+1 << " value is: " << temp << endl;
	}

	cout << "The sum of the above series is : " << res << endl;
	cout << endl << endl;
}
int largestNumber(int nVariables, int numbers[]) //pass number of variables and number array
{
	int largest = numbers[0]; //initiate largest as the number at index 0

	for (int i = 0; i <= nVariables; i++) { //for loop to iterate through the numbers array that is nVariables long
		largest = (largest < numbers[i] ? numbers[i] : largest);
		//^ternary operator same as:
		/*
			if(largest < numbers[i]){
				largest = numbers[i]; //sets largest as numbers[current iteration of i]
			}
			else{
				largest = largest; // stays same
			}
		*/
	}

	return largest;
}
void ex15() {
	// ask user to input positive integers
	// to process: count, maximum, minimum, and average or terminate the process with -1
	int n, temp;
	float sum = 0;
	vector<int> inputs;
	cout << "How many positive integers u wish to input? "; cin >> n; cout << endl;
	for (int i = 0; i < n; i++) {
		cout << ">> positive integer " << i+1 <<": "; cin >> temp;
		inputs.push_back(temp);
	}
	// loop thru vector, to find total sum
	int largest = inputs.front(); //initiate largest as 1st element
	int smallest = inputs.front(); //initiate smallest as 1st element
	for (auto it = inputs.cbegin(); it != inputs.cend(); it++) {
		largest = (largest < *it ? *it : largest);
		smallest = (smallest > *it ? *it : smallest);
		sum += *it;
	}
	cout << endl << endl;
	cout << "Number of positive integers is: " << n << endl;
	cout << "The maximum value is : " << largest << endl;
	cout << "The minimum value is : " << smallest << endl;
	cout << "The average is " << sum / n << endl;
	cout << endl << endl;

}
void ex17() {
	/*
	Print a pattern like square with # character:
	--------------------------------------------------
	Input the number of characters for a side : 4
	# # # #
	# # # #
	# # # #
	# # # #
	*/
	char c;
	int n;
	cout << "Which character would you like to fill your square in? "; cin >> c; cout << endl;
	cout << "Input the number of characters for a side : "; cin >> n; cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void ex18() {
	// display the cube of the number upto given an integer
	int n;
	cout << "Input the number of terms : "; cin >> n; cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << "Number is : " << i << ", and the cube of " << i << " is : " << i*i*i << endl;
	}
	cout << endl << endl;
}
void ex19() {
	// display the multiplication table vertically from 1 to n
	int n,res;
	cout << "Input the number upto : "; cin >> n; cout << endl;
	cout << "Multiplication table from 1 to " << n << endl;
	cout << "--------------------------------------------------------------------------\n";
	// 1x1=1 2x1=2 3x1=3 4x1=4 5x1=5
	for (int i=1; i<=12; i++) {
		for (int j = 1; j <= 5; j++) {
			res = i * j;
			cout << j << "x" << i << "=" << res << "\t\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void ex20() {
	// display the n terms of odd natural numberand their sum
	int n, sum = 0, count=1;
	cout << "Input number of terms : "; cin >> n;
	cout << "The natural odd numbers are : ";
	for (int i = 1; count <= n; i++) {
		if (i % 2 != 0) {
			sum += i;
			count++;
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "The Sum of odd Natural Numbers upto "<<n<<" terms : "<<sum;
	cout << endl << endl;
}
void ex22() {
	// display the n terms of harmonic series and their sum
	/*
	1 + 1/2 + 1/3 + 1/4 + 1/5 ... 1/n terms
	Sample Output :
	Input number of terms : 5
	1/1 + 1/2 + 1/3 + 1/4 + 1/5
	The sum of the series upto 5 terms : 2.28333
	*/
	int n;
	float sum = 0;
	cout << "Input number of terms : "; cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += 1/float(i);
		if (i<n)
			cout << "1/" << i << " + "; // each term

	}
	cout << "1/" << n << endl; // last term
	cout << "The sum of the series upto " << n << " terms : " << sum;
	cout << endl << endl;
}
void ex23() {
	// display the sum of the series[9 + 99 + 999 + 9999 ...]
	/*
	Input number of terms: 5
	9 99 999 9999 99999
	The sum of the series = 111105
	*/
	int m, n;
	long long sum = 0;
	cout << "Input number of terms: "; cin >> m;
	cout << "Input a number : "; cin >> n;
	for (int i = 1; i <= m; i++) {
		string s = string(i, char(n) + '0'); // ASCII Table
		cout << s << " ";
		long long element = stoll(s);
		sum += element;
	}
	cout << endl;
	cout << "The sum of the series = " << sum;
	cout << endl << endl;
}
int main() {
	/*int n = 9;
	string s = string(5, char(n) + '0');
	cout << s << endl;
	cout << stol(s) - 1<< endl;*/
	ex23();

	return 0;
}
/*
void timecheck() {
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	ex4_3(); // CHECK HERE
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[s]" << std::endl;
}
*/