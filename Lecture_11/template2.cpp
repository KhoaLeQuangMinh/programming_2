#include <iostream>
#include <cmath>
using namespace std;
template <typename T>
class Node{
    public:
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
};
template <typename T>
class LinkedList{
    private:
        Node<T> *head;
        Node<T> *tail;
    public:
        LinkedList(): head(nullptr), tail(nullptr){};
        void append(T value){
            Node<T>* newNode = new Node<T>(value);
            if(!head){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        };
        void prepend(T value){
            Node<T>* newNode = new Node<T>(value);
            if(!head){
                head = newNode;
                tail = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        };
        void insert(int idx, T value) {
            if (idx == 0) {
                prepend(value);
                return;
            }

            int count = 0;
            Node<T>* temp = head;

            while (temp && count < idx - 1) {
                temp = temp->next;
                count++;
            }

            if (temp) {
                Node<T>* newNode = new Node<T>(value);
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == tail) {
                    tail = newNode;
                }
            } else if (count == idx - 1 && !temp) {
                append(value);
            } else {
                cout << "Index out of range!" << endl;
            }
        }
        Node<T>* find(T value){
            Node<T> *temp = head;
            while(temp){
                if(temp->data == value){
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        };
        T get(int idx){
            Node<T>*temp = head;
            int count = 0;
            if(idx == 0){
                return head->data;
            }
            while(temp && count < idx){
                temp = temp->next;
                count++;
            }
            if(temp){
                return temp->data;
            }
            else{
                cout<<"Index out of range!"<<endl;
                return 0;
            }
        };
        void replace(T oldVal, T newVal){
            Node<T>* temp = head;
            while(temp){
                if(temp->data == oldVal){
                    temp->data = newVal;
                }
                temp = temp->next;
            }
        }
        int isEmpty(){
            if(!head){
                return 1;
            }
            return 0;
        }
        void remove(int idx){
            Node<T>*temp = head;
            int count = 0;
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            if(idx == 0){
                Node<T> *toDelete = head;
                head = head->next;
                if(tail == toDelete){
                    tail = nullptr;
                }
                delete toDelete;
                return;
            }
            while(temp && count < idx-1){
                temp = temp->next;
                count++;
            }
            if(temp){
                Node<T> *toDelete = temp->next;
                temp->next = toDelete->next;
                if(tail == toDelete){
                    tail = temp;
                }
                delete toDelete;
            }else{
                cout<<"Index out of range!"<<endl;
            }
        }
        void clear(){
            Node<T> * temp = head;
            while(temp){
                Node<T>* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            head = nullptr;
            tail = nullptr;
        }
};
int main() {
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    list.prepend(0);

    list.insert(2, 99);

    for (int i = 0; i < 5; i++) {
        cout << list.get(i) << " ";
    }
    cout << endl;

    list.replace(99, 100);

    for (int i = 0; i < 5; i++) {
        cout << list.get(i) << " ";
    }
    cout << endl;

    list.remove(2);

    for (int i = 0; i < 4; i++) {
        cout << list.get(i) << " ";
    }
    cout << endl;

    Node<int>* found = list.find(3);
    if (found) {
        cout << "Found " << found->data << endl;
    } else {
        cout << "Not found" << endl;
    }

    list.clear();

    cout << (list.isEmpty() ? "Empty" : "Not empty") << endl;

    return 0;
}

