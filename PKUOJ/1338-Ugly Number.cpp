#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int main(){
    v.push_back(1);
    for(int i=2; v.size()<1600; i++){
        int x=i;
        while(x%2==0) x/=2;
        while(x%3==0) x/=3;
        while(x%5==0) x/=5;
        if(x==0) v.push_back(i);
    }
    int n; scanf("%d", &n);
    while(n!=0){
        printf("%d\n", v[n-1]);
        scanf("%d", &n);
    }
    return 0;
}
