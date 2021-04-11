#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#pragma comment(linker, "/STACK:2769095000")
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<numeric>
#include<chrono>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<random>
#include<functional>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<complex>
#include<tuple>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef int itn;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
typedef pair<ll, ld> pid;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
#define xx first
#define yy second
//#define int __int128t
//#define F first
//#define S second
#define zz second
#define mp make_pair
#define y1 oshfkfsldhs
#define union jfghjdghdjhgjhdjgh
#define all(x) (x).begin(), (x).end()
#define out(x) return void(cout << (x) << endl)
#define OUT(x) ((cout << (x)), exit(0))
const ll MOD = 1e9 + 7;// (ll)998244353;
const ll MOR = (ll)1e9 + 33;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const char dc[] = { 'D', 'U', 'R', 'L' };
const ll INF = 1e18 + 100;
const ld EPS = 1e-10;
const double PI = 3.14159265358979323846;
const int SZ = 80000001;
const ll MAXN = (1 << 20) + 100, maxN = 505;

#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
typedef __int64 int128;
#else
//typedef __int128 int128;
#endif

inline void getint(int& x) {
	int c = getc(stdin);
	x = 0;
	while (c <= 32)
		c = getc(stdin);
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getc(stdin);
	return;
}
inline void writeint(int& x)
{
	char s[10];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		putc(s[n], stdout);
	putc('\n', stdout);
}

int g[1025][11];
string info[1025];

int st(int x)
{
	for (int i = 9; i >= 0; i--)
		if (x & (1 << i))
			return i;
	return 0;
}
int step;
string find(int cur, int finish, bool print = 0)
{
	
	if (cur == finish)
		return info[finish];
	step++;
	int dist = 1e6, nxt;
	if(print)cout << "from " << cur << ":\n";
	for (int i = 0; i < 10; i++)
	{
		if (g[cur][i] == -1)
			continue;
		if (print)cout << "variant: " << g[cur][i] << " dist: " << (finish ^ g[cur][i]) << "\n";
		if (g[cur][i] >= 0 && (finish ^ g[cur][i]) < dist)
		{
			dist = finish ^ g[cur][i];
			nxt = g[cur][i];
		}
	}
	if (print)cout << "next step: " << nxt << "  dist: " << dist << "\n";
	return find(nxt, finish);
}

void solve()
{
	for (int i = 0; i < 1024; i++)
	{
		fill(g[i], g[i] + 10, -1);
		int cnt = 1 + rand() % 5;
		for (int t = 0; t < cnt; t++)
			info[i] += "_";
		info[i] += to_string(i);
	}
	for (int v = 1; v < 1024; v++)
	{
		int x = -1;
		
		while(x == -1 || g[x][st(x^v)] >= 0)
			x = rand() % v;
		g[x][st(x^v)] = v;
		g[v][st(x^v)] = x;
	}
	for (int i = 0; i < 1024; i += 2)
	{
		g[i][0] = i + 1;
		g[i + 1][0] = i;
	}
	for (int i = 0; i < 3500; i++)
	{
		int x = -1, y = -1;
		while (x == -1 || g[x][st(x ^ y)] >= 0 || g[y][st(x ^ y)] >= 0 || x == y)
		{
			x = rand() % 1024;
			y = rand() % 1024;
		}
		g[y][st(x^y)] = x;
		g[x][st(x^y)] = y;
	}
	vector<int> cnt(12, 0);
	for (int i = 0; i < 1024; i++)
	{
		int x = 0;
		for (int j = 0; j < 10; j++)
			if (g[i][j] >= 0) x++;
		cnt[x]++;
	}
	for (int i = 0; i <= 10; i++)
		cout << i << " " << cnt[i] << "\n";

	cout << "\n";
	int mn = 100000, mx = -100000, sum = 0, cntt = 0;
	for (int k = 0; k < 100; k++)
	{
		for (int i = 0; i < 1024; i++)
		{
			cntt++;
			step = 0;
			int finish = rand() % 1024;
			//cout << "start " << i << "\n";
			string info = find(i, finish);
			//cout << info << "  : " << finish << " " << "with " << step << " steps\n\n\n";
			sum += step;
			mn = min(mn, step);
			mx = max(mx, step);
		}
	}
	cout << mn << " " << 1.0 * sum / cntt << " " << mx;
}


int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(11);
#ifdef _DEBUG
	auto _ = freopen("input.txt", "r", stdin);
	_ = freopen("output.txt", "w", stdout);
#else
	//auto _ = freopen("input.txt", "r", stdin);
	//_ = freopen("output.txt", "w", stdout);
#endif

	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++)
	{
		solve();
	}
}
