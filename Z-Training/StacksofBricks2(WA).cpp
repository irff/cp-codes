#include <cstdio>
using namespace std;

int n,a[200];
long long total,rat,hasil;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]),total+=a[i];
    rat=total/n;
    //printf("%d\n",rat);
    for(int i=0; i<n; i++) if(a[i]<rat) hasil+=(rat-a[i]);
    printf("%lld\n", hasil);
    return 0;
}
