#include <cstdio>

int sec;
double next[12];
int main(){
    scanf("%d", &sec);
    next[0]=0;
    for(int i=1; i<12; i++){
        next[i]=(3600*i)*(double)12/11;
        //printf("%.3lf\n", next[i]);
    }
    for(int i=1; i<12; i++){
        if(next[i]>sec) { printf("%.3lf\n", next[i]); break; }
    }
    scanf("\n");
    return 0;
}
