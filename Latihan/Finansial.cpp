// irfan's financial calculator
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
typedef long long LL;

LL finalmoney,nincome,nspent,budget,income,spent,totalincome,totalspent,totalmoney,loan,networth;
int main(){
    
    printf("How much is your initial budget?\n");
    scanf("%lld", &budget);
    
    totalmoney+=budget;
    
    printf("How many source of income do you have?\n");
    scanf("%lld", &nincome);
    
    R(i,1,nincome+1){
        printf("How much is your %dth income?\n", i);
        scanf("%lld", &income);
        totalincome+=income;
    }
    
    totalmoney+=totalincome;
    
    printf("How many activities cost you money?\n");
    scanf("%lld", &nspent);
    
    R(i,1,nspent+1){
        printf("How much does your activity number %d cost?\n", i);
        scanf("%lld", &spent);
        totalspent+=spent;
    }
    
    printf("Do you have any unpaid loan/debt?\n");
    scanf("%lld", &loan);
    
    system("PAUSE");
            
    printf("Here is the summary\n");
    printf("--INITIAL BUDGET : %lld Rupiahs\n", budget);
    printf("--TOTAL INCOME   : %lld Rupiahs\n", totalincome);
    printf("--TOTAL MONEY    : %lld Rupiahs\n", totalmoney);
    printf("--TOTAL SPENT    : %lld Rupiahs\n", totalspent);
    finalmoney=totalmoney-totalspent;
    networth=finalmoney-loan;
    printf("--FINAL MONEY    : %lld Rupiahs\n", finalmoney);
    printf("--NET WORTH      : %lld Rupiahs\n", networth);
    
    system("PAUSE");
        
    return 0;
}
