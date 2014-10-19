#include <cstdio>
#include <cstring>

int maks,pos,len;
char s[5000];
int main() {
    scanf("%s", s);
    len=strlen(s);
    for(int i=0; i<len; i++) {
        int kiri=1,kanan=1;
        int x=(i+len-1)%len;
        printf("%d \n", x);
        while(s[ (x+len-1)%len ] == s[x] ) {
            kiri++;
            if(kiri>=len) break;
            x--;
        }
        x=i;
        while(s[(x+1)%len] == s[x]) {
            kanan++;
            if(kanan>=len) break;
            x++;
        }
        int total=(kiri+kanan)%(len+1);
        if(total>maks) {
            maks=total; pos=i;
        }
        printf("%d %d %d\n", i, kiri,kanan);
    }
    for(int i=0; i<len; i++) {
        if(pos==i) printf("*");
        printf("%c", s[i]);        
    }
    printf("\n");
    return 0;
}
