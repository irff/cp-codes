#include <cstdio>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<double, double> pdd;
typedef pair<pdd, int> pddi;
priority_queue< greater<pddi>(),vector<pddi> > q;

int n, lubang;
int main() {
    scanf("%d%d", &n, &lubang);
    for(int i=0; i<n; i++) {
        int num; scanf("%d", &num);
        q.push( pddi(pdd((double)num,(double)num),1) );
    }
    lubang-=n;
    for(int i=0; i<lubang; i++) {
        pddi t = q.top();
        t.first.first = (double) (t.first.second/++t.second);
        q.pop(); q.push(t);
    }
    printf("%.2f\n", q.top().first.first);
    return 0;
}
