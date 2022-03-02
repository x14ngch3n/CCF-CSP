#include <iostream>
#include <vector>
#include <algorithm>

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
    int mediate = -1;
    // O(n^2)
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] < nums[i])
            {
                left++;
            }
            else if (nums[j] > nums[i])
            {
                right++;
            }
        }
        if (left == right)
        {
            mediate = nums[i];
        }
    }
    cout << mediate << endl;

    return 0;
}