#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

struct board { int mat[20][20]; };
int n,hasil=0;

board m;

void rek(int bar, board mm) {
    if(bar == n-1) {
        int x=hasil;
        R(i,0,n) if(mm.mat[bar][i]==0) hasil++;
        if(hasil!=x) {
            R(i,0,n) { R(j,0,n) printf("%d", mm.mat[i][j]); printf("\n"); }
            printf("\n");
        }
        return ;
    } else {
    R(i,0,n) {
        if(mm.mat[bar][i]==0) {
            board m=mm;
            //========================LASER AREA============================
            R(j,0,n) m.mat[bar][j]=1;
            R(j,bar,n) m.mat[j][i]=1;
            R(j,0,n) if(bar+j<n and i+j<n) m.mat[bar+j][i+j]=1;
            R(j,0,n) if(bar+j<n and i-j>=0) m.mat[bar+j][i-j]=1;
            m.mat[bar][i]=9;
            //==============================================================
            //R(i,0,n) { R(j,0,n) printf("%d", m[i][j]); printf("\n"); }
            //printf("\n");
            rek(bar+1,m);
        }
    }
    }
}

int main() {
    scanf("%d", &n);
    rek(0,m);
    printf("%d\n", hasil);
    return 0;
}
