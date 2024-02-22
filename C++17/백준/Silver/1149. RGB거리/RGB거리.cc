//
//  main.cpp
//  1149
//
//  Created by 최진우 on 2/22/24.
//

#include <iostream>
using namespace std;
int N;
int house[1001][3] = {0, };
int dp[1001][3] = {0, };
int main() {
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j = 0;j<3;j++)
            cin>>house[i][j];
    
    for(int i=1;i<=N;i++)
    {
        for(int j = 0;j<3;j++)
        {
            dp[i][j] = min( dp[i-1][(3+j-1)%3], dp[i-1][(3+j+1)%3]) + house[i][j];
        }
    }
    cout<<min(dp[N][0], min(dp[N][1], dp[N][2]));

    return 0;
}
