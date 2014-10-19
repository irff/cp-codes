#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

char sa[100],sb[100];
int main() {
    scanf("%s", sa);
    int lena=strlen(sa);
    for(int i=0; i<lena; i++) sb[lena-1-i]=sa[i];
    printf("f(%s) = %s + %d = %d\n", sa, sa, atoi(sb), atoi(sa)+atoi(sb));
    return 0;
}
