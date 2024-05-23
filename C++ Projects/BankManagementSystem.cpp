#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

// Define a struct to hold customer information
struct Customer {
    int accountNumber;
    string name;
    double balance;
    Customer* next;
    Customer* prev;
};

string password;
int counter=0;

// Define a function to add a new customer to the list
void addCustomer(Customer* &head, int accountNumber, string name, double balance) {
    Customer* newCustomer = new Customer;
    newCustomer->accountNumber = accountNumber;
    newCustomer->name = name;
    newCustomer->balance = balance;
    newCustomer->next = NULL;
    newCustomer->prev = NULL;

    if (head == NULL) {
        head = newCustomer;
    }
     else
        {
        Customer* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCustomer;
        newCustomer->prev = temp;
    }
}

// Define a function to delete a customer from the list
void deleteCustomer(Customer* &head, int accountNumber)
{
    if (head == NULL)
        {
            system("cls");
            cout << " This is Wrong Account.it do not Exist This Account number in our Bank sofar." << endl;
        return;
      }

    Customer* temp = head;
    while (temp != NULL && temp->accountNumber != accountNumber)
        {
        temp = temp->next;
       }

    if (temp == NULL)
        {
            system("cls");
 cout << "The Customer is not Found. This is Wrong Account.OR.it do not Exist in our Bank sofar." << endl;
        return;
    }

    if (temp->prev != NULL)
        {
        temp->prev->next = temp->next;
    }
    else
        {
        head = temp->next;
      }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
system("cls");
     cout << "Customer deleted successfully." << endl;


}

// Define a function to show a customer's data
void showCustomer(Customer* head, int accountNumber)
 {
    Customer* temp1 = head;
    while (temp1 != NULL && temp1->accountNumber != accountNumber)
        {
        temp1 = temp1->next;
       }

    if (temp1 == NULL)
        {
            system("cls");//to clear the Screen.
        cout << "Customer not found." << endl;
    }
    else
    {
        system("cls");
    cout<<"====================================================================================================\n";
        cout << "Account Number: " << temp1->accountNumber << endl;
        cout << "Name: " << temp1->name << endl;
        cout << "Balance: " << temp1->balance << endl;
    cout<<"====================================================================================================\n";
    }
}

// Define a function to modify a customer's data
void modifyCustomer(Customer* head, int accountNumber, string name, double balance)
  {
    Customer* temp2 = head;
    while (temp2 != NULL && temp2->accountNumber != accountNumber)
    {
        temp2 = temp2->next;
    }

    if (temp2 == NULL)
    {
            system("cls");//to clear the Screen
        cout << "Customer not found." << endl;
    }

    else
    {
        temp2->name = name;
        temp2->balance = balance;
         system("cls");
        cout<<"====================================================================================================\n";
       cout<<"The Customer data successfully Modified\n";
       cout<<"------------------------------------------------------------------------------------------------------\n";
       cout<<"The New Name is  :"<< temp2->name<<endl;
       cout<<"The new Balance is :"<<temp2->balance <<endl;
      cout<<"====================================================================================================\n";
    }
}

// Define a function to search for a customer by name
void searchCustomer(Customer* head, int accountNumber)
  {
    Customer* temp3 = head;
    while (temp3 != NULL) {
        if (temp3->accountNumber == accountNumber)
            {
                system("cls");
        cout<<"====================================================================================================\n";
            cout << setw(15)<<"Account Number: " << setw(15)<< temp3->accountNumber << endl;
            cout << setw(15)<< "Name: " << setw(15)<<temp3->name << endl;
            cout << setw(15)<< "Balance: " << setw(15)<<temp3->balance << endl;
        cout<<"====================================================================================================\n";
           }

        temp3 = temp3->next;
      }
system("cls");
        cout<<"The Customer is Not Found\n";
  }

// Define a function to get the total number of customers
int getTotalCustomers(Customer* head)
    {
    int count = 0;
    Customer* temp4 = head;
    while (temp4 != NULL)
    {
        count++;
        temp4 = temp4->next;
    }
    return count;
}

// Define a function to show all customers' information by account number

void showAllCustomers(Customer* head)
   {
     system("cls");
     if (head==NULL){
     cout<<"There is No Recorded Customer\n";}
     else
        {
    Customer*temp5 = head;
    while (temp5!= NULL)
    {

    cout<<"====================================================================================================\n";
        cout << setw(15)<<"Account Number: "<< setw(15)<<temp5->accountNumber << endl;
        cout<< setw(15)<<"Name: " << setw(17)<< temp5->name << endl;
        cout << setw(15)<< "Balance: " << setw(15)<< temp5->balance << endl;
    cout<<"====================================================================================================\n";
        temp5 = temp5->next;

             }
      }
  }

// Define a function to deposit money into a customer's account
void deposit(Customer* head, int accountNumber, double amount)
    {
    Customer* temp6 = head;
    while (temp6 != NULL && temp6->accountNumber != accountNumber)
    {
        temp6 = temp6->next;
    }

    if (temp6 == NULL)
    {
            system("cls");
        cout << " The Customer is not found.  \nPlease FIRST OPEN Account " << endl;
    }
    else

     {
        temp6->balance += amount;
         system("CLS");
        cout<<"Now You have deposited :"<<amount<<"Birr....\n";
        cout << "...Your New balance: " << temp6->balance << endl;
    }
}

// Define a function to withdraw money from a customer's account
void withdraw(Customer* head, int accountNumber, double amount)
  {
    Customer* current = head;
    while (current != NULL && current->accountNumber != accountNumber)
    {
        current = current->next;
    }

    if (current == NULL)
        {
            system("cls");
        cout << " The Customer is not found.  \nPlease FIRST OPEN Account." << endl;
    }
    else if (current->balance < amount)

    {
        cout << "You have Insufficient balance." << endl;
    }
    else
        {
        current->balance -= amount;
        cout<<"Now you withdraw "<<amount<< "Birr"<<endl;
        cout << " Your New balance: " << current->balance << "Birr"<<endl;
     }
 }

// Define a function to check a customer's balance
void checkBalance(Customer* head, int accountNumber)
   {
    Customer* current = head;
    while (current != NULL && current->accountNumber != accountNumber)
    {
        current = current->next;
    }

    if (current == NULL)
        {
            system("cls");
        cout << "Customer not found. \nPlease FIRST OPEN Account" << endl;
    }
    else
        {
             system("cls");
        cout << "Your Balance " << current->balance << " Birr"<<endl;
    }
}

// Define a function to open a new account
void openAccount(Customer*& head, int accountNumber, string name, double balance)
 {
    addCustomer(head, accountNumber, name, balance);
     system("cls");
    cout<<"CONGURALATIONS  :";
    cout << "Account opened successfully." << endl;
}

// Define a function to close an account
void closeAccount(Customer*& head, int accountNumber)
 {
    deleteCustomer(head, accountNumber);
Customer* current = head;

    while (current != NULL && current->accountNumber != accountNumber)
        {
        current = current->next;
     }

    if (current == NULL)
        {

        cout << "Customer not found.... \nYou have no Account" << endl;
        }

    else
  {

    system("cls");
    cout << "Account closed successfully." << endl;
   }
}
// Define a function to transfer money between two accounts
void transfer(Customer* head, int SenderAccount, int RecipientAccount, double amount)
  {
    Customer* Sender_Customer = head;
    while (Sender_Customer != NULL && Sender_Customer->accountNumber != SenderAccount)
    {
        Sender_Customer = Sender_Customer->next;
    }

    if (Sender_Customer == NULL)
        {
            system("cls");
        cout << "Sender not found." << endl;
        return;
       }

    Customer* Recipient_Customer = head;
    while (Recipient_Customer != NULL && Recipient_Customer->accountNumber != RecipientAccount)
        {
        Recipient_Customer = Recipient_Customer->next;
       }

    if (Recipient_Customer == NULL)
        {
            system("cls");
        cout << "Recipient not found." << endl;
        return;
       }

    if (Sender_Customer->balance < amount)
        {
            system("cls");
        cout << "Insufficient funds." << endl;
        return;
      }

    Sender_Customer->balance -= amount;
    Recipient_Customer->balance += amount;
    system("cls");
    cout << "Transfer successful." << endl;
    cout<<"You have transfered "<<amount<<" Birr to Account Number of  "<<RecipientAccount<<"Succesfully \n";
    cout<<"Your New Balance is "<<Sender_Customer->balance <<"\n";
   }

// Define a function to get a loan from the bank
void getLoan(Customer* head, int accountNumber, double amount)
  {
    Customer* current = head;
    while (current != NULL && current->accountNumber != accountNumber)
        {
        current = current->next;
      }

    if (current == NULL) {
            system("cls");
        cout << "Customer not found. \nPlease FIRST OPEN Account." << endl;
    } else {
        current->balance += amount;
        cout<<"You Have Loaned  "<<amount<<" Birr From Bank\n";
        cout << "Your New balance is: " << current->balance << endl;
    }
}


//main function
int main()
{
    Customer* head = NULL;
    int role,d,t ;
  char m;
   system("color 9");
   label2:
 system("cls");
  cout<<" ______________________________\n";
 cout<<"|  NAME = MELAKU AZENE         |\n";
 cout<<"|   ID=1405424                 |\n";
 cout<<"|  Department=Computer Science |\n";
 cout<<"|______________________________|\n";
   cout<<"**********       * *     *  *        *      *      *                     \n";
   cout<<"*       *      *   *     *    *      *      *    *                       \n";
   cout<<"*      *      *     *    *      *    *      * *                        \n";
   cout<<"***** *      * * * * *   *        *  *      *   *                      \n";
   cout<<"*     *     *        *   *          *       *     *                    \n";
   cout<<"******* *  *         *   *                  *                         \n";

    cout<<"====================================================================================================\n";
cout << "Are you a Banker or a Customer?" << endl;
  cout<<"Choose one who are you\n";
    cout<<" Press :1:BANKER \n";
    cout<<"Press:2:CUSTOMER\n";
    cout<<"Press :3:EXIT \n\n";

  cout<<"====================================================================================================\n";

    cin >> role;
    lable5:
    if(role==1)
        goto label1;
    else if(role==2)
        goto label;
    else if(role==3)
        goto lable4;
        else
            cout<<"Invalid Input try again ";
            cin>>role;

            t++;
            if(t>3){
            cout<<"You try a lot time .run again the program .\n";
         }
        else{
      goto lable5;
        }
label1:
switch(role)
{
    case 1:if (role ==1) {
        // Prompt the banker to enter their password
        do{  system("color 30");
        string password12;
        int trial=0;

   if(counter==0)
   {
       system("cls");
    cout<<"Create Your Password\n";
    cin>>password;

    counter++;
   }
   if(counter>0)
   {
    cout<<"Enter your Password Creating Now to Login The system \n";

    cin>>password12;
     banker12:

    if(password==password12)
    {
     goto staff;//To go to Banker Menu
    }
    trial++;
    cout<<"incorrect password try again\n";
    cin>>password12;
    trial++;
     if (trial > 3){
                cout<<"You try a lot time .Run again the program .\n";
                  break;
                  }
          goto banker12;

   }
   break;

            char c;
           do {
                // Prompt the banker to choose an action
                staff:
                    system("color 6");
                    system("cls");
     cout<<"====================================================================================================\n";
    cout<<"***********************=> THIS IS BANKER MENU=>**********************************************************"<<endl;
                cout << "WHAT WOULD YOU LIKE TO DO?" << endl;
                cout << "1. Add customer" << endl;
                cout << "2. Delete customer" << endl;
                cout << "3. Show customer data" << endl;
                cout << "4. Modify customer data" << endl;
                cout << "5. Search for customer" << endl;
                cout << "6. Get total number of customers" << endl;
                cout << "7. Show all customers' information by account number" << endl;
                cout<<" 8.  Go to Customer MENU\n";
                cout<<" 9 .Go to Main MENU\n";
                cout << "10. Exit" << endl;
   cout<<"====================================================================================================\n";

                int choice;
    cout<<"Enter your choice From given the above MENU\n";
                cin >> choice;

                switch (choice) {
                    case 1: {
                        // Prompt the banker to enter the new customer's information
                        int accountNumber;
                        string name;
                        double balance;
                        cout << "Enter the new customer's account number: ";
                        cin >> accountNumber;
                        cout << "Enter the new customer's Full name: ";
                        cin.ignore();
                       getline(cin,name);
                        cout << "Enter the new customer's balance: ";
                        cin >> balance;
                        // Add the new customer to the list
                        addCustomer(head, accountNumber, name, balance);
                        cout << "Customer added successfully." << endl;
                        break;
                    }
                    case 2: {
                        // Prompt the banker to enter the account number of the customer to delete
                        int accountNumber;
                        cout << "Enter the account number of the customer to delete: ";
                        cin >> accountNumber;

                        // Delete the customer from the list
                        deleteCustomer(head, accountNumber);
                      //  cout << "Customer deleted successfully." << endl;
                        break;
                    }
                    case 3: {
                        // Prompt the banker to enter the account number of the customer to show
                        int accountNumber;
                        cout << "Enter the account number of the customer to show: ";
                        cin >> accountNumber;

                        // Show the customer's data
                        showCustomer(head, accountNumber);
                        break;
                    }
                    case 4: {
                        // Prompt the banker to enter the account number of the customer to modify
                        int accountNumber;
                        cout << "Enter the account number of the customer to modify: ";
                        cin >> accountNumber;

                        // Prompt the banker to enter the new information for the customer
                        string name;
                        double balance;
                        cout << "Enter the new Full name for the customer: ";
                          cin.ignore();
                       getline(cin,name);
                        cout << "Enter the new balance for the customer: ";
                        cin >> balance;

                        // Modify the customer's data
                        modifyCustomer(head, accountNumber, name, balance);
                        break;
                    }
                    case 5: {
                        // Prompt the banker to enter the name of the customer to search for
                        int accountNumber;
                        cout << "Enter the account number of the customer to search: ";
                        cin >> accountNumber;

                        // Search for the customer by name
                        searchCustomer(head, accountNumber);
                        break;
                    }
                    case 6: {
                        // Get the total number of customers
                        int totalCustomers = getTotalCustomers(head);
                        system("cls");
                        cout << "Total number of customers in the Bank: " << totalCustomers << endl;
                        break;
                    }
                    case 7: {
                        // Show all customers' information by account number
                        showAllCustomers(head);
                        break;
                    }
                    case 8:  goto label;
                    break;//call Customer menu
                    case 9:goto label2;
                    break;//call main mainu
                    lable8:
                    case 10: {


                          exit(0); // Exit the program

                    }
                    break;
                    default: {
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                               }
                     }

         cout<<"DO YOU WANT TO CONTINUE\n";
   cout<<"Press y or Y to Continue\n";

   cin>>c;

       }while(c=='y'||c=='Y');
break;

  }while(true);
break;


    label:
     case 2:
                          system("cls");
                  system("color 10");
        cout << "|=============================|" << endl;
        cout << "|        WELCOME TO           |" << endl;
        cout << "|        OUR BANK             |" << endl;
        cout << "|=============================|" << endl;

        cout << endl;
                           char b;

                           do{
 cout<<"=====================================================================================================\n";
cout<<"||                               THIS IS CUSTOMER MENU                                               ||" <<endl;
 cout<<"=====================================================================================================\n";
cout<<"||                                                                                                   ||" <<endl;
cout<<"||                                                                                                   ||" <<endl;
cout<<"||                             What would you like to do?                                            ||" << endl;
cout<<"||                            .1. Deposit money                                                      ||"<< endl;
cout<<"||                           .2. Withdraw money                                                      ||" << endl;
cout<<"||                           .3. Check balance                                                       ||" << endl;
cout<<"||                           .4. Open new account                                                    ||"<< endl;
cout<<"||                           .5. Close account                                                       ||" << endl;
cout<<"||                           .6. Transfer money                                                      ||" << endl;
cout<<"||                           .7. Get a loan                                                          ||" << endl;
cout<<"||                           .8. Go to Banker Menu                                                   ||" << endl;
cout<<"||                           .9.Go to Main Menu                                                      ||"<<endl;
cout<<"||                           .10. Exit                                                               || "<< endl;
  cout<<"====================================================================================================\n";
  cout<<"====================================================================================================\n";
        int accountNumber;

            int choice;
            cout<<"enter your choice\n";
            cin >> choice;

            switch (choice) {
                case 1: {
                    double amount;
                    cout << "Please enter your account number: ";
                    cin >> accountNumber;
                    cout << "Enter the amount to deposit: ";
                    cin >> amount;

                    deposit(head, accountNumber, amount);
                    break;
                }
                case 2: {
                    // Prompt the customer to enter the amount to withdraw
                    cout << "Please enter your account number: \n";
                    cin >> accountNumber;
                    double amount;
                    cout << "Enter the amount to withdraw: ";
                    cin >> amount;

                    // Withdraw the money from the customer's account
                    withdraw(head, accountNumber, amount);
                    break;
                }
                case 3: {
                    // Check the customer's balance
                    cout << "Please enter your account number: \n";
                    cin >> accountNumber;
                    checkBalance(head, accountNumber);
                    break;
                }
                case 4: {
                    // Prompt the customer to enter their information for the new account
                    int newAccountNumber;
                    string name;
                    double balance;
                    cout << "Enter your new account number:\n ";
                    cin >> newAccountNumber;
                    cout << "Enter your Full  name:\n ";
                    cin.ignore();
                  getline(cin,name);
                    cout << "Enter your starting balance:\n ";
                    cin >> balance;

                    // Open the new account
                    openAccount(head, newAccountNumber, name, balance);
                    break;
                }
                case 5: {
                    // Close the customer's account
                    cout << "Please enter your account number: \n";
                    cin >> accountNumber;
                    closeAccount(head, accountNumber);
                    break;
                }
                case 6: {
                    // Prompt the customer to enter the recipient's account number and the amount to transfer
                    int recipientAccountNumber;
                    double amount;
                    cout << "Please enter your account number: \n";
                    cin >> accountNumber;
                    cout << "Enter the recipient's account number: \n";
                    cin >> recipientAccountNumber;
                    cout << "Enter the amount to transfer:\n ";
                    cin >> amount;

                    // Transfer the money between the two accounts
                    transfer(head, accountNumber, recipientAccountNumber, amount);
                    break;
                }
                case 7: {
                    // Prompt the customer to enter the amount of the loan
                    double amount;
                    cout << "Please enter your account number: \n";
                    cin >> accountNumber;
                    cout << "Enter the amount of the loan: \n";
                    cin >> amount;

                    // Get the loan from the bank
                    getLoan(head, accountNumber, amount);
                    break;
                }
                case 8: goto label1;//to go banker mainu
                  break;
                case 9:goto label2;//to go main menu
                break;
                case 10: {

                    exit(0);// Exit the program
                          }
                break;
                default: {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }

                 cout<<"DO YOU WANT TO CONTINUE\n";
   cout<<"Press  y or Y to Continue\n";

   cin>>b;
}while(b=='Y'||b=='y');
break;
  }
    lable4:
    case 4://to exit from main menu
        {
        exit(0);
        }
    return 0;
   }
}



