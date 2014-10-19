#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

map<int,int> used;
int hasil=0,nkayu,diangkat=0,ngajah;
void rek(int a) {
    if(a==0) return ;
    for(map<int,int>::iterator it=used.begin(); it!=used.end(); it++) {
        if(it->second){
            if(it->first >=a) {
                printf("%d ", a);
                hasil++;
                diangkat+=a;
                it->second--;
                return ;
            }
        }
    }
    if(a==1) return ;
    int ki=a/2; int ka=a-ki;
    rek(ka); rek(ki);
}
int main() {
    scanf("%d%d", &nkayu, &ngajah);
    R(i,0,ngajah) {
        int num;
        scanf("%d", &num);
        used[num]++;
    }
    rek(nkayu);
    if(diangkat==nkayu) {
        printf("\n%d\n", hasil);
    } else printf("\n0\n");
    return 0;
}
