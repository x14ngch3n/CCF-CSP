#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, k;
    cin >> n >> k;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int count = 0, weight = 0;
    for (int i = 0; i < n; i++) {
        if (weight < k) {
            weight += nums[i];
        } else {
            weight = nums[i];
            count++;
        }
    }
    cout << count + 1 << endl;
    return 0;
}