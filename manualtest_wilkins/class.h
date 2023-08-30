#include<iostream>
#include<fstream>
#include<string>
#include <cassert>
using namespace std;
struct Data {
    int score; //�X�R�A
    string username; //���[�U�[��

    Data(int score, const string& username) : score(score), username(username) {}//�X�R�A�ƃ��[�U�[���̃R���X�g���N�^
};
class DoublyLinkedList {
    //public:
private:
    struct Node {
        Node* prev; //�O�̃m�[�h�ւ̃|�C���^
        Node* next; //���̃m�[�h�ւ̃|�C���^
        Data data; //���уf�[�^

        Node(int score, const string& username) : prev(nullptr), next(nullptr), data(score, username) {}//�m�[�h�\���̂̃R���X�g���N�^
    };
    Node* head;//�m�[�h�ւ̃|�C���^
    //Node* tail;//�m�[�h�ւ̃|�C���^
    size_t size;//�f�[�^���̎擾
public:
    Node* getHead()const {
        return head;
    }
    //Node* getTail()const {
    //    return tail;
    //}
    size_t getSize() const {
        return size;
    }
    DoublyLinkedList() : head(nullptr),/* tail(nullptr)*/ size(0) {}//DoublyLinkedList�̃R���X�g���N�^
    class ConstIterator {
    public:
        Node* current;//���݂̃m�[�h
        ConstIterator(Node* node) : current(node) {} //current�̃R���X�g���N�^
        const Data& operator*() const {
            //assert(current != nullptr);
            return current->data;//�C�e���[�^�̎w���v�f�̎擾
        }

        ConstIterator& operator++() {
            //assert(current != nullptr);
            if (current) {
                current = current->next;//���X�g�̖����Ɉ�i�߂�
            }
            return *this;
        }

        ConstIterator& operator--() {
            //assert(current != nullptr);
            if (current) {
                current = current->prev;//���X�g�̐擪�Ɉ�i�߂�
            }
            return *this;
        }
        ConstIterator& operator=(const ConstIterator& other) {
            if (this != &other) {
                current = other.current;//���
            }
            return *this;
        }

        bool operator==(const ConstIterator& other) const {
            return current == other.current;//���ꂩ��r
        }

        bool operator!=(const ConstIterator& other) const {
            return current != other.current;//�قȂ邩��r
        }


    };
    ConstIterator begin() const {
        return ConstIterator(head);//�R���X�g�C�e���[�^�̐擪��Ԃ�
    }

    ConstIterator end() const {
        return ConstIterator(head);//�R���X�g�C�e���[�^�̖�����Ԃ� 
    }
    class Iterator :public ConstIterator {
    public:
        Node* current;
        Iterator(Node* node) :ConstIterator(node), current(node) {
            current = node;//current��node����
        }

        Data& operator*() {
            return current->data;//��const�ł̎擾
        }
        operator ConstIterator() const {
            return ConstIterator(current);
        }
    };
    Iterator begin() {
        //Node* dummyNode = new Node(-1, ""); // �_�~�[�m�[�h�̍쐬
        //dummyNode->next = dummyNode->prev = dummyNode;

        //if (head == nullptr) {
        //    return Iterator(dummyNode);
        //}
        return Iterator(head);//�C�e���[�^�̐擪��Ԃ�
    }

    Iterator end() {
        return Iterator(head);//�C�e���[�^�̖�����Ԃ�
    }

    void insert(Iterator position, int score, const string& username) {
        Node* newNode = new Node(score, username);
        if (position == begin()) {
            if (head == nullptr) { // ��̃��X�g�̏ꍇ
                head = newNode;
                newNode->prev = newNode->next = newNode;
            }
            else {
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
                if (position.current == head) {
                    head = newNode;
                }
            }
        }
        else if (position == end()) {

        }
        else {
            Node* prevNode = position.current->prev;
            newNode->prev = prevNode;
            newNode->next = position.current;
            prevNode->next = newNode;
            position.current->prev = newNode;
        }
        size++;
    }

    const void Constinsert(ConstIterator position, const int score, const string& username) {
        Node* newNode = new Node(score, username);
        if (position == begin()) {
            if (head == nullptr) { // ��̃��X�g�̏ꍇ
                head = newNode;
                newNode->prev = newNode->next = newNode;
            }
            else {
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
                if (position.current == head) {
                    head = newNode;
                }
            }
        }
        else if (position == end()) {

        }
        else {
            Node* prevNode = position.current->prev;
            newNode->prev = prevNode;
            newNode->next = position.current;
            prevNode->next = newNode;
            position.current->prev = newNode;
        }
        size++;
    }
    void remove(Iterator position) {
        if (position == begin()) {
            if (size == 1) { //�T�C�Y��1�̏ꍇ
                head = nullptr;
            }
            else {
                Node* nextNode = position.current->next;//�m�[�h������
                nextNode->prev = position.current->prev;//�m�[�h���ЂƂO��
                position.current->prev->next = nextNode;
                if (position.current == head) {
                    head = nextNode;
                }
                delete position.current;
            }
        }
        else {
            Node* prevNode = position.current->prev;//�ЂƂO��
            Node* nextNode = position.current->next;//����
            prevNode->next = nextNode;//prevNode��nextNode��
            nextNode->prev = prevNode;//Nextnode��prevNode��
            delete position.current;
        }
        size--;
    }
    void Constremove(ConstIterator position) {
        if (position == begin()) {
            if (size == 1) { //�T�C�Y��1�̏ꍇ
                head = nullptr;
            }
            else {
                Node* nextNode = position.current->next;//�m�[�h������
                nextNode->prev = position.current->prev;//�m�[�h���ЂƂO��
                position.current->prev->next = nextNode;
                if (position.current == head) {
                    head = nextNode;
                }
                delete position.current;
            }
        }
        else {
            Node* prevNode = position.current->prev;//�ЂƂO��
            Node* nextNode = position.current->next;//����
            prevNode->next = nextNode;//prevNode��nextNode��
            nextNode->prev = prevNode;//Nextnode��prevNode��
            delete position.current;
        }
        size--;
    }

};
