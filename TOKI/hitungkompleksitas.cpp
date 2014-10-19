#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define R(_,_a,_b) for(int _=int(_a);_<int(_b);_++)
int m,n;

string s;
int val(string s){
    
    if(s=="1") return 1;
    if(s=="logN") return 2;
    if(s=="N") return 3;
    if(s=="NlogN") return 4;
    if(s=="N^2") return 5;
    if(s=="N^3") return 6;
    if(s=="2^N") return 7;
    if(s=="N!") return 8;
}
int main(){ 
    int nyat,sampah=32123,tenan;
    cin >> n >> m;
    R(i,1,n+1){
        tenan=-32123;
        R(j,0,m){
            cin >> s; int x=val(s);
            if(x>tenan) tenan=x;
        }
        if(tenan<sampah) { sampah=tenan; nyat=i;}
    }
    printf("%d\n", nyat);
    return 0; 
}
