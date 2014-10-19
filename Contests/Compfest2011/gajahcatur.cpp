#include <cstdio>
#include <algorithm>
using std::max;
#define R(i,_a,_b) for(int i=int(_a),c=int(_b); i<c; i++)

int maks,teskes,bar,kol,m[1200][1200];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        maks=0;
        scanf("%d%d", &bar, &kol);
        
        R(i,0,bar) R(j,0,kol) scanf("%d", &m[i][j]);
        R(i,0,bar) {
          R(j,0,kol) {
            int hasil=0;
            // kiri atas
            int xi=i-1,xj=j-1;
            while(xi >=0 and xj >= 0) hasil+=m[xi--][xj--];
            // kanan atas
            xi=i-1,xj=j+1;
            while(xi >=0 and xj < kol) hasil+=m[xi--][xj++];
            // kanan bawah
            xi=i+1,xj=j+1;
            while(xi < bar and xj < kol) hasil+=m[xi++][xj++];
            // kiri bawah
            xi=i+1,xj=j-1;
            while(xi < bar and xj >=0) hasil+=m[xi++][xj--];
            
            maks=max(maks,hasil);
          }
        }
        printf("%d\n", maks);
    }
    return 0;
}
