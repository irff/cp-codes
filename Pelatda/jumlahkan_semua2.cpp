#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;
priority_queue<less<int>,vector<int> > q;

int n;
LLD total = 0;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        int x;
        scanf("%d", &x);
        q.push(-x);
    }
    
    while(q.size() > 1) {
        LLD a = -q.top(); q.pop();
        LLD b = -q.top(); q.pop();
        LLD c = a+b;
        total+=(c);
        q.push(-c);
    }
    printf("%lld\n", total);
    return 0;
}
