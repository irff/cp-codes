#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
bool ada[15];
vector<int> v[90];
int main() {
    for(int i=1; i<50000; i++) {
        for(int j=2; j<80; j++) {
            int x = i, y = j, xy=i*j;
            bool bisa=1;
            if(xy>=100000) bisa=0;
            memset(ada, 0, sizeof ada);
            if(x<10000) ada[0]=1;
            while(x>0) {
                if(ada[x%10]) { bisa=0; break; }
                else ada[x%10]=1,x/=10;
            }
            while(xy>0) {
                if(ada[xy%10]) { bisa=0; break; }
                else ada[xy%10]=1,xy/=10;
            }
            if(bisa) R(k,0,10) if(!ada[k]) bisa=0;
            if(bisa) v[j].push_back(i);
            //if(bisa) printf("x");
        }
    }
    scanf("%d", &n);
    bool pertamax=1;
    while(n!=0) {
        if(!pertamax) printf("\n");
        pertamax=0;
        int len = v[n].size();
        if(len==0) printf("There are no solutions for %d.\n", n);
        else R(i,0,len) {
               if(v[n][i]>=10000) printf("%d / %d = %d\n", v[n][i]*n, v[n][i], n);
               else printf("%d / 0%d = %d\n", v[n][i]*n, v[n][i], n);
             }
        scanf("%d", &n);
    }
    return 0;
}
