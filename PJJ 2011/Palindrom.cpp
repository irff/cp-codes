#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string sa,si,su[10000];
int ctr=0;
int main(){
    while(cin>>sa > 0){
        si=sa;
        reverse(si.begin(),si.end());
        if(sa==si) su[ctr++]=sa;
    }
    for(int i=0; i<ctr; i++){
        cout << su[i];
        if(i!=ctr-1) cout << " ";
        else cout << endl;
    }
    return 0;
}
