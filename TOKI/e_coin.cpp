#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 99999;

typedef struct {
    int a, b, c;
} triangle;

triangle phy[2000];

int teskes, n, target, ctr = 0;
int a[50], b[50], memo[302][302];

int change(int x, int y) {
    if(x==0 and y==0) return 0;
    if(x < 0 or y < 0) return INF;
    if(!memo[x][y]) {
        int res = INF;
        R(i,0,n) {
            res = std::min(res, change(x-a[i], y-b[i])+1);
        }
        return memo[x][y] = res;
    }
    
    return memo[x][y];
    
}

int main() {
    R(i,1,300+1) {
        R(j,0,300+1) {
            int x = sqrt(i*i-j*j);
            if(x*x+j*j==i*i) {
                phy[ctr].a = i;
                phy[ctr].b = j;
                phy[ctr].c = x;
                ctr++;
            }
        }   
    }
    //R(i,0,20) printf("%d %d %d\n", phy[i].a, phy[i].b, phy[i].c);
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &n, &target);
        R(i,0,n) {
            scanf("%d%d", &a[i], &b[i]);
        }
        int ans = INF;
        R(i,0,1020) {
            if(phy[i].a==target) {
                memset(memo, 0, sizeof memo);
                ans = std::min(ans, change(phy[i].b,phy[i].c));
            }
        }
        if(ans==INF) printf("not possible\n");
        else printf("%d\n", ans);
    }

    return 0;
}
