#include <iostream>
#include <deque>

using namespace std;

void password(string s) {
	deque<char> left; //현재 커서의 왼쪽
	deque<char> right; //현재 커서의 오른쪽

	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '<': //커서를 왼쪽으로 옮기는 경우
			if (!left.empty()) {
				char tmp = left.back();
				left.pop_back();
				right.push_front(tmp);
			}
			break;
		case '>': //커서를 오른쪽으로 옮기는 경우
			if (!right.empty()) {
				char tmp = right.front();
				right.pop_front();
				left.push_back(tmp);
			}
			break;
		case '-':  //커서 앞글자를 지우는 경우
			if (!left.empty()) {
				left.pop_back();
			}
			break;
		default:
			left.push_back(s[i]);
			break;
		}
	}

	while (!left.empty()) {
		cout << left.front();
		left.pop_front();
	}
	while (!right.empty()) {
		cout << right.front();
		right.pop_front();
	}
	cout << '\n';

	return;
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		password(s); //입력 받은 후 각 케이스에 대해 연산 실행
	}

	return 0;
}