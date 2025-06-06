#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int INF = 1e9;
vector<pair<int, int>> vec[N];
int dist[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;


	while (t--)
	{
		int v, e;
		cin >> v >> e;

		cout << "nilai v: " << v << ", dan nilai e: " << e << '\n';

		for (int i = 0; i < v; ++i)
		{
			dist[i] = INF;
			vec[i].clear();
		}

		cout << "nilai dis: ";

		for (int i = 0; i <= v; i++) {
			cout << dist[i] << " ";
		}
		cout << '\n';
		for (int i = 0; i < e; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			cout << "nilai x: " << x << ", nilai y: " << y << ", nilai z: " << z << '\n';
			vec[x].emplace_back(y, z);
		}

		cout << "nilai vec:\n";
		for (int i = 0; i < v; i++) {
			cout << "nilai vec[" << i << "]: ";
			for (auto j : vec[i]) {
				cout << "(" << j.first << ", " << j.second << ") ";
			}
			cout << '\n';
		}

		dist[0] = 0;
		bool updated;
		for (int i = 0; i < v; i++)
		{
			updated = false;
			for (int j = 0; j < v; j++)
			{
				for (int k = 0; k < vec[j].size(); k++)
				{
					cout << "nilai i: " << i << ", nilai j: " << j << ", nilai k: " << k << ", dan nilai vec[j][k]: " << vec[j][k].first << ", " << vec[j][k].second << '\n';
					int a = j;
					int b = vec[j][k].first;
					cout << "nilai a: " << a << ", nilai b: " << b << ", nilai dist[a]: " << dist[a] << ", nilai dist[b]: " << dist[b] << '\n';
					int cost = vec[j][k].second;
					cout << "nilai cost: " << cost << '\n';
					if (dist[a] == INF) continue;
					if (dist[a] + cost < dist[b])
					{
						cout << "masuk dist[a] + cost < dist[b], nilai a: " << a << ", nilai b: " << b << ", nilai dist[a]: " << dist[a] << ", nilai cost: " << cost << ", nilai dist[a] + cost: " << dist[a] + cost << ", nilai dist[b]: " << dist[b] << '\n';
						dist[b] = dist[a] + cost;
						updated = true;
					}
				}
			}
			cout << "akhir dari i: " << i << '\n';
			cout << "nilai dist: ";
			for (int x = 0; x < v; x++) {
				cout << dist[x] << " ";
			}
			cout << '\n' << '\n';
		}
		if (updated)
		{
			cout << "Pak Dengklek tidak mau pulang\n";
		}
		else if (dist[v - 1] == INF)
		{
			cout << "Tidak ada jalan" << '\n';
		}
		else
		{
			cout << dist[v - 1] << '\n';
		}

	}

	return 0;
}
