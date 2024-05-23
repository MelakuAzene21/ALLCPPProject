#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrome(string str) {
    stack<char> stack;
    int length = str.length();

    // Push each character of the string onto the stack
    for (int i = 0; i < length; i++) {
        stack.push(str[i]);
    }

    // Compare each character of the string with the top of the stack
    for (int i = 0; i < length; i++) {
        if (str[i] != stack.top()) {
            return false;
        }
        stack.pop();
    }

    return true;
}


void dec_to_bin(int number) {
   stack<int> stk;
   while(number > 0) {
      int rem = number % 2; //take remainder
      number = number / 2;
      stk.push(rem);
   }
   while(!stk.empty()) {
      int item;
      item = stk.top();
      stk.pop();
      cout << item;
   }
cout<<endl;}

// function definition BINARY TO DECIMAL
int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}



// Function to check if a character is an operator
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> stk;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If character is an operand, add it to the postfix expression
        if (isalnum(c))
            postfix += c;
        // If character is an opening parenthesis, push it to the stack
        else if (c == '(')
            stk.push(c);
        // If character is a closing parenthesis, pop operators from the stack until an opening parenthesis is encountered
        else if (c == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop(); // Pop the opening parenthesis from the stack
        }
        // If character is an operator
        else if (isOperator(c)) {
            while (!stk.empty() && getPrecedence(stk.top()) >= getPrecedence(c)) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    // Pop any remaining operators from the stack
    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}



string reverseString(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    string revStr = "";
    while (!s.empty()) {
        revStr += s.top();
        s.pop();
    }
    return revStr;
}


#define MAX_SIZE 100

int stack1[MAX_SIZE];
int top = -1;

bool isEmptyStack() {
    return (top == -1);
}

bool isFullStack() {
    return (top == MAX_SIZE - 1);
}

void push(int value) {
    if (isFullStack()) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stack1[++top] = value;
}

int pull() {
    if (isEmptyStack()) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return stack1[top--];
}

int peek() {
    if (isEmptyStack()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return stack1[top];
}

void makeEmpty() {
    top = -1;
}

int getSize() {
    return top + 1;
}

int evaluatePostfix(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            int operand2 = pull();
            int operand1 = pull();
            switch (postfix[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid operator!" << endl;
                    return -1;
            }
        }
    }
    return pull();
}




#define MAX_SIZE 100

int stack2[MAX_SIZE];
//int top = -1;
/*
void push(int value){
    if(top == MAX_SIZE-1){
        cout<<"Stack overflow."<<endl;
        return;
    }
    top++;
    stack[top] = value;
}
*/
void pop(){
    if(top == -1){
        cout<<"Stack underflow."<<endl;
        return;
    }
    top--;
}

void displayStack(){
    if(top == -1){
        cout<<"Stack is empty."<<endl;
        return;
    }
    cout<<"Stack elements: ";
    for(int i=top; i>=0; i--){
        cout<<stack2[i]<<" ";
    }
    cout<<endl;
}


int main()

 {



    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }




     int num;
   cout << "Enter a number: ";
   cin >> num;
   dec_to_bin(num);



   long long n;
  cout << "Enter a binary number: ";
  cin >> n;
  cout << n << " in binary = " << convert(n) << " in decimal";


cout<<endl;

    string infixExpression;
    cout << "Enter the infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;


//string str;
     cout<<"Enter a string\n";
     cin.ignore();
     getline(cin,str);
     //str = "Hello World!";
    cout << reverseString(str) << endl;

     string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;


    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();

    return 0;
}

