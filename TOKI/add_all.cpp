#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

priority_queue<int> q;

int n;
int ans;
int main() {
    while(scanf("%d", &n), n) {
        ans = 0;

        R(i,0,n) {
            int num; scanf("%d", &num);
            q.push(-num);
        }
        while(q.size() > 1) {
            int a = -q.top(); q.pop();
            int b = -q.top(); q.pop();
            ans+=a+b; q.push(-(a+b));
        }
        q.pop();
        printf("%d\n", ans);      
    }

    return 0;
}
