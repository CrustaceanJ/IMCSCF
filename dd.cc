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
vector<vector<double>> gr;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i){
		p pt;
		cin >> pt.x >> pt.y;
		vP.push_back(pt);
	}
	gr.resize(n);
	for (int i = 0; i < n; ++i){
		gr[i].resize(n);
		for (int j = 0; j < n; ++j){
			if ((i + 1) % n == j % n || (i - 1) % n == j % n) gr[i][j] = 0; else
			gr[i][j] = sqrt((vP[i].x - vP[j].x)*(vP[i].x - vP[j].x)*1.0 + (vP[i].y - vP[j].y)*(vP[i].y - vP[j].y)*1.0);
		}
	}

	return 0;
}//http://codeforces.com/blog/entry/2275#comment-47170
