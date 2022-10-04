#include <iostream>  //입출력 헤더
#include <vector>  //벡터 헤더

using namespace std;  //std 라이브러리

struct info { //내구도와 로봇 존재 여부
	int power;  //칸의 내구도
	bool is_on;  //로봇 존재 여부
};

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 여부)
int zero_power;     //내구도가 0인 벨트 칸의 개수

int minusPosition(int n, int pos) { //인덱스 감소
	if (--pos >= 0) {  //pos가 0보다 크면
		return pos;  //1 감소 시킨 값 리턴
	}
	return n * 2 - 1;  //아니라면 인덱스의 마지막 값인 2n - 1 리턴
}

void second(int n, int start, int end) {  //두 번째 단계에 해당하는 함수
	int cur = end;  //가장 먼저 올린 로봇부터
	while (cur != start) { //end - 1 부터 start 까지 검사
		cur = minusPosition(n, cur);  //인덱스 감소
		int next = (cur + 1) % (n * 2); //다음 위치
		if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
			belt[cur].is_on = false;  //현재 위치에서 옮기기 때문에 현재의 로봇 여부는 false로
			belt[next].power--;  //해당 위치 내구도 감소
			if (next != end) { //내리는 위치 아닐 경우만
				belt[next].is_on = true; //로봇 옮기기
			}
			if (belt[next].power == 0) {  //옮겨서 내구도가 0이 되면
				zero_power++;  //0인 칸의 개수 증가
			}
		}
	}
}

void third(int start) {  //세 번째 단계에 해당하는 함수
	if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
		belt[start].is_on = true;  //로봇의 존재 여부 true로 바꾸고
		belt[start].power--;  //해당 칸의 내구도 감소
		if (belt[start].power == 0) {  //만약 올린 후 내구도가 0이면
			zero_power++;  //0인 칸의 개수 증가
		}
	}
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 *
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 *
 * 해당 문제는 deque 자료구조를 사용해서도 구현 가능 (1번에서 회전하는 부분만 다르고 2번, 3번은 동일한 로직)
 */

int main() {
	ios_base::sync_with_stdio(false);  //버퍼 끊기
	cin.tie(NULL);  //입출력 향상

	int n, k; //칸 n과 끝낼 칸의 개수 변수 선언

	//입력
	cin >> n >> k;  //입력
	belt.assign(n * 2, { 0, false });  //내구도에 0, 로봇 존재 여부에 false로 초기화
	for (int i = 0; i < n * 2; i++) {  //0부터 2n까지
		cin >> belt[i].power; //각 칸의 내구도 입력
	}

	//연산
	int start = 0;    //올리는 위치
	int end = n - 1;  //내리는 위치
	int step = 0;     //단계 수
	while (true) {  //break 조건까지 무한 반복
		start = minusPosition(n, start);  //올리는 위치의 인덱스 계산
		end = minusPosition(n, end);  //내리는 위치의 인덱스 계산
		if (belt[end].is_on) { //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기
			belt[end].is_on = false;  //로봇 내리고 로봇 존재 여부 false로
		}
		second(n, start, end);  //2번 단계 실행
		third(start);  //3번 단계 실행
		step++;  //라운드 하나 끝났으므로 한 단계 증가
		if (zero_power >= k) {  //만약 내구도 0인 칸이 k개 이상이면
			break;  //종료
		}
	}

	//출력
	cout << step;  //단계 출력
	return 0;
}