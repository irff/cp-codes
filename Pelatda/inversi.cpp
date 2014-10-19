#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

typedef pair<int,int> PII;

PII p[510];

int len, n;
char s[510][510];
int main() {
    scanf("%d%d", &len, &n);
    R(i,0,n) {
        scanf("%s", &s[i]);
        int inv = 0;
        R(j,1,len) {
            R(k,0,j) {
                if(s[i][k]>s[i][j]) inv++;
            }
        }
        p[i].first = inv; p[i].second = i;
    }
    sort(p, p+n);
    R(i,0,n) {
        printf("%s\n", s[ p[i].second ]);
    }
    return 0;
}
