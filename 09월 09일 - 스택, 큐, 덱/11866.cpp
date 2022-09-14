#include <iostream>
#include <queue>

using namespace std;


int main() {

	int n, k;
	int i = 0;
	cin >> n >> k;
	queue<int> q;

	while (n--) {
		q.push(++i); //큐에 원소들 삽입
	}
	
	cout << '<';

	while (!q.empty()) {
		for (int i = 0; i < k; i++) {
			if (i != k - 1) {
				//i가 k번째 원소가 아니라면 원형으로 생각하기 위해서
				//큐의 제일 뒤에 원소를 넣어줌
				q.push(q.front());
				q.pop();
				continue;
			}
			
			if (q.size() == 1) {
				//i가 k번째 원소이고, 큐의 제일 마지막 원소일 때
				// 출력형태를 맞추기 위해 원소와 ',' 대신 '>'를 출력해줌.
				cout << q.front() << '>';
				return 0;
			}
			//그 외의 경우에는 원소와 ','를 출력
			cout << q.front() << ", ";
			q.pop();
		}
	}


	return 0;
}