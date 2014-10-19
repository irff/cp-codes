#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int ans = 2000111222;
        scanf("%d", &n);
        R(i,1,100) {
          R(j,1,100) {
              int x = n/(i*j);
              if(i*j*x == n) {
                  int area = 2*i*j+2*i*x+2*j*x;
                  ans = min(ans, area);
              }
          }
        }
        printf("%d\n", ans);
    }
    return 0;
}
