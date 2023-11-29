#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

bool generateRandomError(double errorRate) {
    // Generating a random number between 0 and 1
    double randNum = static_cast<double>(rand()) / RAND_MAX;
    return randNum < errorRate;
}

void sender(int frameCount, double errorRate) {
    int frameNumber = 0;
    while (frameNumber < frameCount) {
        cout << "Sender: Sending Frame " << frameNumber << endl;
        
        // Simulating transmission delay
        this_thread::sleep_for(chrono::seconds(1));

        // Simulating acknowledgment receipt
        if (!generateRandomError(errorRate)) {
            cout << "Receiver: Acknowledgment received for Frame " << frameNumber << endl;
            frameNumber++;
        } else {
            cout << "Receiver: Acknowledgment lost for Frame " << frameNumber << ", Resending..." << endl;
        }
    }
    cout << "Sender: Transmission complete." << endl;
}

void receiver(int frameCount, double errorRate) {
    int frameExpected = 0;
    while (frameExpected < frameCount) {
        cout << "Receiver: Waiting for Frame " << frameExpected << endl;
        
        // Simulating reception delay
        this_thread::sleep_for(chrono::seconds(1));

        // Simulating frame received or lost
        if (!generateRandomError(errorRate)) {
            cout << "Sender: Frame " << frameExpected << " received, sending acknowledgment." << endl;
            frameExpected++;
        } else {
            cout << "Sender: Frame " << frameExpected << " lost, requesting retransmission..." << endl;
        }
    }
    cout << "Receiver: Reception complete." << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int frameCount;
    double errorRate;

    cout << "Enter the number of frames to send: ";
    cin >> frameCount;

    cout << "Enter the error rate (between 0 and 1): ";
    cin >> errorRate;

    cout << "\nStarting n-bit Stop-and-Wait Protocol...\n\n";

    // Starting sender and receiver threads
    thread senderThread(sender, frameCount, errorRate);
    thread receiverThread(receiver, frameCount, errorRate);

    senderThread.join();
    receiverThread.join();

    return 0;
}
