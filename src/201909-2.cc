#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    int apples;
    bool isDroped = false;
};

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    vector<Tree> trees(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        cin >> trees[i].apples;
        int tmp;
        for (int j = 1; j < m; j++) {
            cin >> tmp;
            if (tmp <= 0) {
                trees[i].apples += tmp;
            } else if (trees[i].apples > tmp) {
                trees[i].isDroped = true;
                trees[i].apples = tmp;
            }
        }
    }
    int T = 0, D = 0, E = 0;
    for (int i = 0; i < n; i++) {
        T += trees[i].apples;
        if (trees[i].isDroped) {
            D++;
        }
        if (trees[i].isDroped && trees[(i + 1) % n].isDroped && trees[(i + 2) % n].isDroped) {
            E++;
        }
    }
    cout << T << " " << D << " " << E << endl;

    return 0;
}