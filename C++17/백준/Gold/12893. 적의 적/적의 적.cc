//
//  main.cpp
//  12893
//
//  Created by 최진우 on 3/7/24.
//
#define MAX 2002
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
int visited[MAX] = {0, };
vector<int> graph[MAX];
int main() {
    int M;
    cin>> N;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
    {
        queue<int> q;
        if(visited[i] == 0)
        {
            q.push(i);
            visited[i] = 1; //1이면 친구 -1이면 적
            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();
                for(int next : graph[cur])
                {
                    if(visited[next] == 0)
                    {
                        visited[next] = -visited[cur];
                        q.push(next);
                    }
                    else{
                        if(visited[next] == visited[cur])
                        {
                            cout<<0<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<1<<endl;
    return 0;
}
