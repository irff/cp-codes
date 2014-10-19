#include <cstdio>
using namespace std;

long long fib[100],s[100],n;
int teskes;
long long f(long long x, long long y){
     if(x==1) return  0;
     if(x==2) return (y==1);
     if(y<=fib[x-1]) return f(x-1,y);
     return f(x-2,y-fib[x-1]);
}
int main(){
    fib[1]=1LL; fib[2]=1LL; s[1]=1LL; s[2]=2LL;
    for(int i=3; s[i-1]<=13000000000LL; i++) { fib[i]=fib[i-1]+fib[i-2]; s[i]=s[i-1]+fib[i]; };
    scanf("%d", &teskes);
    char C[2];
    while(teskes--){
        scanf(" %c %c %d", &C[0],&C[1],&n);
        long long k=1;
        n++;
        while(n>s[k]) k++;
        printf("%c\n", C[f(k,n-s[k-1])]);
    }

    return 0;
}
