//
//  main.cpp
//  3078
//
//  Created by 최진우 on 3/4/24.
//

#include <iostream>
#include<vector>
#include <map>
using namespace std;
int front, rear;
int len[22]= {0, };
int q[300010] = {0, };
long long int answer=0;
int N, K;
int main() {
    
    cin>>N>>K;
    front = rear = 1;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        q[rear] = s.size();
        if(rear - front > K)
        {
            len[q[front++]]-=1;
        }
        rear++;
        answer+=len[s.size()]++;
    }
    cout<<answer<<endl;
    return 0;
}
