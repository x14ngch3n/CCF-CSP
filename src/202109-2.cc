#include <bits/stdc++.h>

using namespace std;

#define ADD_DIFF_BYONE(i, j) diffP[i]++, diffP[j + 1]--;

#define N_MAX 1000000
#define A_MAX 10000

// prefix sum and diffrential
// https://www.cnblogs.com/yongcheng137blogs/p/15396599.html
// https://www.cnblogs.com/yongcheng137blogs/p/15412952.html
int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    // diffP is the diffrential sequence of distribution of p
    int A[N_MAX], diffP[A_MAX];
    A[0] = diffP[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        if (A[i - 1] < A[i]) {
            // may cause nonzero segment
            ADD_DIFF_BYONE(A[i - 1] + 1, A[i]);
        }
    }

    int maxSeg = 0, prefixSum = 0;
    // revserse computing diffP(accumulation) to get the P's distribution
    for (int i = 1; i < A_MAX; i++) {
        prefixSum += diffP[i];
        maxSeg = max(maxSeg, prefixSum);
    }
    cout << maxSeg << endl;

    return 0;
}