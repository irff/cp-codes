#include <cstdio>
#include <bitset>
using namespace std;

const int MAX=1000000;

bitset<1000000> bs;
int n;

void goldbach(int n){
    for(int i=2; i*2<=n; i++)
     if(!bs[i] and !bs[n-i]) printf("%d %d\n", i,n-i);
}

int main(){
    // the sieve
    bs.set(); bs[0]=0; bs[1]=0;
    for(int i=2;i*i<=MAX;i++) for(int j=i*i;j<=MAX; j+=i) bs[j]=0;
    
    // checking . . .
    while(scanf("%d", &n)>0) goldbach(n);
    
    return 0;
}
