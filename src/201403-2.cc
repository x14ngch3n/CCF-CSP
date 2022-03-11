#include <iostream>
#include <vector>

using namespace std;

bool inWindow(int click[2], vector<int> window)
{
    return (click[0] >= window[0] && click[0] <= window[2] && click[1] >= window[1] && click[1] <= window[3])
        ? true
        : false;
}

// in-place rearrange
void reArrange(vector<vector<int>>& windows, int i)
{
    vector<int> window = windows[i];
    windows.erase(windows.begin() + i);
    windows.push_back(window);
}

int main(int argc, char const* argv[])
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> windows(N, vector<int>(5));
    // insert vector reversely
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> windows[i][j];
        }
        // windows[i][4] represents window serial number
        windows[i][4] = i + 1;
    }

    int clicks[M][2];
    for (int i = 0; i < M; i++) {
        cin >> clicks[i][0] >> clicks[i][1];
    }

    for (int i = 0; i < M; i++) {
        int flag = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (inWindow(clicks[i], windows[j])) {
                cout << windows[j][4] << endl;
                reArrange(windows, j);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "IGNORED" << endl;
        }
    }

    return 0;
}