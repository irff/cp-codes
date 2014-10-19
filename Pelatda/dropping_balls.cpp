#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
int teskes, dep, nowdep = 0, ball, finish = 0;
bool m[1100000];
int ans[21][600000];
void drop(int a, int step) {
    if(step>=nowdep) {
        finish = a;
        return ;
    }
    
    if(m[a]==0) {
        m[a]=1;
        drop(a*2, step+1);
    } else {
        m[a]=0;
        drop(a*2+1, step+1);
    }
}

int main() {
    R(d,2,21) {
        nowdep = d;
        R(i,1,(1<<d)/2+2) {
            drop(1,1);
            //if(d==4) printf("%d ", finish);
            ans[d][i]=finish;
        }
        
        R(i,0,(1<<d)+1) m[i]=0;
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &dep, &ball);
        int ke = ball%(1<<(dep-1));
        if(ke==0) ke = (1<<(dep-1));
        printf("%d\n", ans[dep][ke]);
    }
    scanf("%d", &teskes);
    return 0;
}
