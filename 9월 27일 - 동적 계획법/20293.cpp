#include <iostream>
#include <queue>

using namespace std;

//참고 사이트 https://www.acmicpc.net/board/view/67084
//m의 카운트를 틀리고 있어서 백준사이트의 질문 부분을 참고했습니다.

void dodo(deque<int> &d, deque<int> &su, deque<int> &d_gr, deque<int> &su_gr) {
	if (!d_gr.empty() && d_gr.front() == 5) {  //만약 도도의 그라운드 패가 5이면 도도 승
		while (!su_gr.empty()) {
			d.push_back(su_gr.back());
			su_gr.pop_back();
		}//수연의 패를 도도의 덱에 삽입 후,
		while (!d_gr.empty()) {
			d.push_back(d_gr.back());
			d_gr.pop_back();
		}
		//도도의 패도 덱 뒤에 삽입
	}

	//도도가 냈는데 수연이 이길 경우
	if (!su_gr.empty() && !d_gr.empty() && d_gr.front() + su_gr.front() == 5) {
		while (!d_gr.empty()) {
			su.push_back(d_gr.back());
			d_gr.pop_back();
		}//도도의 패를 수연의 덱에 삽입 후
		while (!su_gr.empty()) {
			su.push_back(su_gr.back());
			su_gr.pop_back();
		}
		//수연의 패도 삽입
	}

	return ;
}

void suyeon(deque<int> &d, deque<int> &su, deque<int> &d_gr, deque<int> &su_gr) {
	//도도의 차례와 같은 방식으로 진행
	if (!su_gr.empty() && su_gr.front() == 5) {
		while (!su_gr.empty()) {
			d.push_back(su_gr.back());
			su_gr.pop_back();
		}
		while (!d_gr.empty()) {
			d.push_back(d_gr.back());
			d_gr.pop_back();
		}
	}

	if (!su_gr.empty() && !d_gr.empty() && d_gr.front() + su_gr.front() == 5) {
		while (!d_gr.empty()) {
			su.push_back(d_gr.back());
			d_gr.pop_back();
		}
		while (!su_gr.empty()) {
			su.push_back(su_gr.back());
			su_gr.pop_back();
		}
	}

	return ;
}


int game(deque<int> &d, deque<int> &su, int m) {
	deque<int> d_gr, su_gr;  //각각의 그라운드 패
	bool is_d = true;  //차례를 가리기 위한 변수

	for (int i = 0; i < m; i++) {
		if (is_d) {
			//도도의 차례
			d_gr.push_front(d.front());
			d.pop_front();
			if (d.empty()) {  //덱에서 그라운드로 카드를 낸 후, 덱이 비었으면 바로 수연이 승
				return 2;
			}
			dodo(d, su, d_gr, su_gr);
			is_d = false; //차례 변경
		}
		else {
			//수연의 차례
			su_gr.push_front(su.front());
			su.pop_front();
			if (su.empty()) {
				//덱에서 카드를 낸 후, 덱이 비면 도도 승
				return 1;
			}
			suyeon(d, su, d_gr, su_gr);
			is_d = true;
		}
	}

	if (d.size() > su.size()) {
		//모든 횟수가 끝나고 도도가 카드 개수가 더 많은 경우
		return 1;
	}
	else if (su.size() > d.size()) {
		//수연이 개수가 더 많은 경우
		return 2;
	}
	else {
		//둘이 비긴 경우
		return 3;
	}
}

int main() {
	int n, m;
	deque<int> su;
	deque<int> d;

	cin >> n >> m;

	while (n--) {
		int a, b;
		cin >> a >> b;
		//제일 아래의 카드부터 나오기 때문에 앞으로 삽입
		d.push_front(a);
		su.push_front(b);
	}

	int g = game(d, su, m);

	if (g == 1) {
		cout << "do";
		return 0;
	}
	if (g == 2) {
		cout << "su";
		return 0;
	}
	if (g == 3) {
		cout << "dosu";
		return 0;
	}


	return 0;
}