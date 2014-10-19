#include <cstdio>

int norang,npass,pass=0;
int a[1000111],sisa;
int main() {
    scanf("%d%d", &norang,&npass);
    sisa=norang;
    int i=0;
    for(i=0; ;) {
        if(sisa==1) break;
        if(a[i]!=-1) {
            if(pass==npass) {
                printf("%d\n", i+1);
                a[i]=-1;
                sisa--;
                pass=0;
                i++;
            }
            pass++;
        }
        i++,i%=norang;
    }
    for(int i=0; i<norang; i++) if(a[i]!=-1) { printf("%d\n", i+1); break; }
    return 0;
}
