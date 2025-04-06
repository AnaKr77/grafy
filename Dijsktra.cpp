#include <iostream>
#include <vector>
#include <queue>
#include <functional>


using namespace std;
long long odl [1000001];
vector <pair<long long,long long>>v[1000001];
long long n,m,a,b,o;
void dijkstra(int start)
{
    for (int i = 1; i <=n; i++)
    {
        odl [i]=-1;
    }
    odl[start]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
    q.push(make_pair(0,start));
    while(!q.empty())
    {
        long long w=q.top().second;
        long long value=q.top().first;
        q.pop();
        if(odl[w]<value)
        {
            continue;
        }
        for (int i = 0; i < v[w].size(); i++) 
        {
           long long s=v[w][i].first;
           long long d=v[w][i].second + value;
           if(odl[s]>d || odl[s]==-1)
           {
               odl[s]=d;
               q.push(make_pair(d,s));
           }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
       cin >> a >> b >>o; 
       v[a].push_back(make_pair(b,o));
       v[b].push_back(make_pair(a,o));
    }
    
    dijkstra(1);

    for (int i = 1; i <n+1; i++) 
    {
           cout << odl [i]<< endl; 
        
        
    }
    return 0;
}
