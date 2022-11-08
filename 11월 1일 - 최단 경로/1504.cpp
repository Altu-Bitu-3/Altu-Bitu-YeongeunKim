#include <iostream>
#include <vector>
#include <queue>

//https://steady-coding.tistory.com/82 92%에서 실패가 떠 INF 범위 참고

using namespace std;
typedef pair<int, int> ci;
const int INF = 200000000;

//최단경로 구하기 위한 다익스트라 알고리즘
int dijkstra(int start, int n, int v, vector <vector<ci>>& graph) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> dist(n + 1, INF);
	priority_queue<ci, vector<ci>, greater<>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			//현재 노드를 거쳐 다음 정점까지 가는 경로값
			int next_weight = weight + graph[node][i].second;
			if (next_weight < dist[next_node]) {
				dist[next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}
		}
	}

	return dist[v];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, e, a, b, w;

	cin >> n >> e;
	vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접리스트
	while (e--) {
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
		graph[b].push_back({ a, w }); //방향 아닐 경우
	}

	int v1, v2;
	cin >> v1 >> v2;

	int st_to_v1 = dijkstra(1, n, v1, graph);  //1에서 v1으로 가는 경우
	int st_to_v2 = dijkstra(1, n, v2, graph);  //1에서 v2로 가는 경우
	int v1_to_v2 = dijkstra(v1, n, v2, graph);  //v1에서 v2 혹은 v2에서 v1으로 가는 경우
	int v1_to_n = dijkstra(v1, n, n, graph);  //v1에서 n으로 가는 경우
	int v2_to_n = dijkstra(v2, n, n, graph);  //v2에서 n으로 가는 경우

	//1->v1->v2->n   1->v2->v1->n 두 가지 경우의 수가 존재
	//둘 모두 계산 후, 더 작은 값을 선택
	int dis = min(st_to_v1 + v1_to_v2 + v2_to_n, st_to_v2 + v1_to_v2 + v1_to_n);

	//가는 경로가 없는 경우
	if (dis >= INF) {
		cout << "-1";
		return 0;
	}

	cout << dis;

	return 0;
}