#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char ch, s[10111];;
int val[400], teskes, paid, lines;
long long ans = 0;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(val, 0, sizeof val);
        ans = 0; int counter = 0;
        scanf("%d", &paid);
        char chi,cha;
        int num;
        R(i,0,paid) {
            scanf("%c%c%c%d", &cha, &chi, &cha, &num);
            val[chi] = num;
        }
        scanf("%d\n", &lines);
        R(i,0,lines) {
            gets(s);
            //printf("%s\n", s);
            int len = strlen(s);
            R(j,0,len) {
                ans+=val[s[j]];
            }
        }
        printf("%.2lf$\n", (double)ans/100);
    }
    return 0;
}
