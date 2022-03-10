#include <bits/stdc++.h>

using namespace std;

// O(n^2), cause TLE
int getNonzeroSeg(int A[], int n, int p)
{
    // p-operation
    for (int i = 0; i < n; i++) {
        A[i] = (A[i] < p) ? 0 : A[i];
    }
    // count all-zero segments
    int count = 0;
    int prev = 1;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0 && prev != 0) {
            count++;
        }
        prev = A[i];
    }
    return count + 1 - (A[0] == 0) - (A[n - 1] == 0);
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    int A[n];
    int AMax = 0;
    // set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        // s.insert(A[i]);
        AMax = max(AMax, A[i]);
    }
    int maxSeg = 0;
    // check if has reach max
    if (getNonzeroSeg(A, n, 1) == (n + 1) / 2) {
        cout << (n + 1) / 2 << endl;
    } else {
        // for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        for (int i = 1; i <= AMax; i++) {
            int seg = getNonzeroSeg(A, n, i);
            maxSeg = max(seg, maxSeg);
        }
        cout << maxSeg << endl;
    }
    return 0;
}