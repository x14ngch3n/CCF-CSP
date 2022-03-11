#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int min_abs = 10000;
    for (int i = 1; i < n; i++) {
        min_abs = min(min_abs, nums[i] - nums[i - 1]);
    }
    cout << min_abs << endl;
    return 0;
}