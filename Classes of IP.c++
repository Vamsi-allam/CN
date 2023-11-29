#include <iostream>
#include <string>

using namespace std;

char findIPClass(string ip) {
    // Extracting the first octet from the IP address
    int firstOctet = stoi(ip.substr(0, ip.find('.')));

    if (firstOctet >= 1 && firstOctet <= 126) {
        return 'A';
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        return 'B';
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        return 'C';
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        return 'D';
    } else if (firstOctet >= 240 && firstOctet <= 255) {
        return 'E';
    } else {
        return 'Invalid';
    }
}

int main() {
    string ipAddress;
    cout << "Enter an IP address: ";
    cin >> ipAddress;

    char ipClass = findIPClass(ipAddress);
    if (ipClass != 'Invalid') {
        cout << "The IP address belongs to Class " << ipClass << endl;
    } else {
        cout << "Invalid IP address entered." << endl;
    }

    return 0;
}
