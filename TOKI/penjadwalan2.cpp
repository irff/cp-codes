#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef struct {
    int x, y;
} data;

long long ans = 0;

int n;
data m[200111];

bool cp(data a, data b) {
    if(a.y == b.y) return a.x > b.x;
    return a.y > b.y;
}
priority_queue<int> q;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d%d", &m[i].x, &m[i].y);
    }
    sort(m, m+n, cp);
    int now = 0;
    RV(i,50000,1) {
        while(m[now].y==i) q.push(m[now].x), now++;
        if(!q.empty()) {
            ans+=q.top();
            q.pop();
        }
    }
    printf("%lld\n", ans);
    return 0;
}
