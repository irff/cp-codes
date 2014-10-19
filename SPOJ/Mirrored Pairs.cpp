#include <cstdio>
#include <cstring>
int main(){
    char s[4];
    int state=0;
    printf("Ready\n");
    while(s[0]=getchar()){
        bool m=0;
            s[1]=getchar();
            if(s[0]==' ' and s[1]==' ') break;
            if(s[0]=='p' and s[1]=='q') m=1;
            if(s[0]=='q' and s[1]=='p') m=1;
            if(s[0]=='b' and s[1]=='d') m=1;
            if(s[0]=='d' and s[1]=='b') m=1;
            if(m) printf("Mirrored pair\n");
            else printf("Ordinary pair\n");
            memset(s,0,sizeof s);
            getchar();
    }
}
