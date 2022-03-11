#include <iostream>

using namespace std;

#define COUNT(pre, stage, ratio) \
    (tax + pre - stage * ratio / 100) * 100 / (100 - ratio)

int main(int argc, char const* argv[])
{
    int tax;
    cin >> tax;
    int salary = 0;
    // counting by hand
    // a better method is count these stage and accumulated tax in C++
    if (tax <= 3500) {
        salary = tax;
    } else if (tax <= 5000 - 45) {
        salary = COUNT(0, 3500, 3);
    } else if (tax <= 8000 - 345) {
        salary = COUNT(45, 5000, 10);
    } else if (tax <= 12500 - 1245) {
        salary = COUNT(345, 8000, 20);
    } else if (tax <= 38500 - 7745) {
        salary = COUNT(1245, 12500, 25);
    } else if (tax <= 58500 - 13745) {
        salary = COUNT(7745, 38500, 30);
    } else if (tax <= 83500 - 22495) {
        salary = COUNT(13745, 58500, 35);
    } else if (83500 - 22495 < tax) {
        salary = COUNT(22495, 83500, 45);
    }
    cout << salary << endl;
    return 0;
}