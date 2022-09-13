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
	m['('] = 3;  //각 연산자들에 대한 우선순위 맵으로 설정

	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '+': case '-': case '*': case '/':
			//연산자의 경우 우선순위가 높은 연산자가 나올 때까지 스택에서 pop
			while (!st.empty() && m[s[i]] >= m[st.top()]) {
				cout << st.top();
				st.pop();
			}
			//그렇지 않을 경우 다시 스택에 값을 넣어준다.
			st.push(s[i]);
			continue;
		case '(':
			// 여는 괄호를 만나면 스택에 넣어줌
			st.push(s[i]);
			continue;
		case ')':
			// 닫는 괄호를 만나면 여는 괄호가 나올 때까지 스택의 연산자를 출력
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
			//그 외 알파벳들은 만나면 바로 출력
			cout << s[i];
			continue;
		}
	}

	// 모든 연산이 끝나고 스택에 연산자가 남아있다면 이를 모두 pop
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}