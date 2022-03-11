#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    map<int, int> nums;
    map<int, int>::iterator it;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        it = nums.find(tmp);
        if (it != nums.end()) {
            it->second++;
        } else {
            nums.insert(pair<int, int>(tmp, 1));
        }
    }
    int max_num = 0;
    for (it = nums.begin(); it != nums.end(); it++) {
        max_num = max(max_num, it->second);
    }
    int ans = 10000;
    for (it = nums.begin(); it != nums.end(); it++) {
        if (it->second == max_num) {
            ans = min(ans, it->first);
        }
    }
    cout << ans << endl;
    return 0;
}