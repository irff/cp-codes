#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int len, n;
char s[1000];
int main() {
    scanf("%d%d", &len, &n);
    scanf("%s", &s);
    R(i,len,1000) s[i] = '\0';
    int change = 0;
    R(i,1,len) {
        if(s[i]==s[i-1]) {
            R(j,'A','A'+n) {
                if(j!=s[i-1] and j!=s[i+1]) {
                    change++;
                    s[i] = j;
                    break;
                }
            }
        }
    }
    
    R(i,0,len) {
        if(s[i]==s[i+1]) {
            R(j,'A','A'+n) {
                if(j!=s[i+1]) {
                    if(i>0 and j==s[i-1]) ;
                    else {
                        change++;
                        s[i] = j;
                        break;
                    }
                }
            }
        }
    }
    
    printf("%d\n", change);
    printf("%s\n", s);
    return 0;
}
