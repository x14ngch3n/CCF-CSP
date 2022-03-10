#include <bits/stdc++.h>

using namespace std;

#define ADD_DIFF_BYONE(i, j) diffA[i]++, diffA[j + 1]--;

#define N_MAX 1000000
#define A_MAX 10000

// prefix sum and diffrential
int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    int A[N_MAX], diffA[A_MAX];
    A[0] = diffA[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        if (A[i - 1] < A[i]) {
            ADD_DIFF_BYONE(A[i - 1] + 1, A[i]);
        }
    }

    int maxSeg = 0, prefixSum = 0;
    for (int i = 1; i < A_MAX; i++) {
        prefixSum += diffA[i];
        maxSeg = max(maxSeg, prefixSum);
    }
    cout << maxSeg << endl;

    return 0;
}