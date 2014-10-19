#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[20];
int main() {
    scanf("%s", &s);
    int len = strlen(s);
    sort(s, s+len);
    printf("%s\n", s);
    while(next_permutation(s,s+len)) printf("%s\n", s);
}
