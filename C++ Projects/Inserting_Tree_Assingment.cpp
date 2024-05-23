#include <iostream>
#include<cstring>
using namespace std;
struct Student
{
    char fullName[15];
    int id;
    int mark;
    Student *left;
    Student *right;
};
// Function to create a new student node
Student *createStudentNode(string fullName, int id, int mark)
{
    Student *Temp = new Student;
   Temp->id = id;
    Temp->mark = mark;
    Temp->left = nullptr;
    Temp->right = nullptr;
    return Temp;
}

// Function to insert a student into the binary search tree
Student *insertStudent(Student *root, char fullName[], int id, int mark)
{
    if (root == nullptr){
        return createStudentNode(fullName, id, mark);
    }

    if (id < root->id)
    {
        root->left = insertStudent(root->left, fullName, id, mark);
    }
    else if (id > root->id)
    {
        root->right = insertStudent(root->right, fullName, id, mark);
    }
    else
    {
        cout << "Student ID " << id << " already exists. Cannot insert duplicate ID." << endl;
    }

    return root;
}

Student* find_min(Student* root) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->left == nullptr) {
        return root;
    } else {
        return find_min(root->left);
    }
}

Student* delete_student(Student* root, int id) {
    if(root == nullptr) {
        return root;
    } else if (id < root->id) {
        root->left = delete_student(root->left, id);
    } else if (id > root->id) {
        root->right = delete_student(root->right, id);
    } else {
        if(root->left == nullptr) {
            Student* temp = root->right;
            delete root;
            return temp;
            cout << "Deleted succssfully" << endl;
        } else if (root->right == nullptr) {
            Student* temp = root->left;
            delete root;
            return temp;
            cout << "Deleted succssfully" << endl;
        }
        Student* min_value = find_min(root->right);
        root->id = min_value->id;
        strcpy(root->fullName, min_value->fullName);
        root->mark = min_value->mark;
        root->right = delete_student(root->right, min_value->id);
        cout << "Deleted succssfully" << endl;
    }
}

// Function to display the student information

void displayStudent(Student*student)
{

    if (student == nullptr)
    {
        cout << "You Have No Inserted Data\n";
        return;
    }
    cout << "Full Name: "<<student->fullName<<endl;
    cout << "ID: " << student->id<<endl;
    cout << "Mark: " << student->mark << endl;
    cout << endl;
}

void inorderTraversal(Student *root)
{
    if (root != nullptr)
    {

        inorderTraversal(root->left);
        displayStudent(root);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Student *root)
{
    if (root!= nullptr)
    {


        displayStudent(root);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(Student *root)
{
    if (root != nullptr)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        displayStudent(root);
    }
}
Student *searchStudent(Student *root, int id)
{
    if (root == nullptr || root->id == id)
    {
        return root;
    }
    if (id < root->id)
    {
        return searchStudent(root->left, id);
    }
    else
    {
        return searchStudent(root->right, id);
    }
}
// Function to find the maximum mark of a student in the binary search tree
int findMaxMark(Student *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root->right == nullptr)
    {
        return root->mark;
    }
    return findMaxMark(root->right);
}

// Function to find the minimum mark of a student in the binary search tree
int findMinMark(Student *root)
{
    if (root == nullptr){
        return -1;
    }
    else if (root->left == nullptr){
        return root->mark;
    } else {
        return findMinMark(root->left);
    }
}
// Function to find the height  of a student in the binary search tree
int Tree_Height(Student *temp) {
    if (temp == NULL)
    {
        return -1;
    }
    else
    {
        int leftHeight = Tree_Height(temp->left);
        int rightHeight = Tree_Height(temp->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;

        }
    else
        {
            return rightHeight + 1;
        }
    }
}
// Function to find the height  of agiven student in the binary search tree
int height_node(Student *temp, int Id)
{
    int counter = 0;
    while (temp->id != Id)
    {
        if (temp->id > Id)
        {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        counter++;
    }
    return counter;
}
// Function to find the anscestor  of a student in the binary search tree
void anscestor(Student *temp2, int Id)
{
    while (temp2->id != Id)
    {
        if (temp2->id > Id)
            {
            cout << "Id: " << temp2->id <<endl<< "name :" << temp2->fullName << endl
                 << "mark:" << temp2->mark << endl;
            temp2 = temp2->left;
            }
        else
            {
            cout << "Id: " << temp2->id << endl<<"name :"<<temp2->fullName<<endl<<"mark:"<<temp2->mark<<endl;
            temp2 = temp2->right;
            }
    }
}

int main()
{
Student* root=nullptr;
  bool check=true;
 int choice;
while(check)
{
    cout<<  "Press 1 to Add a student\n";
    cout << "Press 2 to Inorder traversal\n";
    cout << "Press 3 to preorder traversal\n";
    cout << "Press 4 to postorder traversal\n";
    cout << "Press 5 to Search\n";
    cout << "Press 6 to Know Maximum Mark\n";
    cout << "Press 7 to Know Minimum Mark\n";
    cout << "Press 8 to Know height of the tree \n";
    cout << "Press 9 to Know anscentor agiven node \n";
    cout << "Press 10 to Know height of agiven node \n";
    cout<<"Press 11 to delete \n";
    cout << "Press 12 to exit\n";

    cout << "Enter your choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
              {

                int numStudents;
                cout << "How many students do you want to insert? ";
                cin >> numStudents;
                //system("cls");
                char fullName [15];
                int id, mark;
                cin.ignore();
                for (int i = 0; i < numStudents; i++)
                {
                    cout << "Enter full name of student " << i + 1 << ": ";

                   cin.ignore();
                   cin>>fullName;
                   //getline(cin,fullName);

                    bool isValidId = false;
                    while (!isValidId)
                    {
                        cout << "Enter ID of student " << i + 1 << ": ";
                        cin >> id;

                        // Check if the ID already exists
                        Student *temp = root;
                        bool isDuplicateId = false;

                        while (temp != nullptr)
                        {
                            if (id == temp->id)
                            {
                                isDuplicateId = true;
                                break;
                            }
                            else if (id < temp->id)
                            {
                                temp = temp->left;
                            }
                            else
                            {
                                temp = temp->right;
                            }
                        }

                        if (isDuplicateId)
                        {
                            cout << "Cannot use ID " << id << " because it is already in use." << endl;
                        }
                        else
                        {
                            isValidId = true;
                        }
                    }

                    bool isValidMark = false;
                    while (!isValidMark)
                    {
                        cout << "Enter mark of student " << i + 1 << ": ";
                        cin >> mark;

                        if (mark >= 0 && mark <= 100)
                        {
                            isValidMark = true;
                        }
                        else
                        {
                            cout << "Invalid mark! Mark must be between 0 and 100 inclusive." << endl;
                        }
                    }

                    // Insert the student into the binary search tree
                     root = insertStudent(root, fullName, id, mark);
                }
                break;
              }
          case 2:{
                inorderTraversal(root);
                break;
                }
    case 3:
                {
                    preorderTraversal(root);
                break;
                }
    case 4:   {
                postorderTraversal(root);
                break;
                }
    case 5:   {
                int searchId;
                cout << "Enter the ID of the student you want to search: ";
                cin >> searchId;

                Student *searchedStudent = searchStudent(root, searchId);
                if (searchedStudent == nullptr)
                {
                    cout << "Student with ID " << searchId << " not found." << endl;
                }
                else
                {
                    cout << "Student with ID " << searchId << " found." << endl;
                    displayStudent(searchedStudent);
                }
                break;
             }
    case 6:    {
                int maxMark = findMaxMark(root);
                if (maxMark == -1)
                {
                    cout << "No mark to display!" << endl;
                }
                else
                {
                    cout << "Maximum Mark: " << maxMark << endl;
                }
                break;
               }

    case 7: {
              int minMark = findMinMark(root);

                if (minMark == -1)
                {
                    cout << "No mark to display!" << endl;
                }
                else
                {
                    cout << "Minimum Mark: " << minMark << endl;
                }
                break;

            }

    case 8:    {
                Student *temp = root;
                cout << "Height of the binary search tree is: " << Tree_Height(temp) << endl;
                break;
               }

    case 9:
               {
                int id;
                Student *temp2 = root;
                cout << "enter the node which will be finded its anscestors " << endl;
                cin >> id;
                anscestor(temp2, id);
                break;
               }

    case 10:
                {
                int id;
                Student *temp1 = root;
                cout << "enter the node which will be finded its height " << endl;
                cin >> id;
                cout << "height of a given node is" << height_node(temp1, id) << endl;
                break;
                }

        case 11:{
            int id;
            cout << "Enter the id of the student you want to delete" << endl;
            cin >> id;
            root = delete_student(root, id);
            break;
        }


    case 12:
                check = false;
        default:
                cout << "please enter valid choice " << endl;
                break;
    }
}

return 0;
}




















/*

    int numStudents;
    cout << "How many students do you want to insert? ";
    cin >> numStudents;
    system("cls");

    Student *root = nullptr;
    string fullName;
    int id, mark;
    for (int i = 0; i < numStudents; i++)
    {

        cout << "Enter full name of student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, fullName);

        bool isValidId = false;
        while (!isValidId)
        {
            cout << "Enter ID of student " << i + 1 << ": ";
            cin >> id;

            // Check if the ID already exists
            Student *temp = root;
            bool isDuplicateId = false;

            while (temp != nullptr)
            {
                if (id == temp->id)
                {
                    isDuplicateId = true;
                    break;
                }
                else if (id < temp->id)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }

            if (isDuplicateId)
            {
                cout << "Cannot use ID " << id << " because it is already in use." << endl;
            }
            else
            {
                isValidId = true;
            }
        }

        bool isValidMark = false;
        while (!isValidMark)
        {
            cout << "Enter mark of student " << i + 1 << ": ";
            cin >> mark;

            if (mark >= 0 && mark <= 100)
            {
                isValidMark = true;
            }
            else
            {
                cout << "Invalid mark! Mark must be between 0 and 100 inclusive." << endl;
            }
        }

        // Insert the student into the binary search tree
        root = insertStudent(root, fullName, id, mark);
    }

    inorderTraversal(root);

    int searchId;
    cout << "Enter the ID of the student you want to search: ";
    cin >> searchId;

    Student *searchedStudent = searchStudent(root, searchId);
    if (searchedStudent == nullptr)
    {
        cout << "Student with ID " << searchId << " not found." << endl;
    }
    else
    {
        cout << "Student with ID " << searchId << " found." << endl;
        displayStudent(searchedStudent);
    }

    int maxMark = findMaxMark(root);
    int minMark = findMinMark(root);

    if (minMark == -1 && maxMark == -1) {
        cout << "No mark to display!" << endl;
    } else {
        cout << "Maximum Mark: " << maxMark << endl;
        cout << "Minimum Mark: " << minMark << endl;
    }
    return 0;
}
*/
