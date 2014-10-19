#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> II;

map<II,int> m;
int n;
int main() {
    scanf("%d", &n);
    while(n!=0) {
        m.clear();
        R(i,0,n) {
            int a,b;
            scanf("%d%d", &a, &b);
            if(m[II(b,a)]>0) {
                m[II(b,a)]--;
            } else {
                m[II(a,b)]++;
            }
        }
        bool jadi = 1;
        for(map<II,int>::iterator it=m.begin(); it!=m.end(); it++) {
            //printf("%d %d - %d\n", it->first.first, it->first.second, it->second);
            if(it->second > 0) {
                jadi = 0;
                break;
            }
        }
        printf("%s\n", (jadi)?"YES":"NO");
        scanf("%d", &n);
    }
    return 0;
}
