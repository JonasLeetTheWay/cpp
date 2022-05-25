// Beginner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h> //srand,rand
#include <stdio.h>
#include <string>
#include <time.h> //time -- generate random seed with different current time  srand(time(NULL))
#include <algorithm>
#include <array>

using namespace std;

void varExchanger() {
	int x;
	int y;
	int temp = 0;
	std::cout << "Input x: "; std::cin >> x;
	std::cout << "Input y: "; std::cin >> y;
	std::cout << "x: " << x << " - y: " << y << std::endl;
	temp = x;
	x = y;
	y = temp;
	std::cout << "x: " << x << " - y: " << y << std::endl;
	if (x > y) {
		std::cout << "the larger value is: " << x;
	}
	else if (y < x) {
		std::cout << "the larger value is: " << y;
	}
	else {
		std::cout << "they are equal";
	}
}

// solve array to pointer, pointer to array repackaging
void varExchanger2(int a, int b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
	int res[] = {a, b};
}

void cubeCalculator() {
	double length;
	double volume;
	int density;
	double weight;
	double force;
	std::cout << "Welcome to the cube calculation program.\nPlease input your desired cube specs!" << std::endl;
	std::cout << "What is the cube length?"; std::cin >> length; std::cout << std::endl;

	volume = pow(length / 100, 3);

	printf("The side length will be: %.0f cm \n", length);
	printf("The volume will be: %.3f m3 \n", volume);

	std::cout << "What is the density?\n1. plastic, 2. wood, 3. iron, ~. 10000kg/m3"; std::cin >> density; std::cout << std::endl;
	switch (density) {
	case 1:
		density = 5;
		std::cout << "The material plastic has been chosen." << std::endl; break;
	case 2:
		density = 15;
		std::cout << "The material wood has been chosen." << std::endl; break;
	case 3:
		density = 25;
		std::cout << "The material iron has been chosen." << std::endl; break;
	default:
		density = 10000;
		std::cout << "The material is unknown, however p = 10000kg/m3." << std::endl; break;
	}

	weight = volume * density;
	force = weight * 9.81;

	printf("The weight will be: %.3f kg \n", weight);
	printf("The force necessary to get your cube moving will be: %.3f N \n", force);
}


string reverseString(string str) {
	const char* ori = str.c_str();
	int len = str.length();
	char* c = new char[len];
	memcpy(c, ori, len);
	for (int low = 0, high = len - 1; low < high; low++, high--) {
		char temp = c[low];
		c[low] = c[high];
		c[high] = temp;
	}
	string res = string(c, len);
	delete[] c;
	return res;
}
string reverseString2(string c) {
	int len = c.length();
	for (int low = 0, high = len - 1; low < high; low++, high--) {
		char temp = c[low];
		c[low] = c[high];
		c[high] = temp;
	}
	return c;
}
void aaa(const char* str) {
	char buf[64];
	char a[] = "123"; //zero-terminated string
	char b[] = "456";
	memcpy(buf, a, sizeof(a) - 1);
	memcpy(buf + sizeof(a), b, sizeof(b) - 1);
	int str_len = strlen(str);
	memcpy(buf + str_len, str, str_len);
	buf[sizeof(a) + sizeof(b) + str_len] = '\0';
	printf("buf: %s\n", buf);
}
void calc_sum(int a, int b, int& c) {
	c = a + b;
}
void swap(int& a, int& b) {
	int temp = a;
	a = b; 
	b = temp;
}

/*
	char C[6] = "Hello";
	// length = 6 (5 for chars, 1 for terminated warning '\0')
	// b/c string-array quirkiness of having a final slot for terminated warning
	// so we have to minus 1,
	// to get the actual length, to get the correct loop numbers = 5
	int size = *(&C +1) - C - 1; 
	int size2 = sizeof(C) / sizeof(C[0]) -1;

	printString(C, size);
*/
void printIntArray(int* p, int size) {
	// original order
	for (int i = 0; i < size; i++) {
		cout << *p;
		p++;
		printf("\t\tCurrent loop i is: %d\n", i);
	}
	cout << endl;
	// after for-loop above, pointer is now at the end of array (NULL-TERMINATED POSITION)
	// hence we need to decrease 1, so that it is before NULL-TERMINATED POSITION
	p--;

	//// reverse order
	//for (int i = size; i > 0; i--) {
	//	cout << *p;
	//	p--;
	//}
}
void createNDimArray() {

	//int n;
	//printf("Enter size of array\n");
	//scanf_s("%d", &n);
	//int* A = (int*)malloc(n * sizeof(int));// dynamically allocated array
	//for (int i = 0; i < n; i++)
	//{
	//	A[i] = i + 1;
	//}
	//free(A);
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d", A[i]);
	//}
	//free(A);
	/*
	int n, len;
	string dtype;
	printf("Enter the datatype of array:\n");
	getline(cin, dtype);
	printf("Enter dimension of array:\n");
	scanf("%d", &n);
	// dynamically allocated array
	switch (n) {
	case 1:
		printf("Enter length of array:\n");
		scanf("%d", &len);
		int* p = (int*)malloc(len * sizeof(dtype));

		for (int i = 0; i < len; i++) {
			*(p+i) = i+1; // p[i] -- p gives base of array address, p[i] index element based on traversing array thru "i steps" from base
			printf("%d", p[i]);
		}
	}
	*/
}

int compare(int a, int b) {
	if (a > b) return -1;
	else return 1;
}
void BubbleSort(int* A, int n, int (*compare)(int, int)) {
	int i, j, temp, count=0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n - 1; j++) {
			printf("Curr loop is no. %d \t\t", ++count - 1);
			cout << compare(A[j], A[j+1]) << "\n";
			
			if (compare(A[j], A[j + 1]) > 0) {
				cout << "\t\t\t\tExchanging num..." << A[j+1] << "to" << A[j] << endl;
				temp = A[j+1];
				A[j+1] = A[j];
				A[j] = temp;
			}
		}

	printIntArray(A, n);
}
void ex3() {
	int m = 300;
	float f = (float)300.600006;
	char ch = 'z';
	int* p;
	float* p1;
	char* p2;

	cout << &m << endl;
	cout << &f << endl;
	cout << (void*)&ch << endl;

	p = &m;
	cout << *p << endl;
	p1 = &f;
	cout << *p1 << endl;
	p2 = &ch;
	cout << *p2 << endl;
}
void ex4() {
	int a = 5, b = 6;
	cout << *&a + *&b;
}
void ex6() {
	// find max num
	int a = 5, b = 6;
	int *p1=&a, *p2=&b;
	if (*p1 > *p2) cout << *p1;
	else cout << *p2;
}
void ex7() {
	/*
	Input the number of elements to store in the array :5
	Input 5 number of elements in the array :
	element - 0 : 5
	element - 1 : 7
	element - 2 : 2
	element - 3 : 9
	element - 4 : 8
	*/
	int numEle,temp,len;
	int A[20];

	cout << "Input number of elements to store in the array\n";
	cin >> numEle;
	len = numEle;
	
	cout << "Input " << numEle << " numbers of elements in the array:\n";

	/*while (numEle>0) {
		cout << "element - " << len+1 - numEle << " : ";
		cin >> temp; A[numEle] = temp;
		cout << endl;
		numEle--;
	}*/
	for (; numEle > 0; numEle--) {
		cout << "element - " << len+1 - numEle << " : ";
		cin >> temp;
		*(A+ len-numEle) = temp;
	}
	printIntArray(A,len);
}
void ex9() {
	auto copyLargertoPrevious = [](int& a, int& b) {
		a = b;
		b = a;
	};

	int arr[] = { 5,5,51,1,100,1000,0 };
	int* p = arr;
	int size = *(&arr + 1) - arr;
	
	for (int i = 0; i < size; i++) {
		cout << "Current loop " << i << " shows arr element " << *(p + i) << endl;
		if (i < size - 1) {
			if (*(p + i) < *(p + i + 1)) {
				copyLargertoPrevious(*(p + i), *(p + i + 1));
				cout << "swapping... " << endl;
			}
		}
		else {
			if (*(p + i) < *(p + i - 1)) {
				copyLargertoPrevious(*(p + i), *(p + i - 1));
			}
		}
		cout << *(p + i) << endl;
	}
	printIntArray(arr,size);
	cout << "So the largest element is the SECOND-LAST element of array with 1-time traverse sorting..\n" << arr[size - 1] << endl;
}
void ex10() {
	// cal length of string using ptr
	const char* str = "im a string btw";
	const char* p = str;
	int count=0;
	while ( *p != '\0') {
		cout << "Ptr at index " << count << "\t\tpoints at char: " << *p << endl;
		p++;
		count++;
	}
	cout << "The length of string is: " << count;
}
void ex11() {
	// swap elements using call by reference

	/* learn nice function*/
	auto swapNumbers = [](int* x, int* y, int* z)
	{
		int tmp;
		tmp = *y;
		*y = *x;
		*x = *z;
		*z = tmp;
	};
	
	int arr[] = { 5,6,7 };
	int* p1 = arr;
	int* p2 = arr + 1;
	int* p3 = arr + 2;
	int temp = *(arr+1);

	*p2 = *p1;
	*p1 = *p3;
	*p3 = temp;

	int new_arr[] = { *p1,*p2,*p3 };
	printIntArray(new_arr, 3);
}
void ex12() {
	// program to find the factorial of a given number using pointers
	int n;
	cout << "Enter the length of array: "; cin >> n;
	int arr[20];
	int size = n;
	int* p = arr;
	int sum = 1;
	for (int i = 0; i < size-1; i++) {
		arr[i] = size-i;
		sum *= *(p + i);
		cout << sum << endl;
	}
}
void ex13() {
	// count the number of vowels and consonants in a string using a pointer
	char str[] = "string";
	int lenStrArr = *(&str + 1) - str - 1;
	char* p = str;

	char vowel[] = "aeiouAEIOU";
	int lenVowelArr = *(&vowel + 1) - vowel - 1;
	
	int vowelCount = 0;

	for (int j = 0; j < lenStrArr; j++) {
		for (int i = 0; i < lenVowelArr; i++) {
			if (str[j] == vowel[i]) vowelCount++;
		}
	}
	cout << "Number of vowels: " << vowelCount << endl;
	cout << "Number of consonants: " << lenStrArr - vowelCount << endl;

	/*
	while(*pt!='\0')
    {
        if(*pt=='A' ||*pt=='E' ||*pt=='I' ||*pt=='O' ||*pt=='U' ||*pt=='a' ||*pt=='e' ||*pt=='i' ||*pt=='o' ||*pt=='u')
            ctrV++;
        else
            ctrC++;
        pt++; //pointer is increasing for searching the next character
    }
	*/

}
void ex14() {
	/*
	// sort an array using Pointer
	Input the number of elements to store in the array : 5
		Input 5 number of elements in the array :
		element - 1 : 25
		element - 2 : 45
		element - 3 : 89
		element - 4 : 15
		element - 5 : 82
	*/
	auto mybubblesort = [](int* p, int size) {
		int* p_original_address = p;
		for (int i = 0; i < size; i++) {
			p = p_original_address; // reset pointer to arr base address every outer loop
			for (int j = 0; j < size-1; j++) {
				if (*p > *(p + j)) {
					int temp = *(p + j);
					*(p + j) = *p;
					*p = temp;
				}
				p++;
			}
		}
	};

	int arr[] = { 25,45,89,15,82,0 };
	int* p = arr;
	int size = *(&arr + 1) - arr;
	
	mybubblesort(p,size);
	printIntArray(arr,size);
}
int* ex15(int &a, int &b) {
	/*
	Write a program in C to show how a function returning pointer
	*/
	if (a > b) return &a;
	else return &b;

}
void ex16() {
	/*
	compute the sum of all elements in an array using pointers
	*/
	int arr[10];
	int len;
	int sum=0;
	cout << "Enter the number of elements to store in array: (max 10)" << endl;
	cin >> len;
	cout << "Input " << len << " number of elements in the array :" << endl;
	for (int i = 0; i < len; i++) {
		cout << "element - " << i+1 << " : ";
		cin >> *(arr+i);
		sum += *(arr + i);
		cout << "\t\t\tcurrent sum is.." << sum << endl;
	}
	cout << "final sum is.." << sum;
}
void ex17() {
	/*
	print the elements of an array in reverse order
	*/
	int arr[] = { 1,2,3,4,5 };
	int* p = arr;
	int size = *(&arr + 1) - arr;

	cout << "The elements of array in reverse order are :" << endl;
	for (int i = size-1; i >= 0; i--) {
		cout << "element - " << i+1 << " : " << *(p + i) << endl;
	}
}
struct EmpAddress
{
	char* ename;
	char stname[20];
	int pincode;
}
employee = { (char*)"John Alter","Court Street \n",654134 }, * pt = &employee;

void ex21() {
	/*
	print all the alphabets using a pointer
	*/
	char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char* p = arr;
	cout << "The alphabets are :" << endl;
	while (*p != '\0') {
		cout << *p << " ";
		p++;
	}
}

void ex22() {
	/*
	print the elements of string array in reverse order
	*/
	char arr[] = "w3resource";
	char* p = arr;
	int size = *(&arr + 1) - arr -1;

	cout << "The elements of string array in reverse order are :" << endl;
	for (int i = size - 1; i >= 0; i--) {
		cout << "element - " << i + 1 << " : " << *(p + i) << endl;
	}
	
}
int main()
{
	/*printf("\n\n Pointer : Show the usage of pointer to structure :\n");
	printf("--------------------------------------------------------\n");
	printf(" %s from %s with pincode %d \n\n", pt->ename, (*pt).stname, (*pt).pincode);
	return 0;*/
	ex21();
}
