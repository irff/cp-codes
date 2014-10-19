#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define fs first
#define sc second

typedef map<int,int> MII;
typedef pair<int,int> PII;
typedef long long LLD;

int teskes;
int nplayer, nsnakes, nroll;
int warp[300], pos[1200000];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        bool win = 0;
        R(i,0,100) warp[i]=i;
        memset(pos, 0, sizeof pos);
        
        scanf("%d%d%d", &nplayer, &nsnakes, &nroll);
        R(i,0,nsnakes) {
            int da, di;
            scanf("%d%d", &da, &di);
            warp[da-1]=di-1;
        }
        R(i,0,nroll) {
            int num; scanf("%d", &num);
            if(!win) {
                int now = i%nplayer;
                pos[now]=warp[ pos[now]+num];
                if(pos[now]>=99) win = 1;
            }
        }
        R(i,0,nplayer) {
            printf("Position of player %d is %d.\n", i+1, pos[i]+1);
        }
    }
    return 0;
}












