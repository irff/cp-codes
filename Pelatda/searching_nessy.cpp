#include <cstdio>
#include <algorithm>
using namespace std;

int teskes, bar, kol;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &bar, &kol);
        bar-=2, kol-=2;
        int now = (bar/3) * (kol/3);
        if(bar%3) now+=(kol+2)/3;
        if(kol%3) now+=(bar+2)/3;
        if(bar%3 and kol%3) now-=1;
        printf("%d\n", now);
    }
    return 0;
}
