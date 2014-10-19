#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

vector<int> vtop,vbottom;
int ma[3000],mb[3000];
int na,nb,a[25],b[25];
int main() {
    scanf("%d", &na);
    R(i,0,na) scanf("%d", &a[i]);
    scanf("%d", &nb);
    R(i,0,nb) scanf("%d", &b[i]);
    sort(a,a+na); sort(b,b+nb);
    int separator=min(na,nb);
    R(i,0,separator) {
        if(a[i] > b[i]) {
            R(j,b[i]+1,a[i]+1) vtop.push_back(j);
        } else
        if(b[i] > a[i]) {
            R(j,a[i]+1,b[i]+1) vbottom.push_back(j);
        }
    }
    if(na > nb) {
        R(i,separator,na) vtop.push_back(a[i]);
    } else
    if(nb > na) {
        R(i,separator,nb) vbottom.push_back(b[i]);
    }
    int siza=vtop.size(),sizb=vbottom.size();
    R(i,0,siza) {
        //printf("%d ", vtop[i]);
        int x=2,num=vtop[i];
        while(num > 1) {
            while(num%x==0) {
                ma[x]++;
                num/=x;
            }
            x++;
        }
    }
    //printf("\n");
    R(i,0,sizb) {
        //printf("%d ", vbottom[i]);
        int x=2,num=vbottom[i];
        while(num > 1){
            while(num%x==0) {
                mb[x]++;
                num/=x;
            }
            x++;
        }
    }
    R(i,0,3000) {
        if(ma[i]!=0 and mb[i]!=0){
            int tmp=min(ma[i],mb[i]);
            ma[i]=ma[i]-tmp;
            mb[i]=mb[i]-tmp;
        }
    }
    //printf("\n");
    R(i,0,3000) {
        if(ma[i]!=0) {
            if(ma[i]==1) printf("%d ", i);
            else printf("%d(%d) ", i, ma[i]);
        }
    }
    printf("\n");
    R(i,0,3000) {
        if(mb[i]!=0) {
            if(mb[i]==1) printf("%d ", i);
            else printf("%d(%d) ", i, mb[i]);
        }
    }
    printf("\n");
    return 0;
}
