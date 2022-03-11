#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool count_num(const pair<int, int> p1, const pair<int, int> p2)
{
    if (p1.second != p2.second) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

int main(int argc, char const* argv[])
{
    int n, tmp;
    cin >> n;
    map<int, int> nums;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (nums.find(tmp) == nums.end()) {
            nums.insert(make_pair(tmp, 1));
        } else {
            nums.find(tmp)->second++;
        }
    }
    vector<pair<int, int>> vec;
    for (map<int, int>::iterator it = nums.begin(); it != nums.end(); it++) {
        vec.push_back(*it);
    }
    sort(vec.begin(), vec.end(), count_num);
    for (vector<pair<int, int>>::iterator it = vec.begin(); it != vec.end();
         it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}