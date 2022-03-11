#include <iostream>
#include <map>
#include <stack>

using namespace std;

map<char, char> opcode;

string toRPN(string e)
{
    stack<int> opcodes;
    stack<int> oprands;
    for (int i = 0; i < e.size(); i++) {
        if (isdigit(e[i])) {
            oprands.push(e[i]);
        } else if (opcodes.empty()) {
            opcodes.push(e[i]);
        } else {
            while (!opcodes.empty() && opcode[e[i]] <= opcode[opcodes.top()]) {
                int tmp = opcodes.top();
                opcodes.pop();
                oprands.push(tmp);
            }
            opcodes.push(e[i]);
        }
    }
    while (!opcodes.empty()) {
        int tmp = opcodes.top();
        opcodes.pop();
        oprands.push(tmp);
    }
    char rpn[7];
    for (int i = 0; i < 7; i++) {
        int tmp = oprands.top();
        oprands.pop();
        rpn[6 - i] = tmp;
    }
    string RPN(rpn, 7);
    return RPN;
}

int evalRPN(string rpn)
{
    stack<int> ops;
    for (int i = 0; i < rpn.size(); i++) {
        if (isdigit(rpn[i])) {
            ops.push(rpn[i] - '0');
        } else {
            int op1 = ops.top();
            ops.pop();
            int op2 = ops.top();
            ops.pop();
            switch (rpn[i]) {
            case '+':
                ops.push(op1 + op2);
                break;

            case '-':
                ops.push(op2 - op1);
                break;

            case 'x':
                ops.push(op1 * op2);
                break;

            case '/':
                ops.push(op2 / op1);
                break;

            default:
                break;
            }
        }
    }
    return ops.top();
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    opcode.insert(pair<int, int>('+', 0));
    opcode.insert(pair<int, int>('-', 0));
    opcode.insert(pair<int, int>('x', 1));
    opcode.insert(pair<int, int>('/', 1));
    for (int i = 0; i < n; i++) {
        string e, rpn;
        cin >> e;
        rpn = toRPN(e);
        cout << (evalRPN(rpn) == 24 ? "Yes" : "No") << endl;
    }

    return 0;
}