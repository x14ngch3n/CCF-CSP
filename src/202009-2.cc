#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, k, t;
    int ans[2] = { 0 };
    long long x, y, xMin, yMin, xMax, yMax;
    cin >> n >> k >> t >> xMin >> yMin >> xMax >> yMax;
    for (int i = 0; i < n; i++) {
        int accumulate = 0, pass = 0, stay = 0;
        for (int j = 0; j < t; j++) {
            cin >> x >> y;
            if (xMin <= x && x <= xMax && yMin <= y && y <= yMax) {
                pass = 1;
                accumulate++;
            } else {
                accumulate = 0;
            }
            if (accumulate == k) {
                stay = 1;
                accumulate++;
            }
        }
        ans[0] += pass;
        ans[1] += stay;
    }
    for (int i = 0; i < 2; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}