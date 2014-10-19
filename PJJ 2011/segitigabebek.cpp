#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int kx[320],ky[320],n;
double a=0,mins=2000111222.00;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &kx[i], &ky[i]);
    for(int i=0; i<n; i++) 
     for(int j=i+1; j<n; j++) 
      for(int k=j+1; k<n; k++) {
        a=fabs( (kx[i]*(ky[j]-ky[k])+kx[j]*(ky[k]-ky[i])+kx[k]*(ky[i]-ky[j])) /2 );
        mins=min(mins,a);
      }
   printf("%.2lf\n", mins);
    return 0;
}
