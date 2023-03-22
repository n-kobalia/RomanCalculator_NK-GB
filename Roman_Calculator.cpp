
#include <iostream>

using namespace std;

int numerial(char roman)
{
    switch (roman)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    }
    return 0;
};

int romantToNum(string roman)
{
    int i, NumOfChar, PreviousChar = 0, Answer = 0;

    NumOfChar = roman.length() - 1;

    for (i = NumOfChar; i >= 0; i--)
    {
        if (numerial(roman[i]) >= PreviousChar)
        {
            Answer = Answer + numerial(roman[i]);
        }
        else
        {
            Answer = Answer - numerial(roman[i]);
        }

        PreviousChar = numerial(roman[i]);
    }

    return Answer;
};

void calculator()
{
    bool done = false;
    string RomNum;
    int result = 0;
    char op;
    char quit;

    while (!done)
    {

        cout << "Enter operation +, -, *, / or 0 to quit: ";
        cin >> op;
        if (op == '0')
        {
            break;
        };

        cout << "Enter Roman Number or 0 to quit: ";
        cin >> RomNum;

        if (RomNum == "0")
        {
            break;
        };

        switch (op)
        {
        case '+':
            result += romantToNum(RomNum);
            break;
        case '-':
            result -= romantToNum(RomNum);
            break;
        case '*':
            result *= romantToNum(RomNum);
            break;
        case '/':
            result /= romantToNum(RomNum);
            break;
        };
    };

    cout << result;
}

int main()
{

    calculator();

    return 0;
}
