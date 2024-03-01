#include <iostream>
#include<string>
using namespace std;
 
string map[51];
int answer=0;
int N,M,K;
 
int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>map[i];
    }
    cin>>K;
    for(int i=0;i<N;i++){
        int z=0;
        for(int j=0;j<M;j++){
            if(map[i][j]=='0') z++;
        }
        
        if(z<=K&&K%2==z%2){
            int cnt=0;
            for(int j=0;j<N;j++){
                if(map[i]==map[j]) cnt++;
            }
            answer=max(answer,cnt);
        }
    }
    cout<<answer<<"\n";
    return 0;
}
