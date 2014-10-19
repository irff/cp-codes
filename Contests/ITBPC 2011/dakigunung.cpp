#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <functional>
using namespace std;

#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
#define RV(i,_a,_b) for(int i=int(_a); i>=int(_b); i--)
#define x first
#define y second

typedef pair<int,int> PII;

int n;
PII a[1000222];

bool cp(PII a, PII b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x > b.x;
}

int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d", &a[i].x);
        a[i].y=i;
    }
    sort(a,a+n, cp);
    /*R(i,0,n) {
        printf("%d %d\n", a[i].x, a[i].y);
    }*/
    int i=0,j=n-1;
    bool gagal=0;
    while(a[i].y > a[j].y) {
        //printf("x--> %d %d\n", i,j);
        bool aneha=0,anehb=0;
        if(a[i+1].y < a[j].y) aneha=1;
        if(a[i].y < a[j-1].y) anehb=1;
        
        if( aneha and anehb ) {
            if( a[i+1].x-a[j].x > a[i].x-a[j-1].x) i++;
            else j--;
        } else
        if( aneha ) i++;
        else if( anehb ) j--;
        else i++,j--;
        if(i>=j) { gagal=1; break; }
    }
    if(gagal) printf("0\n");
    else printf("%d\n", a[i].x - a[j].x);
    return 0;
}
