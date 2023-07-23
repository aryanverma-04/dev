#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void traversal(Node* head){
    Node* temp = head;
    while (temp!= NULL)
    {
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertHead(Node* &head, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        return;
    }
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertTail(Node* &head, int data){
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* tt = new Node(data);
    temp->next  = tt;
    tt->next = NULL;
}
void insertAfterValue(Node* &head, int data, int value){
    Node* temp = head;
    while (temp->data != data && temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;

}
void insertAfterIndex(Node* &head, int index, int data){
    if(index == 1){
        cout<<"Head wala called"<<endl;
        insertHead(head, data);
        return;
    };
    Node*temp = head;
    int i = 1;
    while (i != index)
    {
        i++; temp = temp->next;
    }
    if(temp == NULL){
        insertTail(head, data);
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteHead(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteTail(Node *&head){
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}
void deleteAtIndex(Node *&head, int index){
    int cnt = 1;
    Node* temp = head;
    Node* prev = NULL;
    while (cnt != index)
    {
        cnt++; prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}
bool floydsCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (slow !=NULL && fast!=NULL)
    {
        fast = fast ->next;
        if(fast != NULL){
            fast = fast ->next;
        }
        slow = slow ->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}
bool detectCycle(Node* head){
    map<Node*, bool> visited;
    Node*temp = head;
    while (temp!=NULL)
    {
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
Node* getTail(Node* head){
    Node*temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}
Node* reverseList(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev= curr;
        curr = next;
    }
    return prev;
}
void reverseRecursively(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    reverseRecursively(head, curr->next, curr);
    curr->next = prev;
}
int findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while (fast!=NULL )
    {
        cout<<"while ke andar"<<endl;
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    cout<<"while ke bahar"<<endl;
    return slow->data;
}
int main(){
    Node *head = NULL;
    traversal(head);
    insertHead(head, 10);
    insertHead(head, 20);
    traversal(head);
    insertTail(head, 30);
    traversal(head);
    insertAfterValue(head, 20, 777);
    traversal(head);     
    insertAfterIndex(head, 2, 5555);
    insertAfterIndex(head, 5, 5555);
    traversal(head);     
    deleteHead(head);
    traversal(head);
    deleteTail(head);     
    traversal(head);
    deleteAtIndex(head, 4);
    traversal(head);
    // Node* tail = getTail(head);
    // cout<<tail->data<<endl;
    // tail->next = head;
    // cout<<floydsCycle(head);
    // cout<<detectCycle(head);
    // traversal(head);
    // Node* newHead = reverseList(head);
    // traversal(newHead);

    // reverseRecursively(head, head, NULL);
    // traversal(head);

    cout<<findMiddle(head);
    return 0;
}
    // cout<<head->data<<endl;
    // void traversal(Node* head);
    // void insertHead(Node* head, int data);
    // void insertTail(Node* head, int data);
    // void insertAtIndex(Node* head, int data, int position);
    // void insertAfterData(Node* head, int data, int value);
    // void deleteHead(Node* head);
    // void deleteTail(Node* head);
    // void deleteAtIndex(Node* head, int index);
    // void deleteAtValue(Node* head, int value);
    // Node *newNode = new Node(29);
    // bool boolCycleDetection(Node* head);


    // insertHead(head, 20);
    // // head->next->data = 20;
    // // cout<<head->next->data;
    // head->next = newNode;