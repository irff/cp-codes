#include <cstdio>
#include <cstring>
#include <cstdlib>

char op[20];
int nop,num,xmaks,ymaks,xmins,ymins,horz,vert;
int main() {
    scanf("%d", &nop);
    while(nop--) {
        scanf("%s%d", op, &num);
        if(strcmp(op, "kanan")==0) {
            horz+=num;
            if(horz > xmaks) xmaks=horz;
        } else if(strcmp(op, "kiri")==0) {
            horz-=num;
            if(horz < xmins) xmins=horz;
        } else if(strcmp(op, "maju")==0) {
            vert+=num;
            if(vert > ymaks) ymaks=vert;
        } else{
            vert-=num;
            if(vert < ymins) ymins=vert;
        }
    }
    int panjang=0, lebar=0;
    if(xmaks+abs(xmins) > ymaks+abs(ymins)) panjang=xmaks+abs(xmins), lebar=ymaks+abs(ymins);
    else panjang=ymaks+abs(ymins), lebar=xmaks+abs(xmins);
    printf("%d %d\n", panjang, lebar);
    return 0;
}
