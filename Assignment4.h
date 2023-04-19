# include <vector>
# include <iostream>
using namespace std;

void InsertAfter(vector <int>&vec, int First, int Second){
  
    for (size_t i =0; i<vec.size(); i++){
        if(vec[i] == First)
        vec.insert(vec.begin() +i +1 ,Second);
    }
}

//The linkedList part :

class LinkedList{
public:

struct node{
    int number;
    node* next;
};

//This Struct is for number 4
struct Node_4{
    int number;
    int numOfOcc;
    Node_4* next;
};

node* head;

//Constructor
LinkedList(){
    head = new node;
    head->number = 0;
    head->next = NULL;
}


void AddNode(int num){
    node* temp = new node; // Allocate memory for temp
    temp->number = num;
    temp->next = NULL;
    if(head->next == NULL){
        head->next = temp;
    }
    else{
        node* current = head->next;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
}




void RemoveNode(node* N){
    node *q, *previous; 
    q=head;
    previous = NULL;
    while (q != NULL && q->number != N->number) {
        previous = q;
        q = q->next;
    }
    if (q != NULL) {
        if (previous == NULL) {
            head = q->next;
        } else {
            previous->next = q->next;
        }
        delete q;
    }
}


int returnSum(){
    node *q;
    q=head;
    int sum=0;
    while (q!=NULL)
    {
        sum+=q->number;
        q=q->next;
    }
    return sum; 
}


void PrintElements(){
    node* q;
    q=head;

    while(q!=NULL){
        cout<<q->number<<endl;
        q=q->next;
    }
}


Node_4* createLinkedList(vector<int> nums) {
    Node_4* head = NULL;

    for (int i = 0; i < nums.size(); i++) {
        // Check if the value already exists in the linked list
        int num = nums[i];
        Node_4* curr = head;
        while (curr != NULL) {
            if (curr->number == num) {
                curr->numOfOcc++;
                break;
            }
            curr = curr->next;
        }

        // If the value does not exist, create a new node and add it to the linked list
        if (curr == NULL) {
            Node_4* newNode = new Node_4{num, 1, NULL};
            if (head == NULL) {
                head = newNode;
            }
             else {
                newNode->next = head;
                head = newNode;
            }
        }
    }

    return head;
}

};
