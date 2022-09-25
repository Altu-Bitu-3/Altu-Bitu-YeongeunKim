#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setState(vector<pair<int, int>>& state) {
	//0부터 각각 북동남서
	//예를 들어 북쪽을 향하고 있다면 y좌표만 1증가하므로 second만 1로 설정
	state[0].first = 0;
	state[0].second = 1;
	state[1].first = 1;
	state[1].second = 0;
	state[2].first = 0;
	state[2].second = -1;
	state[3].first = -1;
	state[3].second = 0;
}

void turtle(string s) {
	//왼쪽 꼭지점을 저장할 값
	pair<int, int> left;
	left.first = 0;
	left.second = 0;

	//오른쪽 꼭지점을 저장할 값 
	pair<int, int> right;
	right.first = 0;
	right.second = 0;

	//현재 위치 좌표
	pair<int, int> now;
	now.first = 0;
	now.second = 0;

	//현재 어느 방향을 향하고 있는지 판단할 배열
	vector<pair<int, int>> state(4);
	setState(state);

	int index = 0;

	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case 'F':
			//앞으로 가는 명령에는 1을 곱해서 더해줌.
			now.first += 1 * state[index].first;
			now.second += 1 * state[index].second;
			break;
		case 'B':
			//뒤로 가는 명령은 -1을 곱해서 더해줌
			now.first += -1 * state[index].first;
			now.second += -1 * state[index].second;
			break;
		//회전일 때는 현재 상태 바꾸는 인덱스 값 조정
		case 'L':
			index = (index + 3) % 4;
			break;
		case 'R':
			index = (index + 1) % 4;
			break;
		}
		//각 꼭지점의 값 업데이트
		left.first = min(left.first, now.first);
		left.second = min(left.second, now.second);
		right.first = max(right.first, now.first);
		right.second = max(right.second, now.second);
	}

	int h = right.second - left.second;
	int w = right.first - left.first;

	cout << h * w << '\n';

	return;
}


int main() {
	int n;
	cin >> n;
	
	while (n--) {
		string s;
		cin >> s;
		turtle(s);
	}
}