#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;

int n, mbebek=0,pangkat[25], a[25];
int main() {
    pangkat[0] = 1;
    for(int i=1; i<20; i++) pangkat[i] = pangkat[i-1]*3;
    scanf("%d", &n);
    int ctr = 19;
    while(n!=0) {
        while(n >= pangkat[ctr]) {
            a[ctr]+=n/pangkat[ctr];
            mbebek+=n/pangkat[ctr];
            n%=pangkat[ctr];
        }
        ctr--;
    }
    printf("%d\n",mbebek);
    for(int i=0; i<20; i++)
        for(int j=0;j<a[i];j++) {
            v.push_back(pangkat[i]);
        }
    int len = v.size();
    for(int i=0; i<len; i++) {
        printf("%d", v[i]);
        if(i != len-1) printf(" ");
    }
    printf("\n");
    scanf("\n");
    return 0;
}
