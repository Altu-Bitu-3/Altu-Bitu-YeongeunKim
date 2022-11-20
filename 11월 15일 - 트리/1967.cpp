#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//https://www.acmicpc.net/board/view/82080 100%에서 틀렸습니다 떠서 참조

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e9;

//한 점에서 모든 점까지의 거리를 구하기 위한 다익스트라
vector<int> dijkstra(vector<vector<ci>> &graph, int start, int v) {
	priority_queue<ci, vector<ci>, greater<>> pq;
	vector<int> dist(v + 1, INF);
	dist[start] = 0;

	pq.push({ 0, start });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (weight > dist[node]) continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_weight = weight + graph[node][i].second;

			if (dist[next_node] > next_weight) {
				dist[next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}
		}
	}

	//다익스트라를 모두 돌고 나서, start 지점에서 가장 거리가 먼 노드와 그 때의 거리를 구해줌
	int point = 0;
	int pp;
	for (int i = 1; i <= v; i++) {
		if (dist[i] > point) {
			pp = i;
			point = dist[i];
		}
	}

	//point는 첫번째로 선택하는 노드(다음 다익스트라 때 start)
	//pp는 최종 지름을 출력하기 위해 반환
	return { point, pp };
}

int main() {
	int n;
	cin >> n;

	//n이 1이면 원이 불가하므로 0 출력 후 종료
	if (n == 1) {
		cout << 0;
		return 0;
	}
	int node = n;
	vector<vector<ci>> graph(n + 1, vector<ci>(0));
	n--;
	//그래프 입력
	while (n--) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
		graph[b].push_back({ a, w });
	}
	
	//처음 다익스트라를 돌며 루트에서 가장 먼 노드를 찾아줌
	vector<int> first = dijkstra(graph, 1, node);

	//이후 첫번째 시행에서 찾은 노드에서 가장 먼 노드를 찾아서 그 거리를 출력
	cout << dijkstra(graph, first[1], node)[0];

	return 0;
}