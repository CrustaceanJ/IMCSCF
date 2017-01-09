#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
string s;
typedef long long ll;
ll szx = 0, z = 0, ans = 0, a[26];
char ch, x='0';

void addToAns(vector< pair<ll, ll>> hochy_kyshat)
{
  ll lMax = 0;
  for(int i = hochy_kyshat.size()-1; i >= 0; --i)
  {
    if(hochy_kyshat[i].second>lMax)
    {
      long long tmp = hochy_kyshat[i].first*(hochy_kyshat[i].second-lMax);
  	  if(tmp<0)
  		    ans=ans-tmp;
  	  else
  		    ans=ans+tmp;
  	  lMax=hochy_kyshat[i].second;
    }
  }
}

int main()
{
    freopen("strange.in", "r", stdin);
    freopen("strange.out","w",stdout);
	  getline(cin, s);
    vector< pair<char, ll> > v;
    vector< vector < vector< pair<ll, ll> > > > letters(26);
    for(int i = 0; i<26; ++i)
    {
      letters[i].resize(26);
    }
	  while(z!=s.length())
    {
    	ch = s[z];
      if(x=='0')
      {
        x=ch;
      }
      if(x!=ch)
      {
    	  a[(int)x-(int)'a']=max(a[(int)x-(int)'a'], szx);
        v.push_back(make_pair(x, szx));
        x = ch;
        szx=0;
      }
      szx++;
      if(z==s.length()-1)
    	{
      		a[(int)ch-(int)'a']=max(a[(int)ch-(int)'a'], szx);
          v.push_back(make_pair(ch, szx));
    	}
  	  z++;
    }
    if(v.size()==1)
    {
      cout<<v[0].second;
      return 0;
    }
    for(int i = 1; i<v.size();++i)
    {
      letters[(int)v[i-1].first-(int)'a'][(int)v[i].first-(int)'a'].push_back(make_pair(v[i-1].second, v[i].second));
    }
	  v.clear();
    for(int i = 0; i<26;++i)
    {
      for(int j = 0; j<26; ++j)
      {
        if(letters[i][j].size()<=1) continue;
        sort(letters[i][j].begin(), letters[i][j].end());
      }
    }
    for(int i = 0; i < 26; ++i)
    {
      for(int j = 0; j < 26;++j)
      {
        if(j==i) continue;
        addToAns(letters[i][j]);
      }
    }
  	for(int i = 0; i < 26; ++i)
  	{
  		ans+=a[i];
  	}
  	cout<<ans<<endl;
}
