#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    string ISBN;
    getline(cin, ISBN);
    int ID = 0, cnt = 0;
    int len = ISBN.size();
    for (int i = 0; i < len - 1; i++) {
        if (isdigit(ISBN[i])) {
            ID += (++cnt) * (ISBN[i] - '0');
        }
    }
    char ID_char = (ID % 11 == 10) ? 'X' : ID % 11 + '0';
    if (ID_char == ISBN[len - 1]) {
        cout << "Right" << endl;
    } else {
        ISBN[len - 1] = ID_char;
        cout << ISBN << endl;
    }
    return 0;
}