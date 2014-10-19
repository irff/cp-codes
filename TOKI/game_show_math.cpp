#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, target, a[200];
int ans[200];
bool nemu = 0,vis[102][65000];
void rek(int ke, int now) {
    if(ke>=n) {
        if(now==target) {
            nemu = 1;
        }
    } else {
        if(nemu or vis[ke][now+32000]) return ;
        vis[ke][now+32000] = 1;
        
        if(!nemu and now-a[ke] >= -32000 and now-a[ke] <= 32000) ans[ke] = 0,rek(ke+1, now-a[ke]);
        
        if(!nemu and now+a[ke] >= -32000 and now+a[ke] <= 32000) ans[ke] = 1,rek(ke+1, now+a[ke]);
        
        if(!nemu and now*a[ke] >= -32000 and now*a[ke] <= 32000) ans[ke] = 2,rek(ke+1, now*a[ke]);
        
        if(!nemu and now%a[ke] == 0 and now/a[ke] >= -32000 and now/a[ke] <= 32000) ans[ke] = 3,rek(ke+1, now/a[ke]);
    }
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(vis, 0, sizeof vis);
        nemu = 0;
        scanf("%d", &n);
        R(i,0,n) scanf("%d", &a[i]);
        scanf("%d", &target);
        R(i,0,n) {
            if(!nemu) rek(1,a[i]);
        }
        if(nemu) {
          R(i,0,n) {
            printf("%d", a[i]);
            if(i<n-1) {
                if(ans[i+1]==0) putchar('-');
                else if(ans[i+1]==1) putchar('+');
                else if(ans[i+1]==2) putchar('*');
                else putchar('/');
            }
          }
          printf("=%d\n", target);
        }
        else printf("NO EXPRESSION\n");
    }
    return 0;
}
