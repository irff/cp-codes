#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, ans = 0;
stack<int> s;
int main() {
    scanf("%d", &n);
    int size = 0;
    R(i,0,n) {
        int x;
        scanf("%d", &x);
        if(s.empty()) s.push(x);
        else {
            int hapus = 0;
            while(!s.empty() and s.top() < x) {
                s.pop(); hapus++;
            }
            hapus+=s.size();
            s.push(x);
            ans+=hapus;
        }
    }
    printf("%d\n", ans);

    return 0;
}
