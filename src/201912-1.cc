#include <iostream>
#include <string>

using namespace std;

bool skip(int n)
{
    string s = to_string(n);
    if (n % 7 == 0 || s.find("7") != string::npos)
        return true;
    else
        return false;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    int skips[4] = { 0 };
    int i = 0, count = 0;
    while (++i && count < n) {
        if (skip(i)) {
            skips[(i - 1) % 4]++;
        } else {
            count++;
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << skips[i] << endl;
    }
    return 0;
}