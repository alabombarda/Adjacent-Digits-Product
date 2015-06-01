#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

long long int adjDigProduct(vector<int> NUMB, int digits, long long int biggest);
vector<int> vectorify(string s);

int main()
{
    long long int biggest = 0;
    string input;
    int numDigits;

    cout << "Enter a REALLY big number!\n";
    getline(cin, input);
    cout << "How many adjacent digits?\n";
    cin >> numDigits;

    vector<int> v = vectorify(input);

    cout << "The biggest product for " << numDigits << " digits is " << adjDigProduct(v, numDigits, biggest) << ".\n";
}

long long int adjDigProduct(vector<int> NUMB, int digits, long long int biggest)
{
    if (NUMB.size() < digits)
        return biggest;

    long long int product = 1;

    for (int i = 0; i < digits; i++)
    {
        product *= NUMB[i];
    }

    NUMB.erase(NUMB.begin());

    if (product > biggest)
        adjDigProduct(NUMB, digits, product);
    else
        adjDigProduct(NUMB, digits, biggest);
}

vector<int> vectorify(string s)
{
    vector<int> v;

    char cArray[s.length()];
    strcpy(cArray, s.c_str());

    for (int i = 0; i < s.length(); i++)
    {
        v.push_back((cArray[i] - '0'));
    }

    return v;
}
