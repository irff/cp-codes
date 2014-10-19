#include <cstdio>

int memo[500], n,sisa,dapet,hasil=0;
int main() {
    for(int i=1; i<=200; i++) {
        int x=i;    
        dapet=x;
        while(x>=3) {
            sisa=x%3;
            x/=3;
            dapet+=x;
            x+=sisa;
        }
        memo[dapet]=i;
    }
    int last;
    for(int i=299; i>0; i--) {
        if(memo[i]!=0) last=memo[i];
        else memo[i]=last;
    }
    scanf("%d", &n);
    hasil+=(n/300)*200;
    if(n>=300 and n%300==0) n=1;
    hasil+=memo[n%300];
    printf("%d\n", hasil);
    return 0;
}
