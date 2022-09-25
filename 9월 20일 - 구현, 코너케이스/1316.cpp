#include <iostream>
#include <vector>

using namespace std;

int group(string s) {
	vector<bool> arr(27, false);

	for (int i = 1; i < s.length(); i++) {
		//앞뒤 글자가 같다면 계속 진행
		if (s[i - 1] == s[i]) {
			continue;
		}
		//만약 이미 나온 글자라면 0을 리턴
		if (arr[s[i] - 'a']) {
			return 0;
		}
		//앞뒤 글자가 달라질 때 앞글자의 벡터값을 true로 바꿔줌
		arr[s[i - 1] - 'a'] = true;
	}

	//그룹 단어일 경우 1리턴
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