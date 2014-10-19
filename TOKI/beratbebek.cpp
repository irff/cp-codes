#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

deque<int>bebek;
long maks,mins;
int berat;
int main(){
    while(scanf("%d", &berat)>0){
        if(berat!=0){
            bebek.push_back(berat);
        }
        else{
            maks=*max_element(bebek.begin(),bebek.end());
            mins=*min_element(bebek.begin(),bebek.end());
            bebek.clear();
            printf("%d %d\n", mins,maks);
        }
    }
    maks=*max_element(bebek.begin(),bebek.end());
    mins=*min_element(bebek.begin(),bebek.end());
    bebek.clear();
    printf("%d %d\n", mins,maks);

    return 0;
}
