#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[1000];
int teskes;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", &s);
        int len = strlen(s);
        sort(s,s+len);
        printf("%s\n", s);
        while(next_permutation(s,s+len)) {
            printf("%s\n", s);
        }
    }
    return 0;
}
