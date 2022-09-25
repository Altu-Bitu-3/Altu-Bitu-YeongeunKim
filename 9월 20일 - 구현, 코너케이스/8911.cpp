#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setState(vector<pair<int, int>>& state) {
	//0���� ���� �ϵ�����
	//���� ��� ������ ���ϰ� �ִٸ� y��ǥ�� 1�����ϹǷ� second�� 1�� ����
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
	//���� �������� ������ ��
	pair<int, int> left;
	left.first = 0;
	left.second = 0;

	//������ �������� ������ �� 
	pair<int, int> right;
	right.first = 0;
	right.second = 0;

	//���� ��ġ ��ǥ
	pair<int, int> now;
	now.first = 0;
	now.second = 0;

	//���� ��� ������ ���ϰ� �ִ��� �Ǵ��� �迭
	vector<pair<int, int>> state(4);
	setState(state);

	int index = 0;

	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case 'F':
			//������ ���� ��ɿ��� 1�� ���ؼ� ������.
			now.first += 1 * state[index].first;
			now.second += 1 * state[index].second;
			break;
		case 'B':
			//�ڷ� ���� ����� -1�� ���ؼ� ������
			now.first += -1 * state[index].first;
			now.second += -1 * state[index].second;
			break;
		//ȸ���� ���� ���� ���� �ٲٴ� �ε��� �� ����
		case 'L':
			index = (index + 3) % 4;
			break;
		case 'R':
			index = (index + 1) % 4;
			break;
		}
		//�� �������� �� ������Ʈ
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