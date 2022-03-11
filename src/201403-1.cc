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
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (abs(nums[i] + nums[j]) == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}