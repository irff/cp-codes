#include <cstdio>
#include <cmath>
#include <cstring>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int mod(int n,int m){
	if(n<0)
		n+=(ceil(-n*1.00/m)*m);
	return n%m;
}

int N, Q;
int a[300], divi, num, kasus = 0;
LLD memo[210][30][20], ans;

LLD rek(int ke, int jum, int take) {
    if(ke>=N) {
        if(take==num and jum%divi==0) return 1;
        return 0;
    }
    if(memo[ke][jum][take]==-1) {
        LLD ans = 0;
        if(take<num) ans+=rek(ke+1, mod((jum+a[ke]),divi), take+1);
        ans+=rek(ke+1, jum, take);
        return memo[ke][jum][take] = ans;
    }
    return memo[ke][jum][take];
}

int main() {
    
    scanf("%d%d", &N, &Q);
    while(N!=0 and Q!=0) {
        kasus++;
        R(i,0,N) {
            scanf("%d", &a[i]);
        }
                printf("SET %d:\n", kasus);
        R(k,0,Q) {
            scanf("%d%d", &divi, &num);
            R(i,0,N+2) R(j,0,divi+2) R(k,0,num+2) memo[i][j][k] = -1;
            ans = rek(0,0,0);
            printf("QUERY %d: %lld\n", k+1, ans);
        }
        scanf("%d%d", &N, &Q);
    }
    return 0;
}
