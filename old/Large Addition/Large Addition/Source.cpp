#include <iostream>
#include <string>
#include <stack>

using namespace std;
string largeAdd(string a, string b);

int main() {
	string n;

	unsigned quantity;
	cin >> quantity;
	cin.get();

	for (unsigned i = 0; i < quantity; ++i) {
		string n1, n2;

		getline(cin, n);

		unsigned plusPos = n.find("+");
		n1.append(n, 0, plusPos);
		n2.append(n, plusPos + 1, n.length() - plusPos - 1);

		cout << largeAdd(n1, n2) << endl;
	}

	system("pause");
	return 0;
}



stack<int> createNumberStackFromStr(string num);
void additionAppendStack(int& excess, stack<int>& what, stack<int>& where);
int getIntFromChar(char sym);
char getCharFromInt(int num);

string largeAdd(string a, string b) {
	stack<int> stackA = createNumberStackFromStr(a),
		stackB = createNumberStackFromStr(b),
		stackC;
	int tmp = 0;

	while (!(stackA.empty() || stackB.empty())) {
		int a = stackA.top();
		int b = stackB.top();

		stackC.push((a + b + tmp) % 10);
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
	while (!stackC.empty()) {
		res += getCharFromInt(stackC.top());
		stackC.pop();
	}

	return res;

}

void additionAppendStack(int& excess, stack<int>& what, stack<int>& where) {
	while (!what.empty()) {
		int a = what.top();

		where.push((a + excess) % 10);

		excess = (a + excess) / 10;
		what.pop();
	}
}


stack<int> createNumberStackFromStr(string num) {
	unsigned len = num.length();
	stack<int> numStack;

	for (int i = 0; i < len; i++) {
		numStack.push(getIntFromChar(num[i]));
	}

	return numStack;
}

int getIntFromChar(char sym) {
	return sym - '0';
}

char getCharFromInt(int num) {
	return num + '0';
}
