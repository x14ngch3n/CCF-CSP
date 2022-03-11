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
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] != prev) {
            prev = nums[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
