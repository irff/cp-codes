#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
char s[1000111];
int main() {
    while(scanf("%s", &s) > 0) {
        if(strcmp(s,".")==0) break;
        int len = strlen(s);
        bool jadi = 0;
        R(i,1,len+1) {
            if(len%i==0) {
                bool bisa = 1;
                //printf("%d\n", i);
                for(int k=0,j=0; k<len; k++, j=(j+1)%i) {
                    //printf("%d %d\n", k, j);
                    if(s[k]!=s[j]) { bisa = 0; break; }
                }
                if(bisa) {
                    jadi = 1;
                    printf("%d\n", len/i);
                    break;
                }
            }
        }
    }
    return 0;
}
