//
//  main.cpp
//  2141
//
//  Created by 최진우 on 3/1/24.
//

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<pair<int, int>> v;
int main() {
    cin>>N;
    long long int total = 0;
    for(int i=0;i<N;i++)
    {
        int x, a;
        cin>>x>>a;
        v.push_back({x, a});
        total+=a;
    }
    sort(v.begin(), v.end());
    
    long long int sum = 0;
    for(int i=0;i<N;i++)
    {
        sum+=v[i].second;
        total-=v[i].second;
        if(sum >= total)
        {
            cout<<v[i].first<<endl;
            return 0;
        }
    }
    return 0;
}
