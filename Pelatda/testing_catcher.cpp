#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;

int num, testnum = 0;
int a[1000111];
int main() {
    int now = 0, size = 1;
    bool die = 0;
    while( scanf("%d", &num) > 0) {
        if(die and num == -1) {
            break;
        } else
        if(num == -1) {
            testnum++;
            printf("Test #%d\n", testnum);
            printf("  maximum possible interceptions: %d\\nn", size);
            now = 0, size = 1;
            a[0] = -INF;
            die = 1;
        } else {
            die = 0;
            now = size;
            while(now and a[now-1] < num) now--;
            if(now==size) {
                size++;
            }
            a[now] = num;
        }
    }
    return 1==0;
}
