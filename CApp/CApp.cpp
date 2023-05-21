#include <iostream>
using namespace std;

struct User {
    string name;
    int age;
};

struct Node {
    User* user;
    Node* next;
    Node* prev;
};

struct List {
    Node* head;
    Node* tail;
    int size = 0;
};

Node* createNode(string name, int age) {
    Node* newNode = new Node;
    User* newUser = new User;
    newUser->name = name;
    newUser->age = age;

    newNode->user = newUser;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}


List* addToOrdered(List* list, string name, int age) {
    Node* newNode = createNode(name, age);
    Node* head = list->head;
    Node* tail = list->tail;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else if (name.compare(head->user->name) < 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != nullptr && temp->next->user->name.compare(name) < 0) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        else {
            tail = newNode;
        }
        temp->next = newNode;
    }

    list->head = head;
    list->tail = tail;
    list->size = ++list->size;
    
    return list;
}


void printList(List* list) {
    cout << list->size << endl;

    Node* temp = list->head;
    while (temp != nullptr) {
        cout << temp->user->name << ":" << temp->user->age << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    List* list = new List;
    Node* head = nullptr;
    Node* tail = nullptr;
    list->head = head;
    list->tail = tail;

    list = addToOrdered(list, "Vladimir", 32);
    list = addToOrdered(list, "Boris", 15);
    list = addToOrdered(list, "Yaroslav", 49);
    list = addToOrdered(list, "Angelina", 22);
    list = addToOrdered(list, "Evgeniy", 17);
    printList(list);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}


//List* addToStart(List* list, string name, int age) {
//    Node* newNode = createNode(name, age);
//    Node* head = list->head;
//    Node* tail = list->tail;
//
//    if (head == nullptr) {
//        head = newNode;
//        tail = newNode;
//    }
//
//    else if (head == tail) {
//        head = newNode;
//        newNode->next = tail;
//        tail->prev = head;
//    }
//    else {
//        head->prev = newNode;
//        newNode->next = head;
//        head = newNode;
//    }
//
//    list->head = head;
//    list->tail = tail;
//    list->size = ++list->size;
//
//    return list;
//}


//List* addToEnd(List* list, string name, int age) {
//    Node* newNode = createNode(name, age);
//    Node* head = list->head;
//    Node* tail = list->tail;
//
//    if (head == nullptr) {
//        head = newNode;
//        tail = newNode;
//    }
//    else if (head == tail) {
//        tail = newNode;
//        newNode->prev = head;
//        head->next = tail;
//    }
//    else {
//        tail->next = newNode;
//        newNode->prev = tail;
//        tail = newNode;
//    }
//
//    list->head = head;
//    list->tail = tail;
//    list->size = ++list->size;
//
//    return list;
//}
