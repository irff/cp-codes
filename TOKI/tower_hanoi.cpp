#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, t, x = 0;
set<int> s[4];
bool udah = 0;
void move(int n, int a, int b, int c) {
    if(n>0) {
        move(n-1, a, c, b);
        if(udah) return ;
        if(x>=t) {
            udah = 1;
            return ;
        }

        x++;
        //printf("%d -> %d is moved from %d to %d\n", x, n, a, c);
        s[a].erase(n);
        s[c].insert(n);
        move(n-1, b, a, c);
    }
}

int main() {
    scanf("%d%d", &n, &t);
    R(i,1,n+1) s[0].insert(i);
    move(n,0,1,2);
    R(i,0,3) {
        if(s[i].empty()) printf("-\n");
        else {
            bool tamax = 0;
            for(set<int>::reverse_iterator it=s[i].rbegin(); it!=s[i].rend(); it++) {
                if(tamax) printf(" ");
                else tamax = 1;
                printf("%d", *it);
            }
            printf("\n");
        }
    }
    return 0;
}
