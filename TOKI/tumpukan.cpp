#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef deque<int> DI;

int teskes, n;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        DI d;
        R(i,0,n) d.push_back(i+1);
        while(d.size() > 1) {
            printf("%d ", d.front());
            d.pop_front();
            int x = d.front();
            d.pop_front();
            d.push_back(x);
        }
        printf("\n");
        printf("%d\n", d.front());
    }

    return 0;
}
