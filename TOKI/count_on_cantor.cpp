#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
int main() {
    while(scanf("%d", &n) > 0) {
        int x = (int)ceil( (sqrt((double)8*n+1)-1) / 2);
        int y = (x*(x+1)/2);
        int sel = y-n;
        int atas = 0, bawah = 0;
        if(x%2==0) {
            atas = x-sel, bawah = sel+1;
        } else {
            atas = sel+1, bawah = x-sel;
        }
        printf("TERM %d IS %d/%d\n", n, atas, bawah);
    }
    return 0;
}
