#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LLD;
int teskes;
int a,b;
bitset<100005> bs;
vector<int> prim;

bool CP(int n){
    if(n==1 or n==0) return 0;
    for(vector<int>::iterator it=prim.begin(); it!=prim.end(); it++){
        if(*it!=n and n% *it==0) return 0;
    }
    return 1;
}

int main(){
    bs.set(); bs[0]=0; bs[1]=0;
    for(int i=2; i*i<=100000; i++){
        for(int j=i*i; j<=100000; j+=i) bs[j]=0;
    }
    for(int i=2; i<=100000; i++) if(bs[i]) prim.push_back(i);
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d%d", &a, &b);
        for(int i=a; i<=b; i++){
            if(CP(i)) printf("%d\n", i);
        }
        puts("");
    }
    return 0;
}
