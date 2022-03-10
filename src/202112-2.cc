#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 100000

// binary search, O(lgN)
// int getFx(int A[], int n, int x)
// {
//     int left = 0, right = n;
//     if (x >= A[n]) {
//         return n;
//     }
//     while (left < right - 1) {
//         int mid = (right - left) / 2 + left;
//         if (A[mid] <= x) {
//             left = mid;
//         } else if (A[mid] > x) {
//             right = mid;
//         }
//     }
//     return left;
// }

int getGx(int A[], int n, int N, int x)
{
    int r = N / (n + 1);
    int g = x / r;
    return g;
}

int main(int argc, char const* argv[])
{
    int n, N;
    cin >> n >> N;
    int A[MAX_LEN] = { 0 };
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    int f, g, error = 0, j = 0;
    // O(n)
    for (int i = 0; i < N; i++) {
        // f = getFx(A, n, i);
        if (i == A[j]) {
            f = j;
            j++;
        }
        g = getGx(A, n, N, i);

        error += abs(f - g);
    }
    cout << error << endl;

    return 0;
}