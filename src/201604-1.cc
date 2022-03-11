#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        if ((nums[i] - nums[i - 1]) * (nums[i + 1] - nums[i]) < 0) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
