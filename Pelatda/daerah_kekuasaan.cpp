#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar, kol, ndaerah, minimal, maks = 0;
int a[100][100], teskes;
int main() {
  scanf("%d", &teskes);
  while(teskes--) {
    maks = -2000111222;
    scanf("%d%d%d%d", &bar, &kol, &ndaerah, &minimal);
    R(i,0,bar) R(j,0,kol) a[i][j] = 1;
    R(i,0,ndaerah) {
        int ia,ib,ja,jb;
        scanf("%d%d%d%d", &ia, &ib, &ja, &jb);
        ia--,ib--;
        R(j,ia,ja) R(k,ib,jb) a[j][k] = -10000;
    }

    R(i,0,bar) {
        R(j,0,kol) {
            if(i>0) { a[i][j] += a[i-1][j]; }
            if(j>0) { a[i][j] += a[i][j-1]; }
            if(i > 0 and j > 0) { a[i][j] -= a[i-1][j-1]; }
        }
    }
    /*
    R(i,0,bar) {
        R(j,0,kol) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    */
    R(i,0,bar) {
      R(j,0,kol) {
        R(k,i,bar) {
          R(l,j,kol) {
              int sum = a[k][l];
              if(i>0) sum -= a[i-1][l];
              if(j>0) sum -= a[k][j-1];
              if(i>0 and j>0) sum += a[i-1][j-1];
              maks = max(sum, maks);
          }
        }
      }
    }
    if(maks >= minimal) {
        printf("YA\n");
    } else {
        printf("TIDAK\n");
    }
  }
    return 0;
}
