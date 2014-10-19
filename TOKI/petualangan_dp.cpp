#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;

const int INF = 20001111;

int jarak = 0, n = 0, ans = 0, memo[205][205];
PII war[300];

int rek(int water, int ke) {
    if(ke>=n) {
        if(water>=100) return 0;
        return INF;
    }
    if(water<0) return INF;
    
    if(memo[water][ke]==-1) {
        int mins = INF;
        R(i,0,200-water+1) {
            int ntar = rek(water+i-(war[ke+1].first-war[ke].first), ke+1);
            mins = min(mins, ntar+i*war[ke].second);
        }
        return memo[water][ke] = mins;
    }
    return memo[water][ke];
}

int main() {
    scanf("%d", &jarak);
    while(scanf("%d%d", &war[n].first, &war[n].second) > 0) {
        n++;
    }
    war[n].first = jarak, war[n].second = 0;
    sort(war, war+n);
    
    memset(memo, -1, sizeof memo);
    ans = rek(100-war[0].first,0);
    
    if(ans < INF) printf("%d\n", ans);
    else printf("Impossible\n");
    
    return 0;
}
