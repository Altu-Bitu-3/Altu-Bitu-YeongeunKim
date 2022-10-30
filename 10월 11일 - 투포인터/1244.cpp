#include <iostream>
#include <vector>

using namespace std;

void turnSwitch(int g, int s, int n, vector<int>& swit) {
	if (g == 1) {
		//남학생일 경우 배수에 해당하는 스위치를 바꿔줌
		for (int i = s; i <= n; i += s) {
			swit[i] = abs(swit[i] - 1);
		}
	}
	else {
		//여학생일 경우
		swit[s] = abs(swit[s] - 1);
		for (int i = 1; i <= n; i++) {
			//주어진 switch 범위를 벗어나면 break
			if (s - i == 0) break;
			if (s + i == n + 1) break;
			
			//대칭이 아니면 break
			if (swit[s + i] != swit[s - i]) {
				break;
			}

			//위에 해당 없으면 상태를 바꿔줌
			swit[s + i] = abs(swit[s + i] - 1);
			swit[s - i] = abs(swit[s - i] - 1);		
		}
	}

	return;
}

int main() {
	int n, m;
	cin >> n;
	vector<int> swit(n + 1);
	swit[0] = -1;
	for (int i = 1; i <= n; i++) {
		//스위치 상태 입력 받기
		cin >> swit[i];
	}

	cin >> m;
	while (m--) {
		int g, s;
		cin >> g >> s;
		//스위치 상태 변환
		turnSwitch(g, s, n, swit);
	}

	//출력
	for (int i = 1; i <= n; i++) {
		cout << swit[i] <<' ';
		if (i % 20 == 0) {
			cout << '\n';
		}
	}

	return 0;
}