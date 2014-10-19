#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a[6];
bool bisa = 0;
void rek(int ke, int num) {
    //printf("%d %d\n", ke, num);
    if(ke>=5) {
        if(num==23) bisa = 1;
        return ;
    }
    rek(ke+1, num*a[ke]);
    rek(ke+1, num-a[ke]);
    rek(ke+1, num+a[ke]);
}

int main() {
    R(i,0,5) scanf("%d", &a[i]);
    while(!(!a[0] and !a[1] and !a[2] and !a[3] and !a[4])){
        bisa = 0;
        sort(a, a+5);
        do {
            if(!bisa) rek(1,a[0]);
            else break;
        } while(next_permutation(a,a+5));
        
        if(bisa) printf("Possible\n");
        else printf("Impossible\n");

        R(i,0,5) scanf("%d", &a[i]);
    }
    return 0;
}
