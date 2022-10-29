#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h, t;
	cin >> n >> h >> t;
	priority_queue<int> giant;
	while (n--) {
		int k;
		cin >> k;
		giant.push(k);
	}

	int cnt = 0;  //뿅망치 사용 횟수
	if (giant.top() < h) {
		//한 번도 사용 안 했을 때의 최댓값이 센티보다 작으면
		//바로 출력 후 종료
		cout << "YES\n";
		cout << cnt;
		return 0;
	}

	while(t--) {
		if (giant.top() == 1) {
			//키가 1이면 break
			break;
		}
		//우선순위 큐에 가장 키가 큰 거인 키 / 2한 값을 넣어주고
		//사용횟수 + 1, 제일 큰 값은 삭제
		giant.push(giant.top() / 2);
		cnt++;
		giant.pop();
		if (giant.top() < h) {
			//만약 현재 가장 큰 값이 센티보다 작으면
			//정답 출력
			cout << "YES\n";
			cout << cnt;
			return 0;
		}
	};


	cout << "NO\n" << giant.top();

	return 0;
}