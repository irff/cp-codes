#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v[4];

void move(int n, int a, int b, int c) {
 if(n>0) {
  move(n-1,a,c,b);
  cout<<"disk "<<n<<" is moved from "<<a<<" to "<<c<<endl;
  move(n-1,b,a,c);
 }
}

int main(){
    int n;
    cin>>n;
    move(n,0,1,2);
    R(i,0,n) 
    return 0;
}
