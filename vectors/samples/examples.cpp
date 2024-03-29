﻿#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <locale>
#include <Windows.h>
#include "queue.h"

std::string Str_(std::string sentence);
int strange_Fib(int n);


int strange_Fib(int n) {
	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return 1;
	}
	std::stack<int> a1;
	int n_1;
	int n_2;
	a1.push(0);
	a1.push(1);
	for (int i = 2; i < n; i++) {
		n_1 = a1.top();
		a1.pop();
		n_2 = a1.top();
		a1.pop();
		a1.push(n_1);
		a1.push(n_1 + n_2);
	}
	return a1.top();

}

std::string Str_(std::string sentence) {
	std::stack<char> res;
	int count_of_square = 0;
	int count_of_figure = 0;
	int count_of_round = 0;
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == '(' || sentence[i] == ')' || sentence[i] == '{' || sentence[i] == '}' || sentence[i] == '[' || sentence[i] == ']') {
			res.push(sentence[i]);
		}
	}
	while (!res.empty()) {
		if (res.top() == '}') {
			count_of_figure++;
			res.pop();
			if (!res.empty()) {
				if (res.top() == '[' || res.top() == '(') {
					return "Wrong sentence";
				}
			}
			else {
				return "Wrong sentence";
			}
		}
		else if (res.top() == ')') {
			count_of_round++;
			res.pop();
			if (!res.empty()) {
				if (res.top() == '[' || res.top() == '{') {
					return "Wrong sentence";
				}
			}
			else {
				return "Wrong sentence";
			}
		}
		else if (res.top() == ']') {
			count_of_square++;
			res.pop();
			if (!res.empty()) {
				if (res.top() == '(' || res.top() == '{') {
					return "Wrong sentence";
				}
			}
			else {
				return "Wrong sentence";
			}
		}
		else if (res.top() == '(') {
			count_of_round--;
			res.pop();
		}
		else if (res.top() == '[') {
			count_of_square--;
			res.pop();
		}
		else if (res.top() == '{') {
			count_of_figure--;
			res.pop();
		}

	}
	if (count_of_square == 0 && count_of_round == 0 && count_of_figure == 0) {
		return "Correctly";
	}
	else {
		return "Wrong sentence";
	}
}

int main(int argc, char *argv) {
	why_my_console_is_broken::my_queue pr;
	pr.push(10);
	pr.push(2);
	pr.push(124);
	pr.push(-9);
	pr.push(70);
	std::cout <<"Last: " << pr.back() << " and " <<"first: " << pr.front() << std::endl;
	std::cout << "Maximum: " << pr.find_max() <<" Minimum: "<<pr.find_min()<< std::endl;
	std::cout << "Last: " << pr.back() << " and " << "first: " << pr.front() << std::endl;
	std::cout << strange_Fib(30) << std::endl;
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	//std::string user_input;
	////user_input = argv;
	//for (int i = 0; i < argc; i++) {
	//	user_input.push_back(argv[i]);
	//	std::cout << "Argument " << i << " : " << user_input[i] << std::endl;
	//	//std::cout << "\n";
	//	//std::cout << Str_(user_input) << std::endl;
	//}
	
	//std::cin >> user_input;
	//std::cout << "\n" << user_input << std::endl;
	//std::cout << Str_(user_input) << std::endl;

	return 0;
}