#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string ISBN;
    getline(cin, ISBN);
    int ID = 0;
    int len = ISBN.size();
    for (int i = 0; i < len - 2; i++)
    {
        if (i != 1 && i != 5)
        {
            ID += (i + 1) * atoi(&ISBN[i]);
        }
    }
    ID = ID % 11;
    char ID_char = (ID == 10) ? 'X' : to_string(ID)[0];
    if (ID_char == ISBN[len - 1])
    {
        cout << "Right" << endl;
    }
    else
    {
        ISBN[len - 1] = ID_char;
        cout << ISBN << endl;
    }
    return 0;
}