#include <cstdio>

int teskes;
char a[5][5];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int nx=0,no=0;
        
        for(int i=0; i<3; i++) scanf("%s", a[i]);
        
        for(int i=0; i<3; i++)
          for(int j=0; j<3; j++)
            if(a[i][j]=='x') nx++;
            else no++;
        
        if(nx>no) {
            bool success=0;
            for(int i=0; i<3; i++) {
              if(a[i][0]=='x' and a[i][1]=='x' and a[i][2]=='x') success=1;
              if(a[0][i]=='x' and a[1][i]=='x' and a[2][i]=='x') success=1;
            }
            
            if(a[0][0]=='x' and a[1][1]=='x' and a[2][2]=='x') success=1;
            if(a[0][2]=='x' and a[1][1]=='x' and a[2][0]=='x') success=1;
            if(success) printf("Pemain x berhasil menyerang\n");
            else printf("Pemain o berhasil bertahan\n");
        } else {
            bool success=0;
            for(int i=0; i<3; i++) {
              if(a[i][0]=='o' and a[i][1]=='o' and a[i][2]=='o') success=1;
              if(a[0][i]=='o' and a[1][i]=='o' and a[2][i]=='o') success=1;
            }
            
            if(a[0][0]=='o' and a[1][1]=='o' and a[2][2]=='o') success=1;
            if(a[0][2]=='o' and a[1][1]=='o' and a[2][0]=='o') success=1;
            if(success) printf("Pemain o berhasil menyerang\n");
            else printf("Pemain x berhasil bertahan\n");
        }
    }
    return 0;
}
