#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int c, p, t; char dum, ch;
        scanf("%d%d%d%c%c", &c, &p, &t, &dum, &ch);
        printf("%d-%d-%d-%c\n", c, p, t, ch);
    }
    return 0;
}
