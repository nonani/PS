//
//  main.cpp
//  2075.cpp
//
//  Created by 최진우 on 2/14/24.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> v(N*N);
    for(int i=0;i<N*N;i++)
        cin>>v[i];
    sort(v.begin(), v.end(), greater<int>());
    cout<<v[N-1]<<endl;
    return 0;
}
