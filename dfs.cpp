#include <iostream>
#include <vector>

using namespace std;
bool odw [1000001];
int n, m, a, b;
vector < int > G[1000001];
vector < int > K[1000001];



void DFS (int w)
{
    cout<<w<<" ";
    if(odw[w]==1)
    {
        return;
       
    }
   
      odw[w]=1;
      for (int i = 0; i < G[w].size(); i++)
     {
        if(odw[G[w][i]]==0)
        {
            DFS(G[w][i]);
        }
     }
      cout<<"("<<w<<") ";

   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n>>m;
    for (int i = 0; i < m; i++)
    {
       cin >> a >> b;
       G[a].push_back(b);
       G[b].push_back(a);
    }
    DFS(1);
    
    
}
    
