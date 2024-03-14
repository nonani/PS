//
//  main.cpp
//  14395
//
//  Created by 최진우 on 3/13/24.
//

#include <iostream>
#include<queue>
#include<vector>
#define MAX 1000000001
using namespace std;
long long int S, T;
vector<bool> visited(MAX, false);
typedef struct s
{
    long long int s;
    int cnt;
    string answer;
}s;
queue<s> q;

int main() {
    cin>>S>>T;
    if(S == T)
    {
        cout<<0<<endl;
        return 0;
    }
    q.push({S, 0, ""});
    visited[S] = true;
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if(cur.s == T)
        {
            cout<<cur.answer<<endl;
            return 0;
        }
        if(cur.s * cur.s < MAX && !visited[cur.s * cur.s])
        {
            visited[cur.s * cur.s] = true;
            q.push({cur.s * cur.s, cur.cnt+1, cur.answer+"*"});
        }
        if(cur.s + cur.s < MAX && !visited[cur.s + cur.s])
        {
            visited[cur.s + cur.s] = true;
            q.push({cur.s + cur.s, cur.cnt+1, cur.answer+"+"});
        }
        if(cur.s - cur.s < MAX && !visited[cur.s - cur.s])
        {
            visited[cur.s - cur.s] = true;
            q.push({cur.s - cur.s, cur.cnt+1, cur.answer+"-"});
        }
        if(cur.s / cur.s < MAX && !visited[cur.s / cur.s])
        {
            visited[cur.s / cur.s] = true;
            q.push({cur.s / cur.s, cur.cnt+1, cur.answer+"/"});
        }
            
    }
    cout<<-1<<endl;
    return 0;
}
