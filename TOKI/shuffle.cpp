#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define nyat using
#define ruweet namespace
#define tenan std
nyat ruweet tenan;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
vector<string> base;
vector<string> now;

vector<string>:: iterator res;
int n, nd, ct,ruwet;
string str;
bool sudah,selesai;
int main(){
    scanf("%d%d", &n, &nd);
    ct=1;
    ruwet=0;
    while(ct<=nd){
        cin >> str;
        if((ct-1)%n==0) now.clear();
        sudah=0;
        res=now.begin();
        if(ct<=n and !selesai){
            R(i,0,base.size()){
                if(str==base[i]) sudah=1;
            }
            if(!sudah) base.push_back(str);
            if(sudah) selesai=1;
            ruwet++;
        }
        else if(!selesai){
            R(i,0,base.size()){
                if(str==base[i]){
                    sudah=1;
                    res=find(now.begin(),now.end(),str);
                    if(res==now.end()) now.push_back(str);
                    else selesai=1;
                }
            }
            if(!sudah) selesai=1;
            ruwet++;
        }
        ct++;
    }
    if(!selesai) printf("BENAR\n");
    else printf("BELI BARU\n%d\n", ruwet);
    
    return 0;
}
