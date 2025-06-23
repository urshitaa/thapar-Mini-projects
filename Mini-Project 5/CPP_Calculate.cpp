#include <iostream>
#include <fstream>
#include <cctype>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
    ifstream inFile("1000MBFile.txt", ios::in | ios::binary);
    ofstream outFile("Uppercase.txt", ios::out | ios::binary);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    auto start = high_resolution_clock::now();

    const size_t BUFFER_SIZE = 8192;  // 8 KB
    vector<char> buffer(BUFFER_SIZE);

    while (inFile.read(buffer.data(), buffer.size()) || inFile.gcount() > 0) {
        size_t bytesRead = inFile.gcount();
        for (size_t i = 0; i < bytesRead; ++i) {
            buffer[i] = toupper((unsigned char)buffer[i]);
        }
        outFile.write(buffer.data(), bytesRead);
    }

    auto end = high_resolution_clock::now();
    duration<double> time_taken = end - start;

    cout << "File converted to uppercase successfully.\n";
    cout << "Time taken: " << time_taken.count() << " seconds\n";

    inFile.close();
    outFile.close();

    return 0;
}
