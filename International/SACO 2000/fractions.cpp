#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
int a,b,c,n1,n2,ca,indeks;
map<PII,int> ma;
map<int,PII> mb;
int main() {
    for(int i=2; i<100; i++) {
        for(int j=1; j<i; j++) {
            if(__gcd(i,j)==1) {
                ma[PII(j,i)]=++ca;
                mb[ca]=PII(j,i);
            }
        }
    }
    printf("Enter first number (f): "); scanf("%d", &n1);
    printf("Enter second number (s): "); scanf("%d", &n2);
    // penjumlahan pecahan
    a=mb[n1].first*mb[n2].second+mb[n1].second*mb[n2].first;
    b=mb[n1].second*mb[n2].second;
    c=__gcd(a,b);
    a/=c; b/=c;
    
    indeks=ma[PII(a,b)];
    printf("Position of sum is: %d\n", indeks);
    return 0;
}
