#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a[3][3], x[3], ans = 2000111222, sum = 0;
char s[4], str[4];
int main() {
    strcpy(s,"BCG");
    while(scanf("%d%d%d%d%d%d%d%d%d", &a[0][0],&a[0][2],&a[0][1],&a[1][0],&a[1][2],&a[1][1],&a[2][0],&a[2][2],&a[2][1]) > 0) {
        x[0]=0,x[1]=1,x[2]=2;
        sum = 0;
        ans = 2000111222;
        R(i,0,3) if(i!=0) sum+=a[i][x[0]];
        R(i,0,3) if(i!=1) sum+=a[i][x[1]];
        R(i,0,3) if(i!=2) sum+=a[i][x[2]];
        if(ans > sum) {
            ans = sum;
            str[0] = s[ x[0] ];
            str[1] = s[ x[1] ];
            str[2] = s[ x[2] ];
        }
        while(next_permutation(x,x+3)) {
            sum = 0;
            R(i,0,3) if(i!=0) sum+=a[i][x[0]];
            R(i,0,3) if(i!=1) sum+=a[i][x[1]];
            R(i,0,3) if(i!=2) sum+=a[i][x[2]];
            if(ans > sum) {
                ans = sum;
                str[0] = s[ x[0] ];
                str[1] = s[ x[1] ];
                str[2] = s[ x[2] ];
            }
        }
        printf("%s %d\n", str, ans);
    }

    return 0;
}
