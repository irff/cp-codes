#include <cstdio>
#include <cstring>

int a,b;
int memo[10111];
int main(){
    memset(memo,-1,sizeof memo);
    memo[1]=1;
    for(int i=2; i<=10000; i++){
        int n=i;
        int len=0;
        while(n!=0){
            if(n==1) len+=1,n=0;
            else if(n<=10000 and memo[n]!=-1) { len+=memo[n]; break; }
            else {
                if(n%2==1) n=3*n+1,len++;
                else n/=2,len++;
            }
        }
        memo[i]=len;
    }
    while(scanf("%d%d", &a,&b)>0){
        int MAX=0;
        int x=a,y=b;
        if(a>b) { int t=a; a=b; b=t; }
        for(int i=a; i<=b; i++){
           if(memo[i]>MAX) MAX=memo[i];
        }
        printf("%d %d %d\n", x, y, MAX);
    }

    return 0;
}
