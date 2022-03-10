#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    int A[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // O(n^4), cause TLE
    // int count = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int num = 0, sum = 0;
    //         for (int k = max(0, i - r); k <= min(n - 1, i + r); k++) {
    //             for (int l = max(0, j - r); l <= min(n - 1, j + r); l++) {
    //                 num++;
    //                 sum += A[k][l];
    //             }
    //         }
    //         if (t * num >= sum) {
    //             count++;
    //         }
    //     }
    // }

    // Using the similar idea as prefix sum, O(n^2)
    int ASum[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        ASum[i][0] = 0;
        ASum[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ASum[i][j] = A[i - 1][j - 1] + ASum[i - 1][j] + ASum[i][j - 1] - ASum[i - 1][j - 1];
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int xMin = max(1, i - r);
            int xMax = min(n, i + r);
            int yMin = max(1, j - r);
            int yMax = min(n, j + r);

            int num = (xMax - xMin + 1) * (yMax - yMin + 1);
            int sum = ASum[xMax][yMax] - ASum[xMax][yMin - 1] - ASum[xMin - 1][yMax] + ASum[xMin - 1][yMin - 1];
            if (t * num >= sum) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}