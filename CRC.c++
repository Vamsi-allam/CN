#include <iostream>
#include <vector>
using namespace std;
vector<int> crcDivision(vector<int>& message, vector<int>& polynomial) {
    int m = message.size();
    int n = polynomial.size();
    vector<int> dividend(m + n - 1, 0);
    vector<int> remainder(n - 1, 0);
    for (int i = 0; i < m; ++i) {
        dividend[i] = message[i];
    }
    for (int i = 0; i < m; ++i) {
        int index = 0;
        if (dividend[i] == 1) {
            for (int j = i; j < i + n; ++j) {
                dividend[j] = (dividend[j] ^ polynomial[index++]);
            }
        }
    }
    for (int i = m, j = 0; i < m + n - 1; ++i, ++j) {
        remainder[j] = dividend[i];
    }
    return remainder;
}
int main() {
    vector<int> message = {1, 0, 1, 0, 1}; // Message: 10101
    vector<int> polynomial = {1, 0, 0, 1}; // Polynomial: x^3 + 1
    vector<int> remainder = crcDivision(message, polynomial);
    cout << "Message: ";
    for (int bit : message) {
        cout << bit;
    }
    cout << endl;
    cout << "Polynomial: ";
    for (int bit : polynomial) {
        cout << bit;
    }
    cout << endl;
    cout << "Remainder (CRC): ";
    for (int bit : remainder) {
        cout << bit;
    }
    cout << endl;
    return 0;
}

// OUTPUT :
// Message: 10101
// Polynomial: 1001
// Remainder (CRC): 111
