#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int a,b,guess;
    string s;
    scanf("%d%d", &a,&b);
    do{
        guess=(a+b)/2;
        printf("%d\n", guess); fflush(stdout);
        cin >> s;
        if( s=="LOW") a=guess+1;
        else b = guess-1;
    } while(s!="WIN");


    return 0;
}
