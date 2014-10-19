#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
int main() {
    while(scanf("%d", &n) and n) {
        int maks = -2000111222, sum = 0, num = 0;
        bool nonneg = 0;
        R(i,0,n) {
            scanf("%d", &num);
            if(num>=0) nonneg = 1;
            sum+=num;
            maks = max(maks, sum);
            if(sum < 0) sum = 0;
        }
        if(sum<=0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", maks);
    }
    return 0;
}
