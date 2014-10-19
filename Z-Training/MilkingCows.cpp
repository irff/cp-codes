/*
TASK: milk2
LANG: C++
ID: irfan1
*/

#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef map<int,int> MI;
typedef MI::iterator MIT;
const int kosong=0,isi=1;
MI m;
int a,b,N;
int main(){
    //freopen("milk2.in","r",stdin);
    //freopen("milk2.out","w",stdout);
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d%d", &a, &b);
        m[a]++; m[b]--;
    }
    
    int pre=0;
    for(MIT it=m.begin(); it!=m.end(); it++){
        it->second=pre+it->second;
        pre=it->second;
    }
    
    int MAX=0,MIN=0;
    int state=isi;
    int awal=m.begin()->first,kawal=0;
    for(MIT it=m.begin(); it!=m.end(); it++){
        if(it->second==0){
            MAX=max(MAX,it->first-awal);
            state=kosong;
            kawal=it->first;
        }
        else if(state==kosong){
            MIN=max(MIN,it->first-kawal);
            state=isi;
            awal=it->first;
        }
    }
    printf("%d %d\n", MAX, MIN);
    //scanf("\n");
    return 0;
}
