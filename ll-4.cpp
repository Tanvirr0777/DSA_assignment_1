#include<bits/stdc++.h>
using namespace std;
struct node{
   int data;
   struct node *link;

   };
 struct node* deleteValue(struct node *head,int key){
      struct node *temp = head, *prev = NULL;
      if(head == NULL){
          cout <<"List is empty"<<endl;

          return NULL;
      }
    while(temp != NULL){
        if(temp->data == key){
            if(prev == NULL){
                head = temp->link;
                free(temp);
                temp = head;
            }else{
                prev->link = temp->link;
                free(temp);
                temp = prev->link;
            }
        }else{
            prev = temp;
            temp = temp->link;
        }
    }
    return head;
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
    int key;
    cout<<"Enter value that will delete : ";
    cin >> key;

    head = deleteValue(head,key);
    cout<<"After delete : ";
    print(head);
return 0;
}
