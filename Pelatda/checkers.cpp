/*
    ID: irfan1
    LANG: C++
    TASK: checker
*/
#include <cstdio>
#include <cstring>

#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, sol=0, solcol[20];
bool colok[20], diaga[40], diagb[40];

void rek(int row) {
    if(row == n) {        
        if(sol < 3) {
            R(i, 0, n) printf("%d%c", solcol[i]+1,i==n-1?'\n':' ');
        }
        
        sol++;
        return ;
    }
    R(i,0,n) {
        if(sol <  3) solcol[row]=i;
        if(colok[i] and diaga[row+i] and diagb[n-row+i]) {
            colok[i]=0; diaga[row+i]=0; diagb[n-row+i]=0;
            rek(row+1);
            colok[i]=1; diaga[row+i]=1; diagb[n-row+i]=1;
        }
    }
}

int main() {
    //freopen("checker.in", "r", stdin);
    //freopen("checker.out", "w", stdout);
    scanf("%d", &n);

    memset(colok, 1, sizeof colok);
    memset(diaga, 1, sizeof diaga);
    memset(diagb, 1, sizeof diagb);
    
    rek(0);
    printf("%d\n", sol);
    return 0;
}
