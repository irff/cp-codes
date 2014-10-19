#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;

int orang, budget, hotel, weeks;
int main() {
    while( scanf("%d%d%d%d", &orang, &budget, &hotel, &weeks) > 0) {
        int price = INF;
        R(i,0,hotel) {
            int a, b, maks = 0;
            scanf("%d", &a);
            R(j,0,weeks) {
                scanf("%d", &b);
                maks = max(maks, b);
            }
            if(maks >= orang) price = min(price, a);
        }
        if(price == INF or price*orang > budget) printf("stay home\n");
        else printf("%d\n", price*orang);
    }
    return 0;
}
