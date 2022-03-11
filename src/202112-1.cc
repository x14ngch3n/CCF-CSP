#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, N;
    cin >> n >> N;
    int nums[n + 1];
    nums[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> nums[i];
    }
    // time consuming
    // int f[N];
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         if (nums[j] <= i)
    //         {
    //             f[i] = j;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    // }
    // int sum = 0;
    // for (int i = 0; i < N; i++)
    // {
    //     sum += f[i];
    // }
    // time saving
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += i * (nums[i + 1] - nums[i]);
    }
    sum += n * (N - nums[n]);
    cout << sum << endl;
    return 0;
}