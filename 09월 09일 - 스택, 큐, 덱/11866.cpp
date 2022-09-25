#include <iostream>
#include <queue>

using namespace std;


int main() {

	int n, k;
	int i = 0;
	cin >> n >> k;
	queue<int> q;

	while (n--) {
		q.push(++i); //ť�� ���ҵ� ����
	}
	
	cout << '<';

	while (!q.empty()) {
		for (int i = 0; i < k; i++) {
			if (i != k - 1) {
				//i�� k��° ���Ұ� �ƴ϶�� �������� �����ϱ� ���ؼ�
				//ť�� ���� �ڿ� ���Ҹ� �־���
				q.push(q.front());
				q.pop();
				continue;
			}
			
			if (q.size() == 1) {
				//i�� k��° �����̰�, ť�� ���� ������ ������ ��
				// ������¸� ���߱� ���� ���ҿ� ',' ��� '>'�� �������.
				cout << q.front() << '>';
				return 0;
			}
			//�� ���� ��쿡�� ���ҿ� ','�� ���
			cout << q.front() << ", ";
			q.pop();
		}
	}


	return 0;
}