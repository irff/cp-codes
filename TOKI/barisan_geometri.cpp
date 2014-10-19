#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
int a[300111];
double x[300111];
int nol;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d", &a[i]);
        if(a[i]==0) nol++;
    }
    if(nol==n) printf("BARISAN GEOMETRI\n");
    else if(nol==n-1) printf("MIRIP BARISAN GEOMETRI\n");
    else {}
    
    R(i,1,n) {
        x[i] = (double)a[i]/a[i-1];
    }
    bool mirip = 0;
    R(i,2,n) {
        if(x[i]!=x[i-1]) {
            mirip = 1;
            R(j,i,n) {
                a[i] = a[i+1];
            }
            break;
            n--;
        }
    }
    if(!mirip) 
    return 0;
}
