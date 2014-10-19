#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LLD;

int teskes;
LLD pos,n,x,p[10000];
int main(){
    p[0]=0;
    for(int i=1; p[i-1]<=10000000; i++){
        p[i]=p[i-1]+i;
    }
    scanf("%lld", &teskes);
    while(teskes--){
        scanf("%lld", &n);
        for(int i=0; i<=5000; i++){
            if(p[i+1]>=n) { x=p[i]; pos=i+1;  break;}
        }
        n=n-x;
        if(pos%2==0){
            printf("%lld/", n,pos-n+1);
            printf("%lld\n", pos-n+1);
        }
        else {
            printf("%lld/", pos-n+1);
            printf("%lld\n", n);
        }
    }
    return 0;
}
