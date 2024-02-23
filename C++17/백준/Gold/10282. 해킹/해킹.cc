#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;


int dp[10005];
int n, d , start;

void dijkstra(auto graph[10001]) {
    for(int i=1;i<=n;i++)
        dp[i] = INF;
  dp[start] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    int cur_i, cur_d;
    cur_d=pq.top().first;
    cur_i = pq.top().second;
    pq.pop();

    if (dp[cur_i] < cur_d) continue;

    for (const auto& g : graph[cur_i]) {
      int next = g.first;
      int w = g.second;

      if (dp[next] > dp[cur_i] + w) {
        dp[next] = dp[cur_i] + w;
        pq.push({dp[next], next});
      }
    }
  }
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    cin >> n >> d >> start;
    vector<pair<int, int>> graph[10001];
    for (int i = 0; i < d; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[v].push_back({u, w});
    }

    dijkstra(graph);

    int answer = 0;
    int sec = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[i] != INF) {
        answer++;
        sec = max(sec, dp[i]);
      }
    }

    cout << answer << " " << sec << endl;
  }

  return 0;
}
