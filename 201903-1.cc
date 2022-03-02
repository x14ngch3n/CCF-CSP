#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int nums[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int max_num = max(nums[0], nums[n - 1]);
    int min_num = min(nums[0], nums[n - 1]);
    int left = nums[n / 2];
    int right = nums[n / 2 - 1];
    double mid_num;
    // just add may cause overflow
    if (n % 2 == 0)
    {
        if (left < right)
            mid_num = (right - left) / 2.0 + left;
        else
            mid_num = (left - right) / 2.0 + right;
    }
    else
        mid_num = left;

    cout << max_num << " ";
    // check if integer
    if (mid_num == (int)mid_num)
        cout << int(mid_num) << " ";
    else
        cout << mid_num << " ";
    cout << min_num << endl;

    return 0;
}