#include <iostream>
#include <vector>

using namespace std;

int group(string s) {
	vector<bool> arr(27, false);

	for (int i = 1; i < s.length(); i++) {
		//�յ� ���ڰ� ���ٸ� ��� ����
		if (s[i - 1] == s[i]) {
			continue;
		}
		//���� �̹� ���� ���ڶ�� 0�� ����
		if (arr[s[i] - 'a']) {
			return 0;
		}
		//�յ� ���ڰ� �޶��� �� �ձ����� ���Ͱ��� true�� �ٲ���
		arr[s[i - 1] - 'a'] = true;
	}

	//�׷� �ܾ��� ��� 1����
	return 1;
}

int main() {
	int n;
	cin >> n;
	int ans = 0;

	while (n--) {
		string s;
		cin >> s;
		ans += group(s);
	}

	cout << ans;

	return 0;
}