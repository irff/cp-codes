#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<string,int> m;
string s;
int N,M,pos,udah;
bool uda;
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        cin >> s;
        m[s]=1;
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        cin >> s;
        if(m.count(s)){
            if(m[s]!=-1){
                udah++;
                if(udah>=((N+1)/2) and !uda) pos=i+1,uda=1;
                m[s]=-1;
            }
        }
    }
    
    printf("%d\n", pos);
    return 0;
}
