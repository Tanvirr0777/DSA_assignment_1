#include<bits/stdc++.h>

using namespace std;
struct node{
  int data;
  struct node *link;
  };
 void update(struct node *head,int old,int newValue){
      struct node *temp = head;

      if(head == NULL){cout<<"List is empty";
      return;}

      while(temp != NULL ){
           if(temp -> data == old){
             temp -> data = newValue;
           }
           temp = temp -> link;
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
    int old,newValue;
    cout<<"Old value : ";
    cin>>old;
    cout<<"New Value : ";
    cin >> newValue;
    update(head,old,newValue);
    cout<<"After update : ";
    print(head);
return 0;
}

