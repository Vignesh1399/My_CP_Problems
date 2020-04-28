#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI (atan(1)*4)
#define mp make_pair
using namespace std;



ifstream in;

const int max_test_files = 8;



//test_specific contents
const int maxn = 1e6;
const ll maxval = 1e9;
int vis[maxn + 1];
vector<int> adjlist[maxn + 1];

void dfs(int cur) {
	vis[cur] = 1;
	for (auto u : adjlist[cur]) {
		if (vis[u])
			continue;
		dfs(u);
	}
}


void check() {
	int n,m;
	in >> n >> m;
	assert(n >= 1);
	assert(n <= maxn);
  assert(m == n-1);
	for (int i = 1; i < n; i++) {
		int u, v;
		in >> u >> v;
    assert(u >= 1);
		assert(u <= maxn);
    assert(v >= 1);
		assert(v <= maxn);
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		assert(vis[i] == 1);
}
//end of test_specific contents


int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name = "input" + to_string(i) + ".txt";
		in.open(file_name.c_str(), std::ifstream::in);
		assert(in.is_open());
		check();
		in.close();
		assert(!in.is_open());
	}
	return 0;
}