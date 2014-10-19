#include <cstdio>
#include <cstring>

char s[20];
int teskes,hasil;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        hasil=1;
        scanf("%s", s);
        for(int i=0,len=strlen(s); i<len; i++) hasil*=(s[i]-'0');
        int bagus=0,jelek=0;
        printf("%d ", hasil);
        while(hasil>0) {
            int x=hasil%10;
            hasil/=10;
            if(x==4 or x%2==1) jelek++;
            else bagus++;
        }
        if(bagus>=jelek) printf("LUCKY\n");
        else printf("NO\n");
    }
    return 0;
}
