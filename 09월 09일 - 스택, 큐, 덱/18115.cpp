#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;
	vector<long long int> arr(n+1);  //��� ������ ���� ���� ����
	deque<long long int> q;  //���� ��� ���� ������ ��

	//���Ϳ� �ԷµǴ� ����� ��ȣ �������� ����
	for (int i = n; i >= 1; i--) {
		cin >> k;
		arr[i] = k;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {  //��� ��ȣ�� 1�̸� ���� �տ� �ε��� ���� ����
			q.push_front(i);
			continue;
		}
		if (arr[i] == 2) {  //��� ��ȣ�� 2�� �տ��� �ι�°�� �ε��� �� ����
			long long int tmp = q.front();
			q.pop_front();  //�ε����� ���� �Ұ��ϹǷ� ���� �տ� ���� �����صξ��ٰ� ����
			q.push_front(i);
			q.push_front(tmp);  //���� �ε��� ���� �ְ� �� �տ� �����ߴ� ���� ����
			continue;
		}
		if (arr[i] == 3) {  //��� ��ȣ�� 3�̸� ���� �ڿ� �ε��� �� ����
			q.push_back(i);
			continue;
		}
	}

	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop_front();
	}

	return 0;
}