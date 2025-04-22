#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <iostream>  // 确保包含标准头文件
#include <climits>  // 添加INT_MAX定义

using namespace std; // 已存在但需要确认作用域

#define MAX_CONTACTS 1000

typedef struct Contact {
    char name[20];
    char sex[5];
    int age;
    char phone[12];
    char addr[100];
}   contact;
contact g_contacts[MAX_CONTACTS] = {0};

int AddContact(contact ContactInfo)
{
    int i = 0;
    for (i = 0; i < sizeof(g_contacts) / sizeof(g_contacts[0]); i++) {
        if (g_contacts[i].name[0] == 0) {
            g_contacts[i] = ContactInfo;
            break;
        }
    }
    if (i + 1 == MAX_CONTACTS) {
        cout << "Contact list is full" << endl;
        return -1;
    }
    return 0;
}

int ShowContacts()
{
    for (int i = 0; i < sizeof(g_contacts) / sizeof(g_contacts[0]); i++) {
        if (g_contacts[i].name[0] != 0) {
            cout << i + 1 << ": " << "name: " << g_contacts[i].name << ", " << "sex: " << g_contacts[i].sex << ", " << "age: " << g_contacts[i].age << ", " << "phone: " << g_contacts[i].phone << ", " << "addr: " << g_contacts[i].addr << "\n" << endl;
        }
    }
    return 0;
}

int DeleteContact(int index)
{
    if (index < 0 || index > sizeof(g_contacts) / sizeof(g_contacts[0])) {
        return -1;
    }
    g_contacts[index].name[0] = 0;
    g_contacts[index].sex[0] = 0;
    g_contacts[index].age = 0;
    g_contacts[index].phone[0] = 0;
    g_contacts[index].addr[0] = 0;
    return 0;
}

contact SearchContact(char* name)
{
    for (int i = 0; i < sizeof(g_contacts) / sizeof(g_contacts[0]); i++) {
        if (strcmp(g_contacts[i].name, name) == 0) {
            return g_contacts[i];
        }
    }
    return contact{0};
}

int ModifyContact(int index, contact ContactInfo)
{
    if (index < 0 || index > sizeof(g_contacts) / sizeof(g_contacts[0])) {
        return -1;
    }
    g_contacts[index] = ContactInfo;
    return 0;
}

int ClearContacts()
{
    for (int i = 0; i < sizeof(g_contacts) / sizeof(g_contacts[0]); i++) {
        g_contacts[i].name[0] = 0;
        g_contacts[i].sex[0] = 0;
        g_contacts[i].age = 0;
        g_contacts[i].phone[0] = 0;
        g_contacts[i].addr[0] = 0;
    }
    return 0;
}
const char* option_list[] = {
    "1. Add contacts",
    "2. Show contacts",
    "3. Delete contacts",
    "4. Search contacts",
    "5. Modify contacts",
    "6. Clear contacts",
    "7. Exit",
};

int main() {
    while (true){
        cout << "Welcome to the contact management system" << endl;
        for (int i = 0; i < sizeof(option_list) / sizeof(option_list[0]); i++) {
            cout << option_list[i] << endl;
        }
        cout << "Please select an option:" << endl;
        int choice = 0;
        cin >> choice;
        switch (choice) {
            case 1:
                // add contacts
                while (true) {
                    contact ContactInfo;
                    cout << "Please enter the name: " << endl;
                    cin >> ContactInfo.name;
                    cout << "Please enter the sex: " << endl;
                    cin >> ContactInfo.sex;
                    cout << "Please enter the age: " << endl;
                    cin >> ContactInfo.age;
                    cout << "Please enter the phone: " << endl;
                    cin >> ContactInfo.phone;
                    cout << "Please enter the addr: " << endl;
                    cin >> ContactInfo.addr;
                    if (AddContact(ContactInfo) == 0) {
                        cout << "Add contact success" << endl;
                        cout << "Do you want to add another contact? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice; 
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                        else {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    } else {
                        cout << "Add contact failed" << endl;
                        cout << "Do you want to readd contact? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice;
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                    }
                }
                break;
            case 2:
                // show contacts
                ShowContacts();
                break;
            case 3:
                // delete contacts
                while (true) {
                    int index = 0;
                    cout << "Please enter the index of the contact you want to delete: " << endl;
                    cin >> index;
                    if (DeleteContact(index - 1) == 0) {
                        cout << "Delete contact success" << endl;
                        cout << "Do you want to delete another contact? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice;
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                        else {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    }
                    else {
                        cout << "Delete contact failed" << endl;
                        cout << "Do you want to redelete contact? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice;
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                        else {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    }
                }
                break;
            case 4:
                // search contacts
                while (true) {
                    char name[20];
                    cout << "Please enter the name of the contact you want to search: " << endl;
                    cin >> name;
                    contact ContactInfo = SearchContact(name);
                    if (ContactInfo.name[0] == 0) {
                        cout << "Search contact failed" << endl;
                        cout << "Do you want to research contact? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice;
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                        else {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    }
                    else {
                        cout << "Search contact success" << endl;
                        cout << "name: " << ContactInfo.name << ", " << endl;
                        cout << "sex: " << ContactInfo.sex << ", " << endl;
                        cout << "age: " << ContactInfo.age << ", " << endl;
                        cout << "phone: " << ContactInfo.phone << ", " << endl;
                        cout << "addr: " << ContactInfo.addr << "\n" << endl;
                        cout << "Do you want to research contact? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice;
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                        else {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    }
                }
                break;
            case 5:
                // modify contacts
                while (true) {
                    int index = 0;
                    cout << "Please enter the index of the contact you want to modify: " << endl;
                    cin >> index;
                    contact ContactInfo;
                    // 修改所有类似输入操作（包括添加/修改联系人中的name/sex/addr字段）：
                    cout << "Please enter the name: " << endl;
                    cin >> ContactInfo.name;
                    cout << "Please enter the sex: " << endl; 
                    cin >> ContactInfo.sex;
                    cout << "Please enter the age: " << endl;
                    cin >> ContactInfo.age;
                    cout << "Please enter the phone: " << endl;
                    cin >> ContactInfo.phone;
                    cout << "Please enter the addr: " << endl;
                    cin >> ContactInfo.addr;
                    if (ModifyContact(index - 1, ContactInfo) == 0) {
                        cout << "Modify contact success" << endl;
                        cout << "Do you want to modify another contact? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice;
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                        else {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    }
                    else {
                        cout << "Modify contact failed" << endl;
                        cout << "Do you want to remodify contact? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice;
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                        else {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    }
                }
                break;
            case 6:
                // clear contacts
                while (true) {
                    if (ClearContacts() == 0) {
                        cout << "Clear contacts success" << endl;
                        break;
                    }
                    else {
                        cout << "Clear contacts failed" << endl;
                        cout << "Do you want to clear contacts again? (y/n)" << endl;
                        char choice = 0;
                        cin >> choice;
                        if (choice == 'n') {
                            break;
                        }
                        else if (choice == 'y') {
                            continue;
                        }
                        else {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    }
                }
                break;
            case 7:
                // exit
                return 0;
            default:
                // invalid choice
                break;
        }
    }
}