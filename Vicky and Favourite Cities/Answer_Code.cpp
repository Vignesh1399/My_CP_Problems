#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI (atan(1) *4)
#define mp make_pair
using namespace std;

ofstream out;
ifstream in ;

const int max_test_files = 8;
const int maxn = 1e6;
vector<int> adjlist[maxn + 1];
int n, m;
vector<int> height(maxn + 1, 0), vis(maxn + 1, 0);

void dfs(int cur)
{
	vis[cur] = 1;
	for (auto u: adjlist[cur])
	{
		if (vis[u])
			continue;
		height[u] = height[cur] + 1;
		dfs(u);
	}
}

void solve()
{
	in >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		adjlist[i].clear();
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v; in >> u >> v;
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	
	dfs(1);
	int x = max_element(height.begin() + 1, height.end()) - height.begin();
	fill(height.begin(), height.end(), 0);
	fill(vis.begin(), vis.end(), 0);
	dfs(x);
	out << *max_element(height.begin() + 1, height.end()) + 1 << endl;
	fill(height.begin(), height.end(), 0);
	fill(vis.begin(), vis.end(), 0);
}

//end of test_specific contents

int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++)
	{
		string file_name_ip = "input" + to_string(i) + ".txt";
		string file_name_op = "output" + to_string(i) + ".txt"; in .open(file_name_ip.c_str(), std::ifstream:: in);
		out.open(file_name_op.c_str(), std::ofstream::out | std::ofstream::trunc);
		assert(out.is_open());
		assert(in .is_open());
		solve();
		out.close(); in .close();
		assert(! in .is_open());
		assert(!out.is_open());
	}

	return 0;
}