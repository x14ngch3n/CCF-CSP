#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define DIST(pos) (sqrt(pow((pos[0] - dst[0]), 2) + pow((pos[1] - dst[1]), 2)))

int dst[2];

bool closer(const vector<int> pos1, const vector<int> pos2)
{
    double dist1 = DIST(pos1);
    double dist2 = DIST(pos2);
    if (dist1 == dist2)
        return pos1[2] < pos2[2];
    else
        return dist1 < dist2;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n >> dst[0] >> dst[1];
    vector<vector<int>> pos(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pos[i].push_back(x);
        pos[i].push_back(y);
        pos[i].push_back(i + 1);
    }
    sort(pos.begin(), pos.end(), closer);
    for (int i = 0; i < 3; i++)
        cout << pos[i][2] << endl;
    return 0;
}