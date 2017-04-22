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
ll n;
struct p{
	int x;
	int y;
};
vector<p> vP;
vector<vector<double>> d, L;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i){
		p pt;
		cin >> pt.x >> pt.y;
		vP.push_back(pt);
	}
	d.resize(n);
	L.resize(n);
	for (int i = 0; i < n; ++i){
		d[i].resize(n);
		L[i].resize(n, 1e6);
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if ((i + 1) % n == j % n || (i - 1) % n == j % n) d[i][j] = 1e6; else
				d[i][j] = sqrt((vP[i].x - vP[j].x)*(vP[i].x - vP[j].x)*1.0 + (vP[i].y - vP[j].y)*(vP[i].y - vP[j].y)*1.0);
		}
	}
	
	for (int i = 0; i < n-2; ++i){
		L[i][(i + 2)] = 0;
	}
	for (int i = 0; i < n; ++i){
		for (int j = i + 3; j < n; ++j){
			for (int k = i + 1; k < j; ++k){
				L[i][j] = min(L[i][j], L[i][k] + L[k][j] + d[i][k] + d[k][j]);
			}
		}
	}
	cout << L[0][n - 1] << endl;
	return 0;
}
