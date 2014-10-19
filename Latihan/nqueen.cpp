#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef vector<short> VB;
typedef vector<VB> VBB;

VBB m;
VB tmp;
int n,hasil=0;

void rek(int bar, VBB mm) {
    if(bar == n-1) {
        R(i,0,n) { R(j,0,n) printf("%d", mm[i][j]); printf("\n"); }
        printf("\n");
        R(i,0,n) if(mm[bar][i]==0) hasil++;
        return ;
    } else {
    R(i,0,n) {
        if(mm[bar][i]==0) {
            VBB m=mm;
            //========================LASER AREA============================
            R(j,0,n) m[bar][j]=1;
            R(j,bar,n) m[j][i]=1;
            R(j,0,n) if(bar+j<n and i+j<n) m[bar+j][i+j]=1;
            R(j,0,n) if(bar+j<n and i-j>=0) m[bar+j][i-j]=1;
            m[bar][i]=9;
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
    R(i,0,n) tmp.push_back(0);
    R(i,0,n) m.push_back(tmp);
    //R(i,0,n) { R(j,0,n) printf("%d", m[i][j]); printf("\n"); }
    rek(0,m);
    printf("%d\n", hasil);
    return 0;
}
