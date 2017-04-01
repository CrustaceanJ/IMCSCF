#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
string s, st;
vector<ll> prefixFun(string s){
	ll sz = s.size();
	vector<ll> p(sz);
	p[0] = 0;
	ll q = 0;
	for (ll t = 1; t < sz; ++t){
		while (q>0 && p[q] == p[t]) q = p[q];
		if (p[q] == p[t]) q++;
		p[t] = q;
	}
	return p;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	getline(cin, s);
	getline(cin, st);
	
	cout << -1 << endl;
	return 0;
}
