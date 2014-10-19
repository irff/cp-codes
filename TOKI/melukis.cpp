#include <cstdio>
#include <cstring>
using namespace std;

int w,h;
int aksi;
int x1,y1;
int x2,y2;
int nilai;
int a[25][25];
int main(){
    scanf("%d%d", &w,&h);
    scanf("%d", &aksi);
    for(int i=0; i<aksi; i++){
        scanf("%d%d%d%d%d", &x1,&y1,&x2,&y2,&nilai);
        x1--;y1--;x2--;y2--;
        for(int j=y1; j<=y2; j++){
            for(int k=x1; k<=x2; k++){
                a[j][k]=nilai;
            }
        }
    }
    for(int j=0; j<h; j++){
        for(int k=0; k<w; k++){
            printf("%d",a[j][k]);
        }
        printf("\n");
    }
    return 0;
}
