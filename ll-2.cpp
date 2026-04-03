#include<bits/stdc++.h>

using namespace std;

   struct node{
   int data;
   struct node *link;
};

void findMiddle(struct node *head){
   struct node *regular = head, *fast = head;

   if(head == NULL){
      cout << "List is empty";
      return;
   }
   while(fast != NULL && fast->link != NULL){
        regular = regular -> link;
        fast = fast -> link -> link;
   }

   cout << regular -> data <<endl;
}

int main(){
     struct node *head,*current,*temp;

    int n;
    cout <<"Enter the number of elements : ";
    cin >> n;


    head = NULL;

    cout << "Enter the element : ";

    for(int i=0; i<n; i++){
        current = (struct node *)malloc(sizeof(struct node));
        cin >> current -> data;

        if(head == NULL){
            head = current;
        }
        else{
            temp -> link = current;
        }
        temp = current;
    }

    findMiddle(head);


return 0;
}
