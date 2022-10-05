#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	priority_queue<int> gift;  //선물 상자 개수 위한 우선순위 큐

	while (n--) {
		int g;
		cin >> g;
		gift.push(g);
	}

	while (m--) {
		int c;
		cin >> c;
		if (gift.top() < c) {
			//만약 제일 많은 선물 상자 개수가
			//현재 원하는 선물보다 적으면 0 출력 후 종료
			cout << "0";
			return 0;
		}
		//선물이 충분한 경우에는 제일 많은 개수에서
		//현재 원하는 개수 빼고 다시 삽입
		gift.push(gift.top() - c);
		gift.pop();
	}

	cout << "1";

	return 0;
}