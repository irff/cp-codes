#include <cstdio>
#include <cstring>

int n;
char m[300];
char sa[600],sb[600],sc[600],sd[600];
int main() {
    bool bingung=0;
    scanf("%d%s%s%s", &n,sa,sb,sc);
    for(int i = 0; i < n; i++) {
        if( m[sb[i]] == 0 ) {
            for(int j = 'A'; j <= 'Z'; j++) {
                if( m[j] == sa[i] ) bingung=1;
            }
            if( !bingung ) {
                m[sb[i]] = sa[i];
            }
        
        } else if( m[sb[i]] != sa[i] ) bingung=1;
    }
    if( bingung ) printf("Pak Dengklek bingung\n");
    else {
        for(int i=0; i<n; i++) {
            if( m[sc[i]] == 0 ) printf("?");
            else printf("%c", m[sc[i]]);
        }
        printf("\n");
    }
    return 0;
}
