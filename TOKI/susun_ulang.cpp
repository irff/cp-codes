#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


char s[15];
int main() {
    scanf("%s", &s);
    int len = strlen(s);
    sort(s, s+len);
    do {
        printf("%s\n", s);
    } while(next_permutation(s,s+len));

    return 0;
}
