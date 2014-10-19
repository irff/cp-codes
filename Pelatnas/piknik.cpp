#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

int nmakanan,nbahaya,sisa;
map<int,int> makanan;
int main() {
    scanf("%d", &nmakanan);
    R(i,0,nmakanan) {
        int num;
        scanf("%d", &num);
        makanan[num]++;
    }
    scanf("%d", &nbahaya);
    R(i,0,nbahaya) {
        int num;
        scanf("%d", &num);
        makanan[num]=0;
    }
    for(map<int,int>::iterator it=makanan.begin(); it!=makanan.end(); it++) {
        sisa+= it->second;
    printf("%d\n", sisa);
    }
    return 0;
}
