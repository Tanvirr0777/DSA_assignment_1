#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *link;
};

void countNode(struct node *head){

    struct node *temp = head;

    int counT = 0;

    while(temp != NULL){
    cout << temp -> data <<" ";
    counT ++;
    temp = temp -> link;
 }

 cout <<endl<< "Total node :" << counT<<endl;
}

int main(){

 struct node *head,*current;

 head = (struct node *)malloc(sizeof(struct node));
 head -> data = 45;
 head -> link = NULL;

 current = (struct node *)malloc(sizeof(struct node));
 current -> data = 98;
 current -> link = NULL;

 head -> link = current;


 current = (struct node *)malloc(sizeof(struct node));
 current -> data = 3;
 current -> link = NULL;

 head -> link -> link = current;

  countNode(head);

return 0;
}
