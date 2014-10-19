#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, m[1020][1020], ki[1020][1020],ka[1020][1020];
bool la[1020][1020], li[1020][1020];
bool arah[2040];
int main() {
    scanf("%d", &n);
    R(i,0,n) R(j,0,n) {
             scanf("%d", &m[i][j]);
             int n = m[i][j];
             while(n%2==0) ki[i][j]++,n/=2;
             while(n%5==0) ka[i][j]++,n/=5;        
    }
    /*R(i,0,n) {
        R(j,0,n) printf("%d ", ki[i][j]);
        printf("\n");
    }
    printf("\n");
    R(i,0,n) {
        R(j,0,n) printf("%d ", ka[i][j]);
        printf("\n");
    }*/
    R(i,0,n) {
        R(j,0,n) {
            if(i==0 and j!=0) { li[i][j] = 1; la[i][j] = 1; ki[0][j] += ki[0][j-1]; ka[0][j] += ka[0][j-1]; }
            else if(i!=0 and j==0) { li[i][j] = 0; la[i][j] = 0; ki[i][0] += ki[i-1][0]; ka[i][0] += ka[i-1][0]; }
            else if(i!=0 and j!=0) {
                 if( ki[i-1][j] <= ki[i][j-1]) {
                     ki[i][j] = ki[i][j]+ki[i-1][j], li[i][j]=0;
                 } else ki[i][j] = ki[i][j]+ki[i][j-1], li[i][j]=1;
                 
                 if( ka[i-1][j] <= ka[i][j-1]) {
                     ka[i][j] = ka[i][j]+ka[i-1][j],la[i][j]=0;
                 } else ka[i][j] = ka[i][j]+ka[i][j-1],la[i][j]=1;
            }
        }
    }
    bool kiri = 1;
    //R(i,0,n) { R(j,0,n) printf("%d ", ki[i][j]); printf("\n"); }
    //printf("\n");
    //R(i,0,n) { R(j,0,n) printf("%d ", ka[i][j]); printf("\n"); }
    //printf("\n");
    //R(i,0,n) { R(j,0,n) printf("%d ", li[i][j]); printf("\n"); }
    //printf("\n");
    //R(i,0,n) { R(j,0,n) printf("%d ", la[i][j]); printf("\n"); }
    //printf("\n");
    //printf("%d %d\n", ki[n-1][n-1], ka[n-1][n-1]);
    if(ka[n-1][n-1] < ki[n-1][n-1]) { kiri = 0; }
    int mins = min(ka[n-1][n-1], ki[n-1][n-1]);
    printf("%d\n", mins);
    int a=n-1, b=n-1;
    int ctr=0;
    while( a>=0 and b>=0) {
        if(kiri) {
            if(li[a][b]) {
                arah[ctr++]=1; b--;
            } else {
                arah[ctr++]=0; a--;
            }
        } else {
            if(la[a][b]) {
                arah[ctr++]=1; b--;
            } else {
                arah[ctr++]=0; a--;
            }
        }
    }
    //printf("kiri? %d\n", kiri);
    for(int i=ctr-2; i>=0; i--) printf("%c", arah[i]?'R':'D');
    printf("\n");
    //R(i,0,n) { R(j,0,n) printf("%d ", ka[i][j]); printf("\n"); }      
    return 0;
}
