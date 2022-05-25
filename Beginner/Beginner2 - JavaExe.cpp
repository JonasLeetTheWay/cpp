#include <iostream>
#include <stdlib.h> //srand,rand
#include <stdio.h>
#include <string>
#include <time.h> //time -- generate random seed with different current time  srand(time(NULL))
#include <algorithm>
#include <array>
#include <cctype>
#include <math.h>

using namespace std;

void varExchanger() {
	int x;
	int y;
	int temp = 0;
	cout << "Input x: "; cin >> x;
	cout << "Input y: "; cin >> y;
	cout << "x: " << x << " - y: " << y << endl;
	temp = x;
	x = y;
	y = temp;
	cout << "x: " << x << " - y: " << y << endl;
	if (x > y) {
		cout << "the larger value is: " << x;
	}
	else if (y < x) {
		cout << "the larger value is: " << y;
	}
	else {
		cout << "they are equal";
	}
	cout << endl << endl << endl;
}

// solve array to pointer, pointer to array repackaging
void varExchanger2(int a, int b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
	int res[] = { a, b };
}

void cubeCalculator() {
	double length;
	double volume;
	int density;
	double weight;
	double force;
	cout << "Welcome to the cube calculation program.\nPlease input your desired cube specs!" << endl;
	cout << "What is the cube length?"; cin >> length; cout << endl;

	volume = pow(length / 100, 3);

	printf("The side length will be: %.0f cm \n", length);
	printf("The volume will be: %.3f m3 \n", volume);

	cout << "What is the density?\n1. plastic, 2. wood, 3. iron, ~. 10000kg/m3"; cin >> density; cout << endl;
	switch (density) {
	case 1:
		density = 5;
		cout << "The material plastic has been chosen." << endl; break;
	case 2:
		density = 15;
		cout << "The material wood has been chosen." << endl; break;
	case 3:
		density = 25;
		cout << "The material iron has been chosen." << endl; break;
	default:
		density = 10000;
		cout << "The material is unknown, however p = 10000kg/m3." << endl; break;
	}

	weight = volume * density;
	force = weight * 9.81;

	printf("The weight will be: %.3f kg \n", weight);
	printf("The force necessary to get your cube moving will be: %.3f N \n", force);
	cout << endl << endl << endl;
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
	buf[sizeof(a) + sizeof(b) + str_len] = '\0'; // sentinel for termination
	printf("buf: %s\n", buf);
}

void printStrArr(char* p, int size) {
	for (int i = 0; i < size; i++) {
		cout << *p;
		p++;
	}
	cout << endl << endl << endl;
}
void printIntArr(int* p, int size) {
	for (int i = 0; i < size; i++) {
		cout << *p;
		p++;
	}
	cout << endl << endl << endl;
}
/*
int len = 10;
char* generated = generateNewPassword(len);
printStrArr(generated, len);
*/
char* generateNewPassword(int passLength) {
	char dict[] = "abcdefghijklmnopqrstuvwxyz1234567890():$ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char* p = dict;
	int size = *(&dict + 1) - dict -1;
	char password[20]; // must be initialized
	srand(time(NULL));

	for (int i = 0; i < passLength; i++) {
		int randPick = rand() % size; // 0 ~ limit
		password[i] = *(p + randPick);
	}
	return p = password; // ptr has changed target

	cout << endl << endl << endl;
}
void checkPassword() {
	bool flag1 = false, flag2 = false, flag3 = false;

	auto _password_rule = []() {
		cout << "---------------------------------\n";
		cout << "Enter password as string, below are the rules: " << endl;
		cout << "1. it contains at least 6 characters." << endl;
		cout << "2. it contains at least 1 number." << endl;
		cout << "3. it doesn't contain the characters  '+' and  '-'." << endl;
		cout << "---------------------------------\n\n\n\n";
	};

	auto _read_password = [&](bool& flag1, bool& flag2, bool& flag3) {
		// reset boolean every run
		int count = 1;

		cout << "Please input password: " << endl;
		//cin.ignore();
		string str;
		getline(cin, str);

		// copy string to c-string buffer
		char buffer[100];
		strcpy_s(buffer, str.c_str());

		// create pointer to c-string buffer
		char* cstr = buffer;
		char* cstr_ori_addr = cstr;

		// terminate process if string length < 6, only can be done after initialization
		// 6 has to 5 !!
		if (str.length() < 5) { 
			cout << "short af!" << endl;
			goto end; 
		}
		cout << "--------------------------\n";
		cout << "checking digits ..." << endl;
		// return false if any element in c-array contains digit
		while (*cstr != '\0') {
			if (isdigit(*cstr)) {
				cout << ">> has at least " << count++ << " digit" << endl;
				flag1 = true;
			}
			cstr++;
		}
		
		// reset address
		cstr = cstr_ori_addr; 

		cout << "checking + - ..." << endl;
		// return true if any element in c-array contains both '+' & '-'
		while (*cstr != '\0') {
			if (*cstr == '+') {
				cout << ">> has + sign" << endl;
				flag2 = true;
			}
			if (*cstr == '-') {
				cout << ">> has - sign" << endl;
				flag3 = true;
			}
			cstr++;
		}
	end: {cout << endl; } // even empty, it needs body
	};

	//auto _check_password = [&]() {
	//};
	
	_password_rule();
	while (!flag1 || !flag2 || !flag3) {
		_read_password(flag1,flag2,flag3);
	}
	cout << ">> congrats! all passed!" << endl;

	cout << endl << endl << endl;
}
void convHexDec2String() {
	// 15 to allow extra spaces for c-array to store string (ele + sentinel)
	char arr[][15] = { "2ae43", "8g023", "249abc", "2354aer23", "234245" };
	int size1 = sizeof(arr) / sizeof(arr[0]);

	// print each string to console
	for (int i = 0; i < size1; i++) {
		cout << "string " << i + 1 << ":\t ";
		for (char c : arr[i]) {
			cout << c;
		}
		cout << endl;
	}
	cout << endl;

	char valid[] = "0123456789abcdef";
	int size2 = *(&valid + 1) - valid-1;

	// print Valid Chars: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f,
	cout << "Valid Chars:\t ";
	for (int i = 0; i < size2; i++) {
		cout << *(valid+i) << ", ";
	}
	cout << endl << endl << endl;

	// if valid, go to convert
	// if not, print not valid
	auto checkValid = [&](char* arr) {
		for (int j = 0; arr[j] != '\0'; j++) {
			for (int k = 0; k < size2; k++) {

				//cout << arr[j] << ",";		DEBUG
				if (arr[j] == valid[k]) { break; }
				//cout << valid[k] << "\t";		DEBUG
				if (k + 1 >= size2) { return false; }
			}
		}
		return true;
	};

	// if valid, convert and print hexstring
	auto convert_n_print = [&](char* arr) {

		// count current string length, since every string element diff length
		int arr_len = 0;
		// store into string, for printing later
		string str;
		for (int i = 0; arr[i] != '\0'; i++) {
			arr_len++;
			str.push_back(arr[i]);
		}
		cout << "\t this string:\t " << str << endl;
		cout << "\t arr_len:\t " << arr_len << endl;

		// conversion
		double sum = 0;
		for (int l = 0, h = arr_len - 1; l < arr_len & h >= 0; l++, h--) {

			// get numeric value of very character in string
			// '7' != '07' in ASCII, therefore need following logic

			//123456789
			bool bool1 = arr[h] - '0' > 0 && arr[h] - '0' < 10;
			//ABCDEF
			bool bool2 = arr[h] - '0' - 7 >= 10 && arr[h] - '0' - 7 < 15;
			//abcdef
			bool bool3 = arr[h] - '0' - 39 >= 10 && arr[h] - '0' - 39 < 15;

			if (bool1) {
				int char_numeric = arr[h] - '0';
				//cout << "current ele: " << arr[h] << ", its numeric val: " << char_numeric << ", times " << pow(16, l) << endl;
				sum += char_numeric * pow(16, l);
			}
			else if (bool2) {
				int char_numeric = arr[h] - '0' - 7;
				//cout << "current ele: " << arr[h] << ", its numeric val: " << char_numeric << ", times " << pow(16, l) << endl;
				sum += char_numeric * pow(16, l);
			}
			else if (bool3) {
				int char_numeric = arr[h] - '0' - 39;
				//cout << "current ele: " << arr[h] << ", its numeric val: " << char_numeric << ", times " << pow(16, l) << endl;
				sum += char_numeric * pow(16, l);
			}

		}
		printf("\t decimal value:\t %.0f", sum);
	};

	// use forloop to iterate through every string-element in arr
	for (int i = 0; i < size1; i++) {

		cout << "checking string " << i+1 << "..." << endl;

		if (checkValid(arr[i])) {
			cout << "\t it is valid" << endl;
			convert_n_print(arr[i]);
		}
		else { cout << "\t it is not valid" << endl; }

		cout << endl << endl;
	}

	cout << endl << endl << endl;
}
/*
char ori[] = "Able was I ere I saw Elba";
int size = *(&ori + 1) - ori -1;
PalindromeCheck(ori, size);
*/
void checkPalindrome(char* p, int size) {

	int half = (int)size / 2;
	int count = 0;
	cout << "The half is.." << half << endl;

	for (int j = 0; j < half; j++) {
		char fromLast = toupper(*(p + size - 1 - j));
		char fromFront = toupper(*(p + j));
		if (fromLast == fromFront) {
			cout << "matched letter is.. " << fromLast << endl;
			cout << count++ << endl;
		}
	}

	cout << "The count after forloop is.." << count << endl;
	if (count == half) { cout << "It is a palindrome!" << endl; }
	else { cout << "It is NOT a palindrome!" << endl; }

	cout << endl << endl << endl;
}
int main() {

	//varExchanger();
	//cubeCalculator();
	//generateNewPassword(10);
	//checkPassword();			BUG
	/*
	char ori[] = "Able was I ere I saw Elba";
	int size = *(&ori + 1) - ori -1;
	PalindromeCheck(ori, size);
	*/
	//convHexDec2String();

	return 0;
}