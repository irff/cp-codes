/*
    ID: irfan1
    LANG: C++
    TASK: hamming
*/

#include <cstdio>
#include <algorithm>
using namespace std;


int n, b, d, ans[1000], ans_size = 0;
int x = 0;

bool check(int num) {
    for(int i=0; i<ans_size; i++) {
        int dist = 0;
        for(int j=0; j<b; j++) {
            bool x = (num&(1<<j));
            bool y = (ans[i]&(1<<j));
            if(x^y) dist++;
        }
        if(dist < d) return 0;
        
    }
    
    return 1;
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    scanf("%d%d%d", &n, &b, &d);
    for(int i=0; i<(1<<b); i++) {
        if(check(i)) {
            ans[ans_size++]=i;
            if(ans_size==n) break;
        }
    }
    for(int i=1; i<=ans_size; i++) {
        printf("%d%c", ans[i-1],(i%10 and i!=ans_size)?' ':'\n');
    }
    return 0;
}
