#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inputFile("./Act1.1_casos/1.in");
    
    if (!inputFile.is_open()) {
        cerr << "Could not open the input file." << endl;
        return 1;
    }
    
    string line;
    while (getline(inputFile, line)) {
        // Process the line
        cout << line << endl; // Print the line as an example
    }
    
    inputFile.close();
    
    return 0;
}
