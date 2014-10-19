#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k;
char s[500111];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", &s);

    int maks = -1, pos = 0, m = 0;
    int ctr = 0;
    while(k != 0) {
        if(n-pos == k) {
            for(int i=pos; i<n; i++) {
                s[i] = '-';
            }
            break;
        }
        maks = -1;
        for(int i=pos; i<=pos+k; i++) {
            if(s[i]-'0'==9) {
                m = i;
                break;
            }
            if(s[i]-'0' > maks) {
                maks = s[i]-'0';
                m = i;
            }
        }
        //printf("pos = %d, maks = %d, m = %d\n", maks, m);
        for(int i=pos; i<m; i++) {
            s[i] = '-';
            k--;
        }
        pos = m+1;
    }
    
    for(int i=0; i<n; i++) {
        if(s[i]!='-') printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}
