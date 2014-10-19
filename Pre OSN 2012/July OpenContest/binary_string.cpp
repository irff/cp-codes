#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m, k, len, ans = 0;
char s[120], sa[15];
int main() {
    scanf("%d%d", &m, &k);
    scanf("%s", &s);
    
    len = strlen(s);
    
    for(int i=m-1; i>=0; i--) {
        if(i >= m-k) sa[i]='1';
        else sa[i]='0';
    }
    
    do {
      bool jadi = 1;
      for(int i=0; i<len; i+=m) {
        for(int j=i, k=0; j<i+m and j<len; j++,k++) {
            if(s[j]==sa[k] or s[j]=='?') {
                //diem
            } else {
                jadi = 0;
            }
        }
      }
      
      if(jadi) {
          ans++;
      }
      
    } while(next_permutation(sa, sa+m) );
    
    printf("%d\n", ans);
    
    return 0;
}
