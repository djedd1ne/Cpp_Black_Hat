using namespace std;

#include <iostream>

int main() {
    char input[100]; // Create char array, hold 100 characters
    cout << "Enter your name: "; // Ask the user for input
    cin >> input; // Store input into input var
    printf(input); // Print out the user's name ,no format string validation
    return 0;
}