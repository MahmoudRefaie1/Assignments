# include "Assignment4.h"


int main(){
    vector<int>Vec (5);
    int first, second;
    cout<< "Please fill the vector with integers \n";
    for(size_t x= 0; x<Vec.size(); x++)
    cin >> Vec[x];

    cout<< "Enter the First value \n";
    cin >> first;
    cout<< "Enter the Second value \n";
    cin>> second;

    InsertAfter(Vec, first, second);

    for(int i =0; i<Vec.size(); i++)
     cout<< "Vec [" << i << "] = " << Vec[i] << endl;

     cout<<"First func tested! \n Now testing the linked list...\n";


    // Test LinkedList class
    LinkedList ll;
    ll.AddNode(1);
    ll.AddNode(2);
    ll.AddNode(3);
    ll.PrintElements();
    cout<<"Sum of the nodes is : "<<ll.returnSum() << endl;
    
    //Testing the remove func
    ll.RemoveNode(ll.head->next);
    ll.PrintElements();
   
    //Testing Question no.4. I did not understand whether I am supposed to use one struct or two. However, I've used 2.
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    LinkedList::Node_4* head = ll.createLinkedList(nums);
    LinkedList::Node_4* curr = head;
    while (curr != NULL) {
        cout << curr->number << " (occurs " << curr->numOfOcc << " times)" << endl;
        curr = curr->next;
    }
   

    return 0;
}




