#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef unsigned long long LLU;

int len, num[1000], op[1000];
char s[1000];
int main() {
    scanf("%d", &len);
    scanf("%s", &s);
    int p = 0, q = 0;
    R(i,0,len) {
        if(i%2==0) {
            if(s[i]=='A') num[p++] = 0;
            else num[p++] = 1;
        } else {
          if(s[i] == 'I') op[q++] = 0;
          else if(s[i] == 'E') op[q++] = 1;
          else if(s[i] == 'U') op[q++] = 2;
        }
    }
    LLD result = rek(0,
    return 0;
}
