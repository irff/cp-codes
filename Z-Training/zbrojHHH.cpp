#include <stdio.h>
#include <string.h>
 
int odd1=0,odd2=1,even1=1,even2=0;
int i,j,x[11],a[30],b[30],len;
char s[30];
int main()
{
    for(i=0; i<30; i++) a[i]=123,b[i]=123;
    scanf("%s", &s); len=strlen(s);
    for(i=0; i<len; i++)
    {
        x[s[i]-'0']++;
    }
    for(i=9; i>=0; i--)
    {
        while(x[i]--)
        {
            if(i%2==1)
            {
                a[odd1]=i; odd1=odd1+2;
                b[odd2]=i; odd2=odd2+2;
            }
            else
            {
                a[even1]=i; even1=even1+2;
                b[even2]=i; even2=even2+2;
            }
        }
    }
    int lena=0,leni=0;
    for(int j=0; j<30; j++) if(a[j]!=123) lena++; else break;
    for(int j=0; j<30; j++) if(b[j]!=123) leni++; else break;
    //printf("%d %d\n", lena, leni);
    i=0;
    if(lena>leni){
        while(a[i]!=123)
            printf("%d", a[i++]);
    } else if(leni>lena){
        while(b[i]!=123)
            printf("%d", b[i++]);
    } else
    if(a[0]>b[0])
        while(a[i]!=123)
            printf("%d", a[i++]);
    else
        while(b[i]!=123)
            printf("%d", b[i++]);
    puts("");
    scanf("\n");
    return 0;
}
