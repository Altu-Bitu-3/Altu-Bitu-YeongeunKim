#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> alphabet(26, 0);

	string st;
	cin >> st;
	//가장 첫 단어의 정보 저장
	for (int i = 0; i < st.length(); i++) {
		int a = int(st[i]) - 65;
		alphabet[a]++;
	}
	n--;

	//벡터 초기화 시 사용할 벡터
	vector<int> init = alphabet;
	int cnt = 0;
	string s;
	while (n--) {
		//벡터 초기상태로
		alphabet = init;
		cin >> s;

		//길이가 2 이상 차이나면 계산하지 않음
		if (abs(int(st.length() - s.length())) >= 2) continue;
		int flag = 0;
		for (int i = 0; i < s.length(); i++) {
			int a = int(s[i]) - 65;
			alphabet[a]--;
			if (alphabet[a] < 0 && flag == 1) {
				//만약 하나 이상 차이가 난다면 break
				flag++;
				break;
			}
			//제일 처음 차이날 경우에 flag 추가하고 계속
			else if (alphabet[a] < 0) flag++;
		}

		//변화된 벡터를 돌면서 1 이상인 알파벳 개수 확인
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] > 0) flag++;
		}

		//flag가 3 이상인 경우에는 비슷하지 않은 단어
		if (flag >= 3) continue;
		cnt++;
	}

	cout << cnt;

	return 0;
}