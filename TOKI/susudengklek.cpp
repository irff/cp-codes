#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
int h1,w1,h2,w2;
long n,maks;
deque<long>totaln;
long a[120][120];
int main(){
    scanf("%d%d", &h1,&w1);
    scanf("%d%d", &h2,&w2);
    
    for(int i=0; i<h1; i++){
        for(int j=0; j<w1; j++)scanf("%ld", &a[i][j]);
    }
    for(int i=0; i<h1; i++){
        for(int j=w1; j<2*w1; j++) a[i][j]=a[i][j-w1];
    }
    for(int i=0; i<h1; i++){
        for(int j=0; j<w1; j++){
           n=0;
           for(int k=i; k<i+h2; k++){
               for(int l=j; l<j+w2; l++) n+=a[k][l];
           }
           totaln.push_back(n);
        }
    }
    maks=*max_element(totaln.begin(),totaln.end());
    printf("%ld\n", maks);
    return 0;
}
