#include <cstdio>

int teskes;
bool a[10];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        for(int i=0; i<10; i++) scanf("%d", &a[i]);
        bool hasil=a[0] or a[1];
        for(int i=0; i<10; i++)
          for(int j=i+1; j<10; j++)
           if(i!=0 or j!=1) hasil=hasil^(a[i] || a[j]);
        for(int i=0; i<10; i++)
          for(int j=i+1; j<10; j++)
           for(int k=j+1; k<10; k++)
            hasil=hasil^(a[i] || a[j] || a[k]);
        printf("%d\n", hasil);   
    }

}
