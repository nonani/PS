#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> cost(10001, 0);
vector<vector<int>> arr(10001);
int dp[10001] = {0, };
queue<int> q;

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> cost[i];
    int num;
    cin >> num;

    for (int j = 0; j < num; j++) {
      int tmp;
      cin >> tmp;
      arr[i].push_back(tmp - 1);
    }
  }

  for (int i = 0; i < N; i++) {
    if (arr[i].empty()) {
      q.push(i);
      dp[i] = cost[i];
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i = 0; i < N; i++) {
      if (i == cur) continue;

      auto it = find(arr[i].begin(), arr[i].end(), cur);
      if (it != arr[i].end()) {
        arr[i].erase(it);
        dp[i] = max(dp[i], dp[cur] + cost[i]);
        if (arr[i].empty()) {
          q.push(i);
        }
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < N; i++) {
    answer = max(answer, dp[i]);
  }

  cout << answer << endl;
  return 0;
}
