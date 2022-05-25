#include <iostream>
#include <string>
#include <vector>
#include <chrono>

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
				if (((n / i) % 1 == 0) && (n != (n / i))) {
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
		
int main() {


	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	ex4_2();
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[s]" << std::endl;

	return 0;
}