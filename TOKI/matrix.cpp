#include <cstdio>
#include <valarray>
#include <vector>
using namespace std;
vector<short> a[1000000];
int num;

int va[10000];
int matrix(int num){
    a[1].push_back(1);
    
    int c=1,x=1,xx=1;
    while(1){
        int s=a[c].size()-1;
        for(int i=xx; i<xx+a[c].size(); i++){
            a[i+c]=a[c];
            a[i+c].push_back( a[c][s]+a[c][i-xx] );
            if(a[i+c].back()==num) return a[i+c].size()-1;
            x++;
            va[ a[c][s]+a[c][i-xx] ] = 1;
        }
        xx=x;
        c++;
    }
}

int main(){
    for(int i=0; i<10000; i++) va[i]=-1;
    scanf("%d", &num);
    printf("%d\n", num==1?0:matrix(num));
    return 0;
}
