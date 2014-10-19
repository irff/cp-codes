#include <cstdio>
using namespace std;

int A,B,C,D;
int x,y,z;
long long pangkat(int a,int b){
    if(b==0) return 1;
    long long tmp=pangkat(a,b/2);
    if(b%2) return a*tmp*tmp;
    return tmp*tmp;
}

int main(){
   while(scanf("%d%d%d%d", &A,&B,&C,&D)>0){
       x=y=z=-1;
       bool nemu=0;
       for(int i=0; i <= (1<<15); i++)
           if( pangkat(i*i+i-D,B)+i*i-D-C == 0){
               if(i*i-D>0){
                   x=i;
                   y=x*x-D;
                   z=A-(x*x+y*y);
                   if(z>=0){
                       nemu=1;
                       break;
                   }
               }
           }
       if(!nemu) printf("No solution\n");
       else printf("%d %d %d\n", x,y,z);
   }
   return 0;
}
