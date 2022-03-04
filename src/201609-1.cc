#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int vibrate = 0;
    for (int i = 1; i < n; i++)
    {
        vibrate = max(vibrate, abs(nums[i] - nums[i - 1]));
    }
    cout << vibrate << endl;
    return 0;
}