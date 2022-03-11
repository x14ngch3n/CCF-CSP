#include <iostream>

using namespace std;

int sum(int nums[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    return sum;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    int B[n];
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    int A_max[n], A_min[n];
    A_max[0] = A_min[0] = B[0];
    for (int i = 1; i < n; i++) {
        if (B[i] > B[i - 1]) {
            A_max[i] = A_min[i] = B[i];
        } else if (B[i] == B[i - 1]) {
            A_max[i] = B[i];
            A_min[i] = 0;
        }
    }
    cout << sum(A_max, n) << endl;
    cout << sum(A_min, n) << endl;
    return 0;
}