#include <cstdio>
using namespace std;

long long fib[11000];
int teskes, m,n;

int main(){
    fib[1]=1;
    for(int i=2; i<10002; i++) fib[i]=(fib[i-1]+fib[i-2])%10000;
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d%d", &m,&n);
        if(n==0 and m==0) printf("1\n");
		else if(n>m) printf("0\n");
        else { if(n==0) n=2; printf("%d\n", fib[m-n+1]); }
    }
    return 0;
}
