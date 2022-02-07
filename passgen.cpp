#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>

std::string passGen(int diff, int len) {
	std::string s = "", chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=";
	s.resize(len + 3);
	if (diff == 1) {
		for (int i = 0; i < len; ++i) {
			s[i] = chars[rand() % 52];
		}
	}
	if (diff == 2) {
		for (int i = 0; i < len; ++i) {
			s[i] = chars[rand() % 62];
		}
	}
	if (diff == 3) {
		for (int i = 0; i < len; ++i) {
			s[i] = chars[rand() % 77];
		}
	}
	return s;
}

void passOut(std::string r, std::string s) {
	std::cout << "\n-> " << s << "\n";
	std::cout << r << ": " << s;
}

std::string passRedo(int diff, int len, std::string r, std::string s) {
	int pR = 1;
		while (pR != 0) {
			std::cout << "\n=-=-=-=\nGenerate again(1/0)?: ";
			std::cin >> pR;
			if (pR == 1) {
				s = passGen(diff, len);
				passOut(r, s);
			}
		}
	return s;
}

void passSave(std::string r, std::string s){
	int a = 0;
	std::cout << "\nSave to a txt file?(1/0): ";
	std::cin >> a;
	if(a == 1){
		std::cout << "Saving..\n";
		std::ofstream file("passwords.txt", std::fstream::app);
		file << r << ": " << s << "\n";
		std::cout<< r << ": " << s << "\n";
		std::cout << "Saved!";
		file.close();
	}
}

int main() {
	srand(time(0));
	std::string r, s;
	int diff, len = 0;

	std::cout << "Welcome to the PWD Gen\n";
		std::cout << "Password purpose: ";
			std::cin >> r;

		std::cout << "1 Simple > 2 Complicated > 3 Impossible: ";
			std::cin >> diff;

		std::cout << "Length: ";
			std::cin >> len;

	s = passGen(diff,len);
	passOut(r, s);
	s = passRedo(diff, len, r, s);
	passSave(r,s);
}
