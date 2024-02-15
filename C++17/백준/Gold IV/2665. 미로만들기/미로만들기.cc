#include<iostream>
#include<climits>
using namespace std;
int N;
int map[50][50];
int dp[50][50];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };
bool visited[50][50] = { false , };
pair<int, int> findMin(bool(&visited)[50][50])
{
    int min = INT_MAX;
    pair<int, int> p;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && dp[i][j] < min)
            {
                min = dp[i][j];
                p.first = i;
                p.second = j;
            }
        }
    }
    return p;
}
void dijkstra(bool(&visited)[50][50])
{
    for (int i = 0; i < N * N; i++)
    {

        auto p = findMin(visited);
        visited[p.first][p.second] = true;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = p.second + dx[dir];
            int ny = p.first + dy[dir];
            if (nx > -1 && nx < N && ny > -1 && ny < N)
            {
                dp[ny][nx] = min(dp[ny][nx], dp[p.first][p.second] + map[ny][nx]);
            }
        }
    }
}
int main()
{
	cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
  
            map[i][j] = (s[j] == '1') ? 1 : 2500;
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = map[0][0];
    dijkstra(visited);
    cout << dp[N - 1][N - 1] / 2500 << "\n";
}