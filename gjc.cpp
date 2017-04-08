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
ll x, t;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	string st;
	getline(cin, st);
	for (int i = 0; i < t; ++i){
		string s;
		char c = '0';
		getline(cin, s);
		ll sz = s.size();
		c = s[0];
		int d = 0;
		for (d = 0; d <= s.size(); ++d){
			if (d == s.size() || c > s[d]) break;
			c = s[d];
		}
		if (d != s.size()) c = s[d];
		if (c == '0') {
			s = "";
			for (int j = 0; j < sz; j++)
			{
				s = s + '9';
			}
		}
		else
		{
			c = '9';
			for (int j = d-1; j < s.size(); ++j)
			{
				if (d - 1> 0){
					if (j == d-1) s[j]--;
					else
						s[j] = c;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
