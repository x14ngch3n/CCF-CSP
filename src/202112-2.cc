#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(int argc, char const* argv[])
{
    ll n, N;
    cin >> n >> N;
    ll A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll gap = N / (n + 1);
    ll len = (N % gap == 0) ? (N / gap) - 1 : (N / gap);
    ll G[len];
    for (ll i = 0; i < len; i++) {
        G[i] = gap * (i + 1);
    }

    // merge to one array, 0 for A, 1 for G
    vector<pair<ll, ll>> AG;
    AG.push_back(make_pair(0, 0));
    ll i = 0, j = 0;
    while (i < n && j < len) {
        if (A[i] == G[j]) {
            AG.push_back(make_pair(A[i], 2));
            i++;
            j++;
        } else if (A[i] > G[j]) {
            AG.push_back(make_pair(G[j], 1));
            j++;
        } else if (A[i] < G[j]) {
            AG.push_back(make_pair(A[i], 0));
            i++;
        }
    }
    if (i == n) {
        while (j < len) {
            AG.push_back(make_pair(G[j], 1));
            j++;
        }
    } else if (j == len) {
        while (i < n) {
            AG.push_back(make_pair(A[i], 0));
            i++;
        }
    }

    // traverse AG to computer the diff at each stage
    ll error = 0, f = 0, g = 0;
    for (ll i = 1; i < AG.size(); i++) {
        error += abs((f - g) * (AG[i].first - AG[i - 1].first));
        if (AG[i].second == 0) {
            f++;
        } else if (AG[i].second == 1) {
            g++;
        } else if (AG[i].second == 2) {
            f++;
            g++;
        }
    }

    error += abs((f - g) * (N - AG[AG.size() - 1].first));
    cout << error << endl;

    return 0;
}