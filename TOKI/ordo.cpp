#include <cstdio>
#include <bitset>
using namespace std;

bitset<1000001> bs;
int a[1000009],teskes,n,ctr=1,ord;
int main(){
    bs.set();
    // Sieve of Irfan
    for(int i=2; i*i<=1000000; i++){
        int j=i*2;
        if(bs[i]) while(j<=1000000) bs[j]=0,j+=i;
    }
    // Prime Indexing
    for(int i=2; i<=1000000; i++) if(bs[i]) a[i]=ctr++;
    
    scanf("%d", &teskes);
    while(teskes--){
        ord=0;
        scanf("%d", &n);
        // Process
        while(a[n]) n=a[n],ord++;
        printf("%d\n", ord);
    }
    return 0;
}