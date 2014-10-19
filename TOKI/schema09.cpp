#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int N, teskes,c[10100], p[10100];
vector <vector <int> > E;
vector <int> B;

void traverse(int v)
{
     for(int i=0; i<E[v].size(); i++)
         if(p[v] != E[v][i]) { p[E[v][i]] = v; traverse(E[v][i]); }
     
     if(c[v] == 0)
     {
         B.push_back(v); c[v]++;
         for(int i=0; i<E[v].size(); i++)
         {
             c[E[v][i]] += 2; B.push_back(E[v][i]);
             for(int j=0; j<E[E[v][i]].size(); j++) c[E[E[v][i]][j]]++;
         }
     }
}

int main()
{
    scanf("%d", &teskes);
    while(teskes--){
        B.clear();
        E.clear();
        scanf("%d", &N);
        E.resize(N);
        for(int i=0; i<N; i++) { p[i] = -1; c[i] = 0; }
    
        int u, v;
    
        for(int i=0; i<N-1; i++)
        {
            scanf("%d %d", &u, &v);
            E[u-1].push_back(v-1);
            E[v-1].push_back(u-1);
        }
        
        traverse(0);
            
        int numRemove = 0;
        for(int i=B.size()-1; i>=0; i--)
        {
            bool canRemove = (c[B[i]] > 1);
            for(int j=0; j<E[B[i]].size(); j++)
                canRemove = canRemove && (c[E[B[i]][j]] > 1);
            if(canRemove)
            {
                c[B[i]]--;
                for(int j=0; j<E[B[i]].size(); j++) c[E[B[i]][j]]--;
            }
            numRemove += canRemove;
        }
        
        printf("%d\n", B.size()-numRemove);
    }
}
