#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 1000000000
const int MAXN=105;
int n, m;
int u, v, p;
int g[MAXN][MAXN];
int main()
{
  freopen("input.txt","r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%d", &n, &m);
  for(int i = 0; i <= MAXN-1; i++)
  {
    for(int j = 0; j <= MAXN-1; ++j)
    {
      if(i==j)
      {
        g[i][j] = 0;
      }
      else
      {
        g[i][j] = INF;
      }
    }
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &u, &v, &p);
    g[u][v] = p;
  }
  for(int k = 1; k<=n; ++k)
  {
    for(int i = 1; i<=n; ++i)
    {
      for(int j = 1; j<=n; ++j)
      {
        if(g[i][k]<INF && g[k][j]<INF) g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
      }
    }
  }
  for(int i = 1; i<=n; ++i)
  {
    for(int j = 1; j<=n;++j)
    {
      if(g[i][j]==INF)
      {
        cout<<"  ";
      }
      else
      {
        cout<<g[i][j]<<" ";
      }
    }
    cout<<endl;
  }
  return 0;
}
