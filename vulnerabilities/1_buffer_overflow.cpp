using namespace std;

#include <iostream>
#include <cstring>

int main() {
    char buffer[5]; //character buffer
    cout << "What's your name?"; //Program asks user
    cin >> buffer; //Input stored into buffer
    cout << buffer << endl; // Name stored in buffer is printed out

    return 0;
}