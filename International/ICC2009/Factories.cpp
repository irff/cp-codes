#include <cstdio>
#include <map>
using namespace std;

int n,x=2;
map<int,int> pf;
int main() {
    scanf("%d", &n);
    if(n==0 or n==1) printf("%d %d\n", n, 1);
    else {
        while(n!=1) {
            while(n%x==0) {
                pf[x]++;
                n/=x;
            }
            x++;
        }
    }
    for(map<int,int>::reverse_iterator it=pf.rbegin(); it!=pf.rend(); it++) {
        printf("%d %d\n", it->first, it->second);
    }
    return 0;
}
