#include<bits/stdc++.h>
using namespace std;

struct node{
   int data;
   struct node *link;
   };

   int isPalindrome(struct node* head){
    struct node *regular=head,*fast=head;
    struct node *prev=NULL,*temp=NULL;

    while(fast != NULL && fast->link != NULL){
        fast = fast->link->link;

        temp = regular->link;
        regular->link = prev;
        prev = regular;
        regular = temp;
    }

    if(fast != NULL){
        regular = regular->link;
    }

    while(prev != NULL&& regular != NULL){
        if(prev->data != regular->data)
            return 0;
        prev = prev->link;
        regular = regular->link;
    }
    return 1;
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
    if(isPalindrome(head))
    {cout<<"The list is palindrome."<<endl;}
    else{
        cout<<"The list is not palindrome."<<endl;}
return 0;}
