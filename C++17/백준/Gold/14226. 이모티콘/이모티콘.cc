#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
int N;
vector<vector<int>> dp(1001, vector<int>(1001, -1));

queue<pair<int, int>> q;
int main()
{
	int answer = INT_MAX;
	cin >> N;
	q.push({1, 0});
	dp[1][0] = 0;
	while (!q.empty())
	{
		int num = q.front().first;
		int copy_board = q.front().second;
		q.pop();

		if (dp[num][num] == -1)
		{
			dp[num][num] = dp[num][copy_board] + 1;
			q.push({ num, num });
		}
		if (num + copy_board <= 1000 && dp[num+ copy_board][copy_board] == -1)
		{
			dp[num + copy_board][copy_board] = dp[num][copy_board] + 1;
			q.push({ num + copy_board, copy_board });
		}
		if (num >= 1 && dp[num - 1][copy_board] == -1)
		{
			dp[num - 1][copy_board] = dp[num][copy_board] + 1;
			q.push({ num - 1, copy_board });
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (dp[N][i] != -1)
			answer = min(answer, dp[N][i]);
	}
	cout << answer << endl;

}