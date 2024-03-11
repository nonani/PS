//
//  main.cpp
//  8983
//
//  Created by 최진우 on 3/11/24.
//

#include <iostream>
#include<vector>
using namespace std;
int M, N, L;
typedef struct pos
{
    int x;
    int y;
    bool killed;
}pos;
vector<int> v_m;
vector<pos>  v_n;
int answer = 0;
int getDist(int x, pos p)
{
    return abs(x - p.x) + p.y;
}

int main() {
    cin>>M>>N>>L;
    for(int i=0;i<M;i++)
    {
        int x;
        cin>>x;
        v_m.push_back(x);
    }
    
    for(int i=0;i<N;i++)
    {
        int x, y;
        cin>>x>>y;
        v_n.push_back({x, y, false});
    }
    
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!v_n[j].killed && getDist(v_m[i], v_n[j]) <= L)
            {
                v_n[j].killed = true;
                answer++;
            }
        }
    }
    cout<<answer<<endl;
    
    return 0;
}
