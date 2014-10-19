#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

int a[1200], n, ntukar;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d", &a[i]);
    }
    R(i,0,n) {
        int mins=2000111222,id=i;
        R(j,i,n) {
            if(a[j] < mins) {
                mins = a[j];
                id = j;
            }
        }
        if(id != i) {
            ntukar++;
            swap(a[i], a[id]);
        }
    }
    
    printf("%d\n", ntukar);
    return 0;
}
