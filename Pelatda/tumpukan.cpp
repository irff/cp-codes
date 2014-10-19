#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;
int teskes, n;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) q.push(i);
        while(q.size() > 1) {
            printf("%d%c", q.front(),q.size()==2?'\n':' ');
            q.pop();
            q.push( q.front() );
            q.pop();
        }
        printf("%d\n", q.front());
        q.pop();
    }

    return 0;
}
