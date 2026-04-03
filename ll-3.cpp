#include<bits/stdc++.h>

using namespace std;

struct node{
  int data;
  struct node *link;
  };

  struct node* revrse(struct node *head){

      struct node *current = head,*prev = NULL, *next = NULL;

      if(current == NULL){
        cout <<"List is empty" <<endl;
        return NULL;
      }

      while(current != NULL){
          next = current -> link;
          current -> link = prev;
          prev = current;
          current = next;
      }

      return prev;
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
      cout <<"Original list : ";
      print(head);

      head = revrse(head);
      cout << "Reverse : ";
      print(head);
      cout<<endl;
return 0;
}
