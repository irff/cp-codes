#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int main() {
    for(int i=2; i<=40; i++) {
        queue<int> q;
        for(int j=1; j<=i; j++) q.push(j);
        while(q.size() > 1) {
            q.pop();
            q.push(q.front());
            q.pop();
        }
        printf("%d %d %d\n", i, q.front(), q.size());
    }
    return 0;
}
