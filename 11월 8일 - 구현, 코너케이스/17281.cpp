#include <iostream>  //입출력 헤더
#include <vector>  //벡터 헤더
using namespace std;  //std 라이브러리
vector<bool> visited(10, false);
vector<int> order(10); //주자 순서
/**
 * [힌트] 입력이 그렇게 크지 않네요! 모든 경우의 수를 다 해보면 될 것 같아요.
 *        3아웃이 되면 아웃 카운트와 출루한 주자들이 모두 리셋되고 새로운 이닝이 시작된다는 규칙을 잘 기억해주세요!
 */

 /* 출루한 주자들의 상태 업데이트 */
int hit(vector<bool>& state, int n) {
	int score = 0;  //점수 0으로 세팅

	for (int i = 3; i > 0; i--) {  //3루 베이스부터
		if (!state[i]) {  //i번째 베이스에 주자가 없으면
			continue;  //패스
		}
		state[i] = false; //주자가 있으면 주자 위치 이동
		if (i + n >= 4) { //홈으로 들어오는 경우
			score++;  //홈으로 들어왔으므로 1점 추가
		}
		else {  //홈으로 들어오는 경우가 아니면
			state[i + n] = true;  //해당 베이스로 주자 이동
		}
	}
	//현재 타자의 위치 설정하기
	if (n == 4) { //타자가 홈런을 날렸을 경우
		return score + 1;  //현재 타자가 홈에 들어왔기 때문에 점수 +1
	}
	//안타를 쳤을 경우
	state[n] = true;  //해당 베이스로 주자 이동
	return score;  //계산한 점수 리턴
}
/* 타순이 결정됐을 때 경기에서 얻는 점수 구하기 */
int getScore(vector<vector<int>>& inning, int n) {
	int out = 0, score = 0, cur = 0;  //아웃 카운드, 점수, 현재 이닝
	vector<bool> state(4, false);  //베이스에 진루한 상태를 저장하는 벡터
	int i = 1;  //순서를 계산하는 변수
	while (true)  //무한 루프를 돌면서
	{
		if (out == 3) { //3아웃
			cur++; //다음 이닝
			out = 0;  //아웃 카운트 초기화
			state = vector<bool>(4, false); //출루한 주자 리셋
			continue;
		}
		if (cur == n) { //이닝 종료
			break;  //무한루프 빠져 나옴
		}

		int player = order[i++]; //타석으로 나갈 주자
		i = i % 9 + 1;  //i+1번째 주자(9 넘을 경우 다시 1번 주자로)
		if (inning[cur][player] == 0) { //아웃
			out++;  //아웃카운트 추가
			continue;
		}
		score += hit(state, inning[cur][player]);  //아웃이 아니라면 점수 계산
	}
	return score;  //현재 타순으로 얻은 점수 리턴
}
/* 타순 정하기 */
void game(int cnt, int n, vector<vector<int>>& inning, int& maxScore) {
	if (cnt == 4) { //4번째 타자는 1로 고정
		game(cnt + 1, n, inning, maxScore);  //다음 순서 정하기
	}
	else if (cnt == 10) { //9명의 타자 순서 정해진 경우
		int score = getScore(inning, n);  //해당 순서의 점수 계산
		if (score > maxScore) {  //만약 점수가 현재 최고 점수보다 높으면
			maxScore = score;  //점수 갱신
		}
	}
	else {  //순서가 아직 안 정해진 경우
		for (int i = 2; i <= 9; i++) {  //2번 선수부터 9번 선수까지
			if (visited[i]) {  //만약 해당 선수가 이미 순서에 있다면
				continue; //패스
			}
			visited[i] = true;  //아니라면 방문에 체크
			order[cnt] = i;  //순서를 정하는 배열에 추가
			game(cnt + 1, n, inning, maxScore);  //다시 다음 순서 정하기
			visited[i] = false;  //해당 경우의 수를 다 탐색하고 나서 다시 방문 배열 원래대로
		}
	}
}
int main() {
	int n; cin >> n; //이닝 횟수
	int score, maxScore = 0;  //초기 변수 설정
	vector<vector<int>> inning(n, vector<int>(10)); //타자들이 각 이닝에서 얻는 결과
	for (int i = 0; i < n; i++) {  //n번 이닝까지
		for (int j = 1; j <= 9; j++) {  //1번 선수부터 9번 선수까지
			cin >> inning[i][j];  //각 이닝에서 얻는 결과 저장
		}
	}
	order[4] = 1; //1번 선수는 4번 타자로 고정
	visited[1] = true;  //1번선수 자리 항상 고정

	game(1, n, inning, maxScore);  //타순 정하고 최대 점수를 구하는 함수 호출
	cout << maxScore;  //최대 점수 출력
	return 0;
}