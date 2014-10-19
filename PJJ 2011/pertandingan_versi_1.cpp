#include <cstdio>
#include <functional>
#include <algorithm>
#include <deque>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        int skora=0, skorb=0;
        deque<int>a,b;
        int num=0;
        
        R(i,0,n) { scanf("%d", &num); a.push_back(num); }
        R(i,0,n) { scanf("%d", &num); b.push_back(num); }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        R(i,0,n) {
            if(a[0] >= b[0]) {
                skora+=3;
                a.pop_back(); b.pop_front();
            } else {
                skorb+=3;
                a.pop_front(); b.pop_front();
            }
        }
        //printf("%d %d\n", skora, skorb);
        if(skorb>skora) printf("YA\n");
        else printf("TIDAK\n");
    }
    return 0;
}
