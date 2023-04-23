
#include <bits/stdc++.h>

using namespace std;
long long n,m,k;
long long d[200099];
long long w,haaland=0;
long long u,v;
vector<pair<long long,long long> > a[100005];
bool visited[200005];
priority_queue< pair<long long,long long >, vector<pair<long long,long long> >, greater<pair<long long, long long> > >duy;
int main()
{
 //   freopen("DFS.inp","r",stdin);
   // freopen("DFS.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   cin>>n>>m;

   for( int i=1;i<=m;i++)
   {
       cin>>u>>v;
       cin>>w;
       a[u].push_back(make_pair(v,w));

   }
  for( int i=1;i<=n;i++)
  {
      d[i]=1e18;
  }
  d[1]=0;
  duy.push({0,1});
  while(!duy.empty())
  {
      pair<long long, long long> gotta;
      gotta = duy.top();
      duy.pop();
      long long l=gotta.second;
      if (gotta.first != d[l])
      {
          haaland++;
          continue;
      }
      for(auto e :a[l])
      {
          if(d[e.first]> gotta.first +e.second)
          {
             d[e.first] = gotta.first+e.second ;
             duy.push({gotta.first+e.second, e.first});
          }
      }
  }
        for( int i=1;i<=n;i++)
      {
          cout<<d[i]<<" ";
      }

    return 0;
}
