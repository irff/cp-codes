#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int teskes, len;
int memo[100][100];
char s[100];

int rek(int ki, int ka) {
    if(memo[ki][ka]==0) {
      if(ki > ka) return 0;
      if(ki==ka) return memo[ki][ka]=1;
      if(s[ki]==s[ka]) return memo[ki][ka]=2+rek(ki+1,ka-1);
      return memo[ki][ka]=max( rek(ki,ka-1), rek(ki+1, ka) );
    }
    return memo[ki][ka];
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(memo, 0, sizeof memo);
        scanf("%s", &s);
        len = strlen(s);
        int hasil = rek(0, len-1);
        printf("%d\n", hasil);
    }
    return 0;
}
