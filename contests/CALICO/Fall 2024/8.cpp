#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> Tab(N);
        int startx = 0, starty = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> Tab[i];
            for (int j = 0; j < M; j++)
            {
                if (Tab[i][j] == 'S')
                    startx = i, starty = j;
            }
        }
        deque<vector<int>> Q;
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(2, -1)));
        vector<vector<pair<int, int>>> L(N, vector<pair<int, int>>(M, {2000001, 1})), R(N, vector<pair<int, int>>(M, {2000001, 1})), U(N, vector<pair<int, int>>(M, {2000001, 1})), D(N, vector<pair<int, int>>(M, {2000001, 1}));

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < M; j++)
            {
                L[i][j].first = L[i - 1][j].first + 1;
                U[i][j].first = U[i][j - 1].first + 1;
                if (Tab[i][j] == '#')
                {
                    L[i][j].first = 2000001;
                    U[i][j].first = 2000001;
                }
                if (L[i][j].first <= K)
                    L[i][j].second = 0;
                if (U[i][j].first <= K)
                    U[i][j].second = 0;
                if (Tab[i][j] == '*')
                {
                    L[i][j].first = U[i][j].first = 0;
                }
            }
        }
        for (int i = N - 2; i >= 0; i--)
        {
            for (int j = M - 2; j >= 0; j--)
            {
                R[i][j].first = R[i + 1][j].first + 1;
                D[i][j].first = D[i][j + 1].first + 1;
                if (Tab[i][j] == '#')
                {
                    R[i][j].first = 2000001;
                    D[i][j].first = 2000001;
                }
                if (R[i][j].first <= K)
                    R[i][j].second = 0;
                if (D[i][j].first <= K)
                    D[i][j].second = 0;
                if (Tab[i][j] == '*')
                {
                    R[i][j].first = D[i][j].first = 0;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                L[i][j].first = -1;
                R[i][j].first = -1;
                U[i][j].first = -1;
                D[i][j].first = -1;
            }
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < M; j++)
            {
                L[i][j].first = L[i - 1][j].first + 1;
                U[i][j].first = U[i][j - 1].first + 1;
                L[i][j].first = min(L[i][j].first, K);
                U[i][j].first = min(U[i][j].first, K);
                if (Tab[i][j] == '#')
                {
                    L[i][j].first = U[i][j].first = -1;
                }
            }
        }
        for (int i = N - 2; i >= 0; i--)
        {
            for (int j = M - 2; j >= 0; j--)
            {
                R[i][j].first = R[i + 1][j].first + 1;
                D[i][j].first = D[i][j + 1].first + 1;
                R[i][j].first = min(R[i][j].first, K);
                D[i][j].first = min(D[i][j].first, K);
                if (Tab[i][j] == '#')
                {
                    R[i][j].first = D[i][j].first = -1;
                }
            }
        }
        dp[startx][starty][0] = 0;
        Q.push_back({startx, starty, 0});
        int noans = 1;
        while (!Q.empty())
        {
            int x = Q.front()[0], y = Q.front()[1], t = Q.front()[2];
            Q.pop_front();
            if (Tab[x][y] == '*' && dp[x][y][0] == -1)
            {
                dp[x][y][0] = dp[x][y][t];
                Q.push_front({x, y, 0});
            }
            if (Tab[x][y] == 'E')
            {
                noans = 0;
                cout << dp[x][y][t] << '\n';
                break;
            }
            if (Tab[x + 1][y] != '#' && dp[x + 1][y][t] == -1)
            {
                dp[x + 1][y][t] = dp[x][y][t] + 1;
                Q.push_back({x + 1, y, t});
            }
            if (Tab[x - 1][y] != '#' && dp[x - 1][y][t] == -1)
            {
                dp[x - 1][y][t] = dp[x][y][t] + 1;
                Q.push_back({x - 1, y, t});
            }
            if (Tab[x][y + 1] != '#' && dp[x][y + 1][t] == -1)
            {
                dp[x][y + 1][t] = dp[x][y][t] + 1;
                Q.push_back({x, y + 1, t});
            }
            if (Tab[x][y - 1] != '#' && dp[x][y - 1][t] == -1)
            {
                dp[x][y - 1][t] = dp[x][y][t] + 1;
                Q.push_back({x, y - 1, t});
            }
            if (t == 0)
            {
                if (Tab[x + R[x][y].first][y] != '#' && dp[x + R[x][y].first][y][R[x][y].second] == -1)
                {
                    dp[x + R[x][y].first][y][R[x][y].second] = dp[x][y][t] + 1;
                    Q.push_back({x + R[x][y].first, y, R[x][y].second});
                }
                if (Tab[x - L[x][y].first][y] != '#' && dp[x - L[x][y].first][y][L[x][y].second] == -1)
                {
                    dp[x - L[x][y].first][y][L[x][y].second] = dp[x][y][t] + 1;
                    Q.push_back({x - L[x][y].first, y, L[x][y].second});
                }
                if (Tab[x][y + D[x][y].first] != '#' && dp[x][y + D[x][y].first][D[x][y].second] == -1)
                {
                    dp[x][y + D[x][y].first][D[x][y].second] = dp[x][y][t] + 1;
                    Q.push_back({x, y + D[x][y].first, D[x][y].second});
                }
                if (Tab[x][y - U[x][y].first] != '#' && dp[x][y - U[x][y].first][U[x][y].second] == -1)
                {
                    dp[x][y - U[x][y].first][U[x][y].second] = dp[x][y][t] + 1;
                    Q.push_back({x, y - U[x][y].first, U[x][y].second});
                }
            }
        }
        if (noans)
            cout << -1 << '\n';
    }
}

