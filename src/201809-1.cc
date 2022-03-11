#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    int firstday[n];
    for (int i = 0; i < n; i++) {
        cin >> firstday[i];
    }
    int secondday[n];
    // implicit type cast
    secondday[0] = (firstday[0] + firstday[1]) / 2;
    secondday[n - 1] = (firstday[n - 1] + firstday[n - 2]) / 2;
    for (int i = 1; i < n - 1; i++) {
        secondday[i] = (firstday[i - 1] + firstday[i] + firstday[i + 1]) / 3;
    }
    for (int i = 0; i < n; i++) {
        cout << secondday[i] << " ";
    }
    cout << endl;

    return 0;
}