#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char str[]) {
    int n = strlen(str);
    int top = -1;
    int i;

    for (i = 0; i < n / 2; i++) {
        top++;
        str[top] = str[i];
    }

    if (n % 2 != 0) {
        i++;
    }

    while (i < n) {
        if (str[top] != str[i]) {
            return false;
        }
        top++;
        i++;
    }

    return true;
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << str << " is a palindrome" << endl;
    } else {
        cout << str << " is not a palindrome" << endl;
    }

    return 0;
}
/*
//BELOW ARE ABOUT PALINDROME NUMBER
#include <iostream>

using namespace std;

bool isPalindrome(int num) {
    int temp = num;
    int n = 0;

    while (temp != 0) {
        temp /= 10;
        n++;
    }

    int stack[n / 2];
    int top = -1;
    int i = 0;

    while (i < n / 2) {
        top++;
        stack[top]=num % 10;
        num /= 10;
        i++;
    }

    if (n % 2 != 0) {
        num /= 10;
    }

    while (num != 0) {
        if (stack[top] != num % 10) {
            return false;
        }
        top--;
        num /= 10;
    }

    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome" << endl;
    } else {
        cout << num << " is not a palindrome" << endl;
    }

    return 0;
}
*/
