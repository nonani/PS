#include<iostream>
#include<vector>
using namespace std; 
int N;
vector<int> v(81);
bool check(vector<int> a, int word_len) //나쁜 수열이면 true 아니면 false
{
	bool flag = false;
	for (int i = 1; i <= word_len/2;i++)
	{
		flag = true;
		for (int j = 0; j < i;j++)
		{
			if (v[word_len - i - j] != v[word_len - j])
				flag = false;
		}
		if (flag)
			return true;
	}
	return false;
}
void  dfs(int depth, int x, bool& flag)
{
	v[depth] = x;
	if (!check(v, depth))
	{
		if (depth == N)
		{
			flag = true;
		}
		for (int i = 1; i <= 3 && !flag; i++)
		{
			if (x != i)
				dfs(depth + 1, i, flag);
		}
	}
}
int main()
{
	cin >> N;
	bool flag = false;
	dfs(1, 1, flag);
	for (int i = 1; i <= N; i++)
		cout << v[i];
	cout << "\n";
}