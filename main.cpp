#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 5e2 + 10, M = 1e4 + 10;

int n, m, k;
int dist[N], last[N];

struct edge
{
    int a, b, w;
} edges[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(last, dist, sizeof dist); // 使用上一次迭代的结果来更新这次的结果
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], last[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) {
        return -1;
    }
    return dist[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    int t = bellman_ford();
    if (t == -1) {
        cout << "impossible" << endl;
    }
    else {
        cout << dist[n] << endl;
    }
    return 0;
}