#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, m;
    cin >> n >> m;
    int apples[n][m + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) {
            cin >> apples[i][j];
        }
    }
    vector<int> remains(n);
    vector<int> discards(n);
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n; j++) {
            remains[j] += apples[j][i];
            if (i) {
                discards[j] -= apples[j][i];
            }
        }
    }
    int T = 0, k = 0, P = 0;
    for (int i = 0; i < n; i++) {
        T += remains[i];
        if (discards[i] > P) {
            k = i + 1;
            P = discards[i];
        }
    }
    cout << T << " " << k << " " << P << endl;
    return 0;
}