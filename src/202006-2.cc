#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;

    // Time Limit Exceed
    // map<long long, long long> v1, v2;
    // set<long long> index1, index2;
    // int index, value;
    // for (int i = 0; i < a; i++) {
    //     cin >> index >> value;
    //     index1.insert(index);
    //     v1.insert(make_pair(index, value));
    // }
    // for (int i = 0; i < b; i++) {
    //     cin >> index >> value;
    //     index2.insert(index);
    //     v2.insert(make_pair(index, value));
    // }
    // set<int> commonIndex;
    // set_intersection(index1.begin(), index1.end(), index2.begin(),
    // index2.end(), inserter(commonIndex, commonIndex.begin())); long long sum =
    // 0; for (auto it = commonIndex.begin(); it != commonIndex.end(); it++) {
    //     sum += v1[*it] * v2[*it];
    // }

    map<int, int> v1;
    int index, value;
    for (int i = 0; i < a; i++) {
        cin >> index >> value;
        v1.insert(make_pair(index, value));
    }
    long long sum = 0;
    for (int i = 0; i < b; i++) {
        cin >> index >> value;
        if (v1.find(index) != v1.end()) {
            sum += v1[index] * value;
        }
    }
    cout << sum << endl;

    return 0;
}