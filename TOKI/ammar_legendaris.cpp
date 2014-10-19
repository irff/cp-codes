#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct {
    int x,y;
} pasang;

map<int,int> pernah,ada,first,second;
pasang a[200007];
int i,n,pos,next,udah,start,finish;

int main() {
    scanf("%d",&n);
    for (i=0 ; i<n ; i++) {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[n+i].x = a[i].y;
        a[n+i].y = a[i].x;
    }
    
    n = 2*n;
    
    for (i=0 ; i<n ; i++) ada[a[i].x]++;
    for (i=0 ; i<n ; i++) {
        if (ada[a[i].x] == 1) {
            if (udah == 0) {
                udah = 1;
                start = a[i].x;
            } else finish = a[i].x;
        } 
    }
    
    if (finish < start) swap(start,finish);
    
    for (i=0 ; i<n ; i++)
        if (first[a[i].x] == 0)
            first[a[i].x] = a[i].y;
        else second[a[i].x] = a[i].y;
    
    pos = start;
    pernah[start] = 1;
    printf("%d",start);
    
    while (pos != finish) {
        next = first[pos];
        
        if (pernah[next] == 0) {
            pernah[next] = 1;
            printf(" %d",next);
            pos = next;
        } else {
            next = second[pos];
            pernah[next] = 1;
            printf(" %d",next);
            pos = next;
        }
    }
    
    printf("\n");
    //scanf("\n");
}
