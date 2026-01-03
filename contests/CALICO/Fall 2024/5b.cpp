#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long T;
    cin >> T;
    while (T--)
    {
        long long B, N;
        cin >> B >> N;
        vector<long long> Tab(N);
        long long cost = 0;
        for (long long i = 0; i < N; i++)
        {
            cin >> Tab[i];
            cost += Tab[i];
        }
        sort(Tab.begin(), Tab.end());
        long long cur = 0, ans = -1;
        for (long long i = 0; i < N; i++)
        {
            long long next = Tab[i];
            cost -= (long long)(N - i) * (long long)(next - cur);
            cur = next;
            if (cost <= B)
            {
                ans = cur - (long long)floor((long long)(B - cost) / (long long)(N - i));
                break;
            }
        }
        if (ans < 0)
            ans = 0;
        cout << ans << '\n';
    }
}
