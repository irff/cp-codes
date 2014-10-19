#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

char awal[3], akhir[3];
int main() {
    scanf("%s%s", &awal, &akhir);
    int ax = awal[0]-'a'+1; int ay = (awal[1]-'0');
    int bx = akhir[0]-'a'+1; int by = (akhir[1]-'0');
    int cy = bx-ax, cx = by-ay;
    
    int dist = max(abs(cx), abs(cy));
    printf("%d\n", dist);
    
    for(int i=0; i < dist; i++) {
        if(cx < 0 and cy < 0) { printf("LD\n"); cx++, cy++; }
        else if(cx < 0 and cy == 0) { printf("D\n"); cx++; }
        else if(cx < 0 and cy > 0) { printf("RD\n"); cx++, cy--; }
        else if(cx == 0 and cy > 0) { printf("R\n"); cy--; }
        else if(cx > 0 and cy > 0) { printf("RU\n"); cx--, cy--; }
        else if(cx > 0 and cy == 0) { printf("U\n"); cx--; }
        else if(cx > 0 and cy < 0) { printf("LU\n"); cx--; cy++; }
        else if(cx == 0 and cy < 0) { printf("L\n"); cy++; }
    }
    return 0;
}
