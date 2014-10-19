// Adjacency List (Unweighted, Undirected)
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
#define DFS_WHITE 0 // Unvisited Node
#define DFS_BLACK 1 // Visited Node
#define VI vector<int> 
#define MI map<int,int>
#define R(i,a,b) for(int i=int(a); i<int(b); i++) // Simple Loop Macro
#define RV(v,it) for(VI::iterator (it)=v.begin(); (it)!=v.end(); (it)++) // Vector Loop Macro
VI adj[10000]; // Adjacency List
MI dfs_num; // Visited or Unvisited
int n, num1,num2;

void dfs(int u) { // DFS for normal usage
     printf(" %d", u); dfs_num[u]=DFS_BLACK; // this vertex is visited mark it
     RV(adj[u],v) // try all neighbors of vertex u
        if(dfs_num[*v]==DFS_WHITE) // Avoid Cycle
            dfs(*v);  // v is a neighbor
}

int main(){
    scanf("%d", &n); // Number of Edges
    R(i,0,n){
        scanf("%d %d", &num1, &num2);
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }
    dfs(0); // procedure calling
    return 0;
}
