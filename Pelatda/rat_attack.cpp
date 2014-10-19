#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, d, rat;
int m[1030][1030];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &d);
        R(i,0,rat) {
            int x, y, num;
            scanf("%d%d%d", &x, &y, &num);
            R(j,x-d,x+d+1) {
                R(k,y-d,y+d+1) {
                    if(j>=0 and k>=0 and j<1025 and k<1025) {
                        m[j][k]+=num;
                    }
                }
            }
        }
        int posx=0,posy=0,maks=0;
        R(i,0,1025) {
          R(j,0,1025) {
              if(maks < m[i][j]) {
                  posx=i,posy=j,maks=m[i][j];
              }
          }
        }
        printf("%d %d %d\n", posx, posy, maks);
    }
    return 0;
}
