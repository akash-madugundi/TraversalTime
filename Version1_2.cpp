#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void traverseArray(int arr[], int size){
     int value;
     for(int i=0;i<size;i++){
          value=arr[i];
     }
}

class Node{
     public:
          int data;
          Node* next;
     Node(int value){
          data=value;
          next=NULL;
     }
};

void traverseLinkedList(Node* head) {
     Node* current=head;
     int value;
     while(current!=NULL){
        value=current->data;
        current=current->next;
     }
}

int main()
{
     int n=10000;
     int arr[n];
     Node* head=NULL;
     for(int i=0;i<n;i++){
          arr[i]=rand();
          Node* p=new Node(rand());
          p->next=head;
          head=p;
     }
     auto start = high_resolution_clock::now();
     traverseArray(arr, n);
     auto stop = high_resolution_clock::now();
     auto duration=duration_cast<microseconds>(stop-start);
     cout<<"Array Time: "<<duration.count()<<endl;

     auto start2 = high_resolution_clock::now();
     traverseLinkedList(head);
     auto stop2 = high_resolution_clock::now();
     auto duration2=duration_cast<microseconds>(stop2-start2);
     cout<<"LinkedList Time: "<<duration2.count()<<endl;
     Node* current = head;
     while(current!=NULL){
        Node* temp=current;
        current=current->next;
        delete temp;
     }
     return 0;
}
