#include <cstdio>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a[1000];
int teskes;
int main() {
    scanf("%d", &teskes);
    printf("Lumberjacks:\n");
    while(teskes--) {
        R(i,0,10) scanf("%d", &a[i]);
        bool asc = 1, desc = 1;
        R(i,1,10) if(a[i] < a[i-1]) asc = 0;
        R(i,1,10) if(a[i] > a[i-1]) desc = 0;
        if(asc or desc) printf("Ordered\n");
        else printf("Unordered\n");
    }

    return 0;
}
