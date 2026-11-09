// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<long long>> a(n, vector<long long>(m));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cin >> a[i][j];

//     vector<vector<long long>> dp(n, vector<long long>(m));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (i == 0 && j == 0) {
//                 dp[i][j] = a[i][j];
//             } else if (i == 0) {
//                 dp[i][j] = dp[i][j - 1] + a[i][j];
//             } else if (j == 0) {
//                 dp[i][j] = dp[i - 1][j] + a[i][j];
//             } else {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
//             }
//         }
//     }

//     // Восстановление пути от правого нижнего угла к началу
//     vector<pair<int, int>> path;
//     int i = n - 1, j = m - 1;
//     path.push_back({i, j});
//     while (i > 0 || j > 0) {
//         if (i == 0) {
//             j--;
//         } else if (j == 0) {
//             i--;
//         } else if (dp[i - 1][j] >= dp[i][j - 1]) {
//             i--;
//         } else {
//             j--;
//         }
//         path.push_back({i, j});
//     }
//     reverse(path.begin(), path.end());

//     for (auto &p : path)
//         cout << p.first << " " << p.second << "\n";

//     return 0;
// }

// Задание 2
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
//
// int main() {
//     int n, d;
//     cin >> n >> d;
//
//     vector<long long> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     sort(a.begin(), a.end());
//
//     long long lo = 0, hi = a[n - 1] - a[0];
//     while (lo < hi) {
//         long long mid = lo + (hi - lo) / 2;
//
//         // сколько дней нужно, чтобы разница в каждом дне была <= mid
//         int days = 1;
//         long long start = a[0];
//         for (int i = 1; i < n; i++) {
//             if (a[i] - start > mid) {
//                 days++;
//                 start = a[i];
//             }
//         }
//
//         if (days <= d) hi = mid;
//         else lo = mid + 1;
//     }
//
//     cout << lo << endl;
//     return 0;
// }
//
// Задание 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<long long>());

    long long sum = 0;
    int left = k;
    for (int i = 0; i < n && left > 0; i++) {
        int take = min(l, left);
        sum += (long long)take * a[i];
        left -= take;
    }

    cout << sum << endl;
    return 0;
}

// Задание 4

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<char>> g(n, vector<char>(m));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cin >> g[i][j];   // работает и с пробелами, и без них

//     if (g[0][0] == '1') {
//         cout << -1 << endl;
//         return 0;
//     }

//     vector<vector<bool>> vis(n, vector<bool>(m, false));
//     queue<pair<int, int>> q;
//     q.push({0, 0});
//     vis[0][0] = true;

//     int pdf = 0;
//     bool exitFound = false;
//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     while (!q.empty()) {
//         auto [x, y] = q.front();
//         q.pop();

//         if (g[x][y] == 'P') pdf++;
//         if (g[x][y] == 'E') exitFound = true;

//         for (int d = 0; d < 4; d++) {
//             int nx = x + dx[d], ny = y + dy[d];
//             if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
//             if (g[nx][ny] == '1' || vis[nx][ny]) continue;
//             vis[nx][ny] = true;
//             q.push({nx, ny});
//         }
//     }

//     if (exitFound) cout << pdf << endl;
//     else cout << -1 << endl;

//     return 0;
// }