#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
#define RV(i,_a,_b) for(int i=int(_a); i>=int(_b); i--)

typedef long long LLD;
const LLD INF = 2000111222;

int a[100][100];

int main() {
    R(i,0,3) {
        R(j,0,3) {
            scanf("%d", &a[i][j]);
        }
    }
    R(j,0,3) {
        R(i,0,3) {
            printf("%d", a[i][j]);
            if(i==2) printf("\n");
            else printf(" ");
        }
    }
    
    scanf("\n");
    return 0;
}
