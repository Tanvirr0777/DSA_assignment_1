#include<bits/stdc++.h>

using namespace std;
struct node{
   int data;
   struct node *link;
   };
void insertAfter(struct node *head,int key,int newValue){
      struct node *temp = head;
      struct node *newNode;
      if(head == NULL){cout<<"List is empty";
      return;}
      while(temp != NULL){
          if(temp -> data == key){
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode -> data = newValue;

            newNode -> link = temp -> link;
            temp -> link = newNode;

            temp = newNode -> link;
          }else{
            temp = temp -> link;}
      }
   }
   void print(struct node *head){
     struct node *temp = head;

     while(temp != NULL){
        cout <<temp -> data <<" ";
        temp = temp -> link;
     }
     cout << endl;
  }
int main(){
    int n;
    cout <<"Enter the number of elements : ";
    cin >> n;
    struct node *head,*current,*temp;
    head = NULL;
    cout << "Enter the elements : ";
    for(int i=0; i<n; i++){
        current = (struct node *)malloc(sizeof(struct node));
        cin >> current -> data;

        if(head == NULL){
            head = current ;
        }
        else{
            temp -> link = current;
        }
        temp = current;
    }
    cout << "Original list : ";
    print(head);
    int key,newValue;
    cout <<"Insert value after : ";
    cin>>key;
    cout<<"New Value : ";
    cin >>newValue;

    insertAfter(head,key,newValue);
    cout <<"After insert : ";
    print(head);
return 0;
}
