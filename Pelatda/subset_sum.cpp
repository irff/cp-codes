/*
    ID: irfan1
    LANG: C++
    TASK: subset
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, jumlah, ans=0;
int memo[100][1000];
int len(int x) { return x*(x+1)/2;}

int rek(int step, int sisa) {
    if(memo[step][sisa]!=-1) return memo[step][sisa]; 
    
    if(sisa==0) return memo[step][sisa]=1;
    if(sisa<0 or step > n) return memo[step][sisa]=0;
    int x = 0;
    if( len(n) - len(step+1) >= sisa ) x = rek(step+1,sisa);
    if( len(n) - len(step+1) >= (sisa-step)) x+=rek(step+1,sisa-step);
    return memo[step][sisa]=x;
}

int main() {
    memset(memo,-1,sizeof memo);
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w",stdout);
    scanf("%d", &n);
    jumlah = n*(n+1)/2;
    if(jumlah%2) printf("0\n");
    else {
        jumlah/=2;
        ans = rek(1,jumlah);
        //for(int i=0; i<50; i++) if(memo[i][0]!=-1) ans+=memo[i][0];
        printf("%d\n", ans);
    }
    return 0;
}
