//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//    Node* prev;
//    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
//};
//
//class DoublyLinkedList {
//public:
//    Node* head;
//    Node* tail;
//
//    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
//
//    void insertEnd(int val) {
//        Node* newNode = new Node(val);
//        if (head == nullptr) {
//            head = tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            newNode->prev = tail;
//            tail = newNode;
//        }
//    }
//
//    void insertFront(int val) {
//        Node* newNode = new Node(val);
//        if (head == nullptr) {
//            head = tail = newNode;
//        }
//        else {
//            newNode->next = head;
//            head->prev = newNode;
//            head = newNode;
//        }
//    }
//
//    int getLength() {
//        int count = 0;
//        Node* temp = head;
//        while (temp != nullptr) {
//            count++;
//            temp = temp->next;
//        }
//        return count;
//    }
//
//    void removeLeadingZeros() {
//        while (head != nullptr && head->data == 0 && head->next != nullptr) {
//            Node* temp = head;
//            head = head->next;
//            head->prev = nullptr;
//            delete temp;
//        }
//    }
//
//    void display() {
//        Node* temp = head;
//        while (temp != nullptr) {
//            cout << temp->data << " <-> ";
//            temp = temp->next;
//        }
//        cout << "NULL" << endl;
//    }
//};
//
//void buildFromString(const string& num, DoublyLinkedList& list) {
//    for (char c : num) {
//        list.insertEnd(c - '0');
//    }
//}
//
//bool isFirstLarger(DoublyLinkedList& a, DoublyLinkedList& b) {
//    int lenA = a.getLength();
//    int lenB = b.getLength();
//    if (lenA != lenB) return lenA > lenB;
//
//    Node* pa = a.head;
//    Node* pb = b.head;
//    while (pa != nullptr) {
//        if (pa->data != pb->data) return pa->data > pb->data;
//        pa = pa->next;
//        pb = pb->next;
//    }
//    return true;
//}
//
//DoublyLinkedList subtract(DoublyLinkedList& larger, DoublyLinkedList& smaller) {
//    DoublyLinkedList result;
//
//    Node* p1 = larger.tail;
//    Node* p2 = smaller.tail;
//    int borrow = 0;
//
//    while (p1 != nullptr) {
//        int d1 = p1->data;
//        int d2 = (p2 != nullptr) ? p2->data : 0;
//
//        int diff = d1 - d2 - borrow;
//        if (diff < 0) {
//            diff += 10;
//            borrow = 1;
//        }
//        else {
//            borrow = 0;
//        }
//
//        result.insertFront(diff);
//
//        p1 = p1->prev;
//        if (p2 != nullptr) p2 = p2->prev;
//    }
//
//    result.removeLeadingZeros();
//    return result;
//}
//
//int main() {
//    string num1, num2;
//
//    cout << "Enter the first number: ";
//    cin >> num1;
//
//    cout << "Enter the second number: ";
//    cin >> num2;
//
//    DoublyLinkedList list1, list2;
//    buildFromString(num1, list1);
//    buildFromString(num2, list2);
//
//    cout << "First Number: ";
//    list1.display();
//
//    cout << "Second Number: ";
//    list2.display();
//
//    DoublyLinkedList result;
//    if (isFirstLarger(list1, list2)) {
//        result = subtract(list1, list2);
//    }
//    else {
//        result = subtract(list2, list1);
//    }
//
//    cout << "Result after subtraction: ";
//    result.display();
//
//    return 0;
//}