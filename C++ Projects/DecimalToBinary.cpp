
#include <iostream>
#include <cmath>
using namespace std;

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
        return 1;
    }
    int value = stack[top];
    top--;
    return value;
}

bool isEmpty() {
    return top == -1;
}

void decimalToBinary(int num) {
    while (num != 0) {
        push(num % 2);
        num /= 2;
    }
    while (!isEmpty()) {
        cout << pop();
    }
}

int binaryToDecimal(string binary) {
    int decimal = 0;
    for (int i = 0; i < binary.length(); i++) {
        int bit = binary[i] - '0';
        push(bit);
    }
    int power = 0;
    while (!isEmpty()) {
        int bit = pop();
        decimal += bit * pow(2, power);
        power++;
    }
    return decimal;
}

int main() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;
    cout << "Binary equivalent: ";
    decimalToBinary(num);
    cout << endl;
     string binary;
    cout << "Enter a binary number: ";
    cin >> binary;
    int decimal = binaryToDecimal(binary);
    cout << "Decimal equivalent: " << decimal << endl;
    return 0;
}
