//
//  main.cpp
//  17471
//
//  Created by 최진우 on 2/27/24.
//

#include <iostream>
#include <climits>
#include <vector>

using namespace std;
int N;
int population[11];
vector<int> graph[11];
int answer = INT_MAX;
int ox[12];

void check(int x, int is_OX, bool (&visited)[12])
{
    for(int i : graph[x])
        {
            if(!visited[i] && ox[i]==is_OX)
            {
                visited[i]=true;
                check(i, is_OX, visited);
            }
        }
}
void dfs(int x)
{
    if(x == N + 1)
    {
        bool visited[12] = {false, };
        
        int first_o = -1, first_x = -1;
        int sum_o = 0, sum_x =  0;
        for(int i=1;i<=N;i++)
        {
            if(ox[i] == 1)
            {
                sum_o += population[i];
                if(first_o == -1)
                    first_o = i;
            }
            else
            {
                sum_x += population[i];
                if(first_x == -1)
                    first_x = i;
            }
        }
        if(first_o == -1 || first_x == -1)
            return;
        visited[first_o] = visited[first_x] = true;
        check(first_o, 1, visited);
        check(first_x, 0, visited);
        for(int i = 1; i<=N;i++)
        {
            if(!visited[i])
                return ;
        }
        answer = min(answer, abs(sum_o - sum_x));
        return;
    }
    dfs(x+1);
    ox[x]=1;
    dfs(x+1);
    ox[x]=0;
}
int main() {
    
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>population[i];
    for(int i=1;i<=N;i++)
    {
        int edge_num;
        cin>>edge_num;
        for(int j = 0;j < edge_num;j++)
        {
            int num;
            cin>>num;
            graph[i].push_back(num);
        }
    }
    dfs(1);
    cout<<((answer == INT_MAX) ? -1 : answer)<<endl;
    return 0;
}
