#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;  //최소힙으로 선언
	for(int i = 0; i < n * n; i++) {
		int k;
		cin >> k;
		//들어오는 값을 최소힙에 삽입해주다가
		pq.push(k);
		//힙의 크기가 n을 넘으면 제일 작은 값을 pop해서 삭제
		//힙의 크기를 n으로 유지할 수 있음
		if (pq.size() > n) {
			pq.pop();
		}
	}

	cout << pq.top();


	return 0;
}