#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  struct node *link;
  };
void removeDuplicates(struct node* head){
    struct node *ptr1, *ptr2, *dup;
    ptr1 = head;
    while(ptr1 != NULL && ptr1->link != NULL){
        ptr2 = ptr1;

        while(ptr2->link != NULL){
            if(ptr1->data == ptr2->link->data){
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
            }else{
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
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
    removeDuplicates(head);
    cout<<"After delete duplicate : ";
    print(head);

return 0;}
