#include<iostream>
#include<queue>
using namespace std;
typedef struct pos {
	int x;
	int y;
}pos;
int map[100][100] = { 0, };
int X, Y;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pos> q;
bool checkMap() // 치즈가 남아있으면 true 다 녹으면 false
{
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
			if (map[i][j] == 1)
				return true;
	return false;
}
int main()
{
	int beforeMAP[100][100];
	int time = 0;
	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
		{
			cin >> map[i][j];
			beforeMAP[i][j] = map[i][j];
		}
			

	while (true)
	{
		for (int i = 0; i < Y; i++)
			for (int j = 0; j < X; j++)
				beforeMAP[i][j] = map[i][j];
		queue<pos> q;
		bool visited[100][100] = { false, };
		q.push({ 0, 0 }); // x, y
		time++;
		while (!q.empty())
		{
			
			auto cur = q.front();
			q.pop();
			for (int c = 0; c < 4; c++)
			{
				int xx = cur.x + dx[c];
				int yy = cur.y + dy[c];
				if (xx > -1 && xx < X && yy > -1 && yy < Y 
					&& !visited[yy][xx])
				{
					if (map[yy][xx] == 1)
						map[yy][xx] = 0;
					else
						q.push({ xx, yy });
					visited[yy][xx] = true;
				}

			}
		}
		if (!checkMap())
			break;
	}
	int answer = 0;

	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
			if (beforeMAP[i][j] == 1)
				answer++;
	cout << time << "\n" <<answer << "\n";
}