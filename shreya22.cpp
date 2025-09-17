#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<long long> row(N + 1, 0), col(N + 1, 0);

    for (int i = 0; i < Q; ++i) {
        string t; int idx; long long x;
        cin >> t >> idx >> x;
        if (t == "WaterRow")    row[idx] += x;
        else  col[idx] += x;
    }

    long long rmax = *max_element(row.begin(), row.end());
    long long cmax = *max_element(col.begin(), col.end());
    cout << rmax + cmax << '\n';
    return 0;
}
