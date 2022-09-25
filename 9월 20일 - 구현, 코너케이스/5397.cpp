#include <iostream>
#include <deque>

using namespace std;

void password(string s) {
	deque<char> left; //���� Ŀ���� ����
	deque<char> right; //���� Ŀ���� ������

	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '<': //Ŀ���� �������� �ű�� ���
			if (!left.empty()) {
				char tmp = left.back();
				left.pop_back();
				right.push_front(tmp);
			}
			break;
		case '>': //Ŀ���� ���������� �ű�� ���
			if (!right.empty()) {
				char tmp = right.front();
				right.pop_front();
				left.push_back(tmp);
			}
			break;
		case '-':  //Ŀ�� �ձ��ڸ� ����� ���
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
		password(s); //�Է� ���� �� �� ���̽��� ���� ���� ����
	}

	return 0;
}