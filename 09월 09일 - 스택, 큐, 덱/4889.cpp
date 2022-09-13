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

		//���� ��ȣ�� ������ ������ ���ÿ� �־��ش�.
		if (s[i] == '{') {
			st.push(s[i]);
			continue;
		}

		//�ݴ� ��ȣ�� �����µ� ������ ����ִٸ� ���� ���� �� ���ְ�
		//�ݴ� ��ȣ�� ���� ��ȣ�� �ٲ۴ٰ� ������ ���� ��ȣ�� ���ÿ� �־��ش�.
		if (s[i] == '}' && st.empty()) {
			sum++;
			st.push('{');
			continue;
		}

		//�ݴ� ��ȣ�̰� ���ÿ� ���� ��ȣ�� �ִٸ� ���ÿ� �ִ� ���� ��ȣ�� pop
		if (s[i] == '}' && !st.empty()) {
			st.pop();
			continue;
		}
	}

	//��� �Է��� ������ ������ ��� ���� �ʴٸ� �׸�ŭ ���� ��ȣ�� ���� ������
	//���� ���� ��ȣ�� ���� �ݴ� ��ȣ�� �ٲ��ش�. ���� '��ü ���� ũ��/2'�� ���� ���� ���Ѵ�.
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