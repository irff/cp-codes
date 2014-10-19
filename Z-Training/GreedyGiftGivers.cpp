#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,int> m;
string beri,dapet,nama[20];
int np,ng,duit;
int main(){
    scanf("%d", &np);
    for(int i=0; i<np; i++){
        cin >> nama[i];
    }
    while( (cin >> beri )){
        scanf("%d%d", &duit, &ng);
        m[beri]-=duit;
        if(ng!=0)m[beri]+=duit%ng;
        for(int i=0; i<ng; i++){
            cin >> dapet;
            m[dapet]+=(duit/ng);
        }
    }
    for(int i=0; i<np; i++){
        printf("%s %d\n", nama[i].c_str(),m[nama[i]]);
    }
    
    return  0;
}
