#include <cstdio>
#include <cstring>

int teskes,liter,harga,jarak,bayaran;
char s[100];

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d%d%d%s", &liter,&harga,&jarak,&bayaran,s);
        if(strcmp(s,"kabur")==0) bayaran=0;
        printf("%d\n", bayaran-(liter*harga*jarak));
    }
    return 0;
}
