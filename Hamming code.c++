#include <iostream>
#include <vector>

using namespace std;

// Function to calculate parity bits for a Hamming Code
vector<int> calculateParityBits(vector<int>& data) {
    vector<int> parityBits(3);

    // Calculating parity bits
    parityBits[0] = (data[0] + data[1] + data[3]) % 2;
    parityBits[1] = (data[0] + data[2] + data[3]) % 2;
    parityBits[2] = (data[1] + data[2] + data[3]) % 2;

    return parityBits;
}

// Function to encode a 4-bit message using Hamming Code
vector<int> hammingCodeEncode(vector<int>& data) {
    vector<int> encodedMessage(7);

    // Setting data bits
    encodedMessage[2] = data[0];
    encodedMessage[4] = data[1];
    encodedMessage[5] = data[2];
    encodedMessage[6] = data[3];

    // Calculating parity bits
    vector<int> parityBits = calculateParityBits(encodedMessage);

    // Setting parity bits
    encodedMessage[0] = parityBits[0];
    encodedMessage[1] = parityBits[1];
    encodedMessage[3] = parityBits[2];

    return encodedMessage;
}

// Function to correct errors in a received Hamming Code
vector<int> hammingCodeCorrect(vector<int>& received) {
    vector<int> corrected = received;

    // Calculating syndrome bits
    int s1 = (received[0] + received[2] + received[4] + received[6]) % 2;
    int s2 = (received[1] + received[2] + received[5] + received[6]) % 2;
    int s3 = (received[3] + received[4] + received[5] + received[6]) % 2;

    // Determining error position
    int errorPos = s1 + s2 * 2 + s3 * 4;

    if (errorPos != 0) {
        cout << "Error detected at bit " << errorPos << endl;
        corrected[errorPos - 1] = (corrected[errorPos - 1] + 1) % 2; // Correcting the bit
    } else {
        cout << "No error detected." << endl;
    }

    return corrected;
}

int main() {
    vector<int> message = {1, 0, 1, 0}; // 4-bit message

    // Encoding the message
    vector<int> encoded = hammingCodeEncode(message);

    // Simulating an error in received data
    encoded[3] = 1; // Introducing an error

    // Correcting errors, if any
    vector<int> corrected = hammingCodeCorrect(encoded);

    cout << "Encoded Message: ";
    for (int bit : encoded) {
        cout << bit << " ";
    }
    cout << endl;

    cout << "Corrected Message: ";
    for (int bit : corrected) {
        cout << bit << " ";
    }
    cout << endl;

    return 0;
}
