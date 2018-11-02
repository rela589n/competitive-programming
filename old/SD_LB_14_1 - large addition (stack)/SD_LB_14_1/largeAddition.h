#pragma once
#include "stack_container.cpp"
#include <string>
using namespace std;


string largeAdd(string a, string b);
stack_container<int> createNumberStackFromStr(string num);
void additionAppendStack(int& excess, stack_container<int>& what, stack_container<int>& where);
int getIntFromChar(char sym);
char getCharFromInt(int num);

string largeAdd(string a, string b) {
	stack_container<int> stackA = createNumberStackFromStr(a), 
						 stackB = createNumberStackFromStr(b),
						 stackC;
	int tmp = 0;

	while ( !(stackA.empty() || stackB.empty()) ) {
		int a = stackA.top();
		int b = stackB.top();

		stackC.push( (a + b + tmp) % 10);
		tmp = (a + b + tmp) / 10;

		stackA.pop();
		stackB.pop();
	}

	additionAppendStack(tmp, stackA, stackC);
	additionAppendStack(tmp, stackB, stackC);

	if (tmp) {
		stackC.push(tmp);
	}

	string res = "";
	while( !stackC.empty() ) {
		res += getCharFromInt( stackC.top() );
		stackC.pop();
	}

	return res;

}

void additionAppendStack(int& excess, stack_container<int>& what, stack_container<int>& where) {
	while (!what.empty()) {
		int a = what.top();

		where.push((a + excess) % 10);

		excess = (a + excess) / 10;
		what.pop();
	}
}


stack_container<int> createNumberStackFromStr(string num) {
	unsigned len = num.length();
	stack_container<int> numStack;
	
	for (int i = 0; i < len; i++) {
		numStack.push( getIntFromChar(num[i]) );
	}

	return numStack;
}

int getIntFromChar(char sym) {
	return sym - '0';
}

char getCharFromInt(int num) {
	return num + '0';
}
