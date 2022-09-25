#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main() {
	string s;
	cin >> s;

	stack<char> st;
	map<char, int> m;
	m['*'] = 1, m['/'] = 1;
	m['+'] = 2, m['-'] = 2;
	m['('] = 3;  //�� �����ڵ鿡 ���� �켱���� ������ ����

	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '+': case '-': case '*': case '/':
			//�������� ��� �켱������ ���� �����ڰ� ���� ������ ���ÿ��� pop
			while (!st.empty() && m[s[i]] >= m[st.top()]) {
				cout << st.top();
				st.pop();
			}
			//�׷��� ���� ��� �ٽ� ���ÿ� ���� �־��ش�.
			st.push(s[i]);
			continue;
		case '(':
			// ���� ��ȣ�� ������ ���ÿ� �־���
			st.push(s[i]);
			continue;
		case ')':
			// �ݴ� ��ȣ�� ������ ���� ��ȣ�� ���� ������ ������ �����ڸ� ���
			while (!st.empty()) {
				if (st.top() == '(') {
					st.pop();
					break;
				}
				cout << st.top();
				st.pop();
			}
			continue;
		default:
			//�� �� ���ĺ����� ������ �ٷ� ���
			cout << s[i];
			continue;
		}
	}

	// ��� ������ ������ ���ÿ� �����ڰ� �����ִٸ� �̸� ��� pop
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}