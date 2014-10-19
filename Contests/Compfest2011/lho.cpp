#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int maks,teskes;
char s[120];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        maks=0;
        scanf("%s", s);
        int len=strlen(s);
        int i=0;
        while( i < len ) {
            int hasil=0;
            int x=i;
            if(x+2 < len and s[x]=='l' and s[x+1]=='h' and s[x+2]=='o') {
                x=x+2;
                while(x < len and s[x]=='o') {
                    hasil++;
                    x++;
                }
                if(x < len and s[x]=='?') maks=max(maks,hasil);
                else hasil=0;
            }
            i++;
        }
        printf("%d\n", maks);
    }
    return 0;
}
