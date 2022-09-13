#include <iostream>
#include <stack>
#include <string>

using namespace std;

int isStable(string s) {
	stack<char> st;
	int sum = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			return -1;
		}

		//여는 괄호를 만나면 무조건 스택에 넣어준다.
		if (s[i] == '{') {
			st.push(s[i]);
			continue;
		}

		//닫는 괄호를 만났는데 스택이 비어있다면 정답 값을 더 해주고
		//닫는 괄호를 여는 괄호로 바꾼다고 가정해 여는 괄호를 스택에 넣어준다.
		if (s[i] == '}' && st.empty()) {
			sum++;
			st.push('{');
			continue;
		}

		//닫는 괄호이고 스택에 여는 괄호가 있다면 스택에 있던 여는 괄호를 pop
		if (s[i] == '}' && !st.empty()) {
			st.pop();
			continue;
		}
	}

	//모든 입력이 끝나고 스택이 비어 있지 않다면 그만큼 여는 괄호가 남기 때문에
	//남는 여는 괄호의 반을 닫는 괄호로 바꿔준다. 따라서 '전체 스택 크기/2'를 정답 값에 더한다.
	if (!st.empty()) {
		sum += st.size() / 2;
	}

	return sum;
}

int main() {
	string s;
	int n = 1;

	while (getline(cin, s)) {
		if (isStable(s) == -1) {
			break;
		}
		cout << n++ << ". " << isStable(s) << '\n';
	}

	return 0;
}