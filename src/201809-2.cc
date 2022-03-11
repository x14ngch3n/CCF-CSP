#include <iostream>

using namespace std;

#define LEN 1000000
int chat[LEN] = { 0 };

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    int start, end;
    for (int i = 0; i < 2 * n; i++) {
        cin >> start >> end;
        for (int j = start; j < end; j++) {
            chat[j]++;
        }
    }
    int chatTime = 0;
    for (int i = 0; i < LEN; i++) {
        if (chat[i] == 2) {
            chatTime++;
        }
    }
    cout << chatTime << endl;

    return 0;
}