#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 100000

int main(int argc, char const* argv[])
{
    int n, N;
    cin >> n >> N;
    int A[MAX_LEN] = { 0 };
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    // two pointer, O(N), still TLE
    int error = 0, gap = N / (n + 1);
    int f = 0, g = 0, prev = 0;
    for (int i = 1; i < N; i++) {
        int isChanged = 0;
        if (i == A[f + 1]) {
            error += abs((f - g) * (i - prev));
            prev = i;
            isChanged = 1;
            f++;
        }
        if (i % gap == 0) {
            if (!isChanged) {
                error += abs((f - g) * (i - prev));
                prev = i;
            }
            g++;
        }
    }
    error += abs((f - g) * (N - prev));
    cout << error << endl;

    return 0;
}