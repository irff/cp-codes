#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,i,x,y,z,sum,pos;
int sudah[10007],a[10007][5];

int main() {
    scanf("%d",&n);
    for (i=1 ; i<=n ; i++) {
        scanf("%d%d%d",&x,&y,&z);
        if (a[x][1] == 0) {
            a[x][1] = y;
        } else {
            a[x][2] = y;
        }

        if (a[y][1] == 0) {
            a[y][1] = x;
            a[y][3] = z;
        } else {
            a[y][2] = x;
            a[y][4] = z;
        }
        sum = sum + z;
    }
    
    sudah[1] = 1;
    sudah[a[1][1]] = 1;
    pos = a[1][1];
    x = a[1][3];
    
    while ((sudah[a[pos][1]] == 0) || (sudah[a[pos][2]] == 0)) {
        if (sudah[a[pos][1]] == 0) {
            x = x + a[pos][3];
            pos = a[pos][1];
            sudah[pos] = 1;
        } else {
            x = x + a[pos][4];
            pos = a[pos][2];
            sudah[pos] = 2;
        }
    }
    
    if (a[pos][1] == 1) x = x + a[pos][3]; else x = x + a[pos][4];
    
    x = min(x,sum-x);
    printf("%d\n",x);
    //scanf("\n");
    return 0;
}
