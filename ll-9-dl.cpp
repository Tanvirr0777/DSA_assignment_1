#include<bits/stdc++.h>

using namespace std;

struct dnode{
    int data;
    struct dnode *prev,*link;
   };

void print(struct dnode *head){
    struct dnode* temp = head;
    while(temp != NULL){
        cout <<temp -> data<<" ";
        temp = temp -> link;
    }
    cout<<endl<<endl;
}

void insertBeginning(struct dnode **head){
       int newValue;
       cout<<"Enter new value: ";
      cin >> newValue;
    struct dnode *newNode = (struct dnode*)malloc(sizeof(struct dnode));

    newNode->data = newValue;
    newNode->prev = NULL;
    newNode->link = *head;

    if(*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
     cout<<"Now list is : ";
     print(*head);
}

void insertEnd(struct dnode **head){
    int newValue;
    cout<<"Enter new value: ";
    cin >> newValue;

    struct dnode *newNode = (struct dnode*) malloc(sizeof(struct dnode));
    newNode->data=newValue;
    newNode->link=NULL;

    struct dnode *temp = *head;;

    while( temp->link != NULL){
          temp=temp->link;
         }
          temp->link=newNode;
          newNode->prev= temp;

     cout<<"Now list is : ";
     print(*head);
}

void insertPosition(struct dnode **head){
    int pos,newValue;
    cout<<"Enter the position: ";
    cin >> pos;
     if(pos == 1){
        insertBeginning(&(*head));
        return;
    }
    cout<<"Enter new value: ";
    cin >> newValue;

    struct dnode *newNode = (struct dnode*)malloc(sizeof(struct dnode));
    newNode->data=newValue;

    struct dnode *temp = *head;

    for(int i=1;i<pos-1;i++)
        temp=temp->link;

    newNode->link=temp->link;
    newNode->prev=temp;

    if(temp->link)
        temp->link->prev=newNode;

    temp->link=newNode;

    print(*head);
}

void insertSorted(struct dnode **head){
     int newValue;
      cout<<"Enter new value: ";
      cin >> newValue;
    struct dnode *newNode=(struct dnode*)malloc(sizeof(struct dnode));
    newNode->data=newValue;

    struct dnode *temp=*head;

    if(temp==NULL || newValue < temp->data){
        newNode->link=temp;
        newNode->prev=NULL;
        if(temp) temp->prev=newNode;
        *head=newNode;
        return;
    }

    while(temp->link && temp->link->data<newValue)
        temp=temp->link;

    newNode->link=temp->link;
    if(temp->link) temp->link->prev=newNode;
    temp->link=newNode;
    newNode->prev=temp;

    cout<<"List is : ";
    print(*head);
}

void deleteBeginning(struct dnode **head){
    if(*head == NULL){
        cout << "List is empty. Nothing to delete."<<endl;
        return;
    }

    struct dnode *temp = *head;
    *head = (*head)->link;

    if(*head)
        (*head)->prev = NULL;

    free(temp);
    cout << "Now list is : ";
    print(*head);
}

void deleteEnd(struct dnode **head){
    if(*head == NULL){
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    struct dnode *temp = *head;

    while(temp->link != NULL)
        temp = temp->link;

    if(temp->prev)
        temp->prev->link = NULL;
    else
        *head = NULL;

    free(temp);
    cout << "Now list is : ";
    print(*head);
}

void deletePosition(struct dnode **head){
    int pos;
    cout << "Enter the position: ";
    cin >> pos;

    if(*head == NULL){
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    struct dnode *temp = *head;

    if(pos == 1){
        deleteBeginning(head);
        return;
    }

    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->link;

    if(temp == NULL){
        cout << "Position out of range.\n";
        return;
    }

    if(temp->prev)
        temp->prev->link = temp->link;
    if(temp->link)
        temp->link->prev = temp->prev;

    free(temp);
    cout << "Now list is : ";
    print(*head);
}

void deleteAllOccurrences(struct dnode **head){
    int val;
    cout << "Enter value to delete all occurrences: ";
    cin >> val;

    if(*head == NULL){
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    struct dnode *temp = *head;

    while(temp != NULL){
        if(temp->data == val){
            struct dnode *toDelete = temp;

            if(temp->prev)
                temp->prev->link = temp->link;
            else
                *head = temp->link;  // Node is head

            if(temp->link)
                temp->link->prev = temp->prev;

            temp = temp->link;
            free(toDelete);
        } else {
            temp = temp->link;
        }
    }

    cout << "Now list is : ";
    print(*head);
}

void update(struct dnode **head){
     int old,newVal;
     cout<<"Enter old data : ";
     cin >> old;
     cout<<"Enter new data : ";
     cin >> newVal;
     struct dnode *temp = *head;
    while(temp != NULL){
        if(temp->data==old)
            temp->data=newVal;
        temp=temp->link;
    }
    cout<<"Now list is : ";
    print(*head);
}

void copyList(struct dnode* head){
    struct dnode *newHead=NULL,*tail=NULL;

    while(head){
        struct dnode *newnode=(struct dnode*)malloc(sizeof(struct dnode));
        newnode->data=head->data;
        newnode->link=NULL;

        if(!newHead){
            newHead=tail=newnode;
            newnode->prev=NULL;
        }else{
            tail->link=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        head=head->link;
    }
    cout<<"Coppy : ";
    print(newHead);
}

void mergelist(struct dnode* old){
    cout<<"Enter another list ";
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    struct dnode *newHead = NULL, *temp, *current;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        current = (struct dnode*)malloc(sizeof(struct dnode));
        cin >> current->data;

        current->prev = NULL;
        current->link = NULL;

        if(newHead == NULL){
            newHead = current;
            temp = current;
        }
        else{
            temp->link = current;
            current->prev = temp;
            temp = current;
        }
    }
    cout <<"The 1st list is : ";
    print(old);
    cout<<"The 2nd list is : ";
    print(newHead);


    struct dnode *tempo=old;

    while(tempo->link)
        tempo=tempo->link;

    tempo->link=newHead;
    newHead->prev=tempo;

    cout<<"After merge two list : ";
    print(old);
}

void split(dnode* head) {
    if (!head) return;

    dnode *first = NULL, *second = NULL;
    dnode *slow = head, *fast = head;

    while (fast->link && fast->link->link) {
        slow = slow->link;
        fast = fast->link->link;
    }

    first = head;
    second = slow->link;

    slow->link = nullptr;
    if (second)
        second->prev = nullptr;

    cout << "First half: ";
    print(first);
    cout << "Second half: ";
    print(second);
}


int main(){

  int n;
    cout << "Enter number of elements: ";
    cin >> n;

    struct dnode *head = NULL, *temp, *current;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        current = (struct dnode*)malloc(sizeof(struct dnode));
        cin >> current->data;

        current->prev = NULL;
        current->link = NULL;

        if(head == NULL){
            head = current;
            temp = current;
        }
        else{
            temp->link = current;
            current->prev = temp;
            temp = current;
        }
    }
    cout<<"The list is : ";
    print(head);

   int choice;

    do {
        cout <<endl<< "Linked List Menu"<<endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Delete node" << endl;
        cout << "3. Update node with new value" << endl;
        cout << "4. Copying a linked list to other linked list" << endl;
        cout << "5. Merging two linked list" << endl;
        cout << "6. Splitting a linked list" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout <<endl<< "Insert new node selected" << endl;
                int select;
                do{
                    cout<<"1.Insert at beginning"<<endl;
                    cout<<"2.Insert at end"<<endl;
                    cout<<"3.Insert at specific position"<<endl;
                    cout<<"4.Insert in a sorted list"<<endl;
                    cout << "0. Exit" << endl;

                    cout << "Enter your choice: ";
                    cin >> select;

                switch(select){
                    case 1:
                      cout<<"1.Insert at beginning"<<endl;
                      insertBeginning(&head);
                      break;

                    case 2:
                        cout<<"2.Insert at end"<<endl;
                        insertEnd(&head);
                        break;

                    case 3:
                         cout<<"3.Insert at specific position"<<endl;
                         insertPosition(&head);
                         break;
                    case 4:
                         cout<<"4.Insert in a sorted list"<<endl;
                         insertSorted(&head);
                         break;
                }
                }while(select != 0);

               break;

            case 2:
                cout <<endl<< "Delete node selected" << endl;
                 int selectD;
                do{
                    cout<<"1.Delete at beginning"<<endl;
                    cout<<"2.Delete at end"<<endl;
                    cout<<"3.Delete at specific position"<<endl;
                    cout<<"4.All occurrence of nodes with a specific value"<<endl;
                    cout << "0. Exit" << endl;

                    cout << "Enter your choice : ";
                    cin >> selectD;

                switch(selectD){
                    case 1:
                      cout<<"1.Delete at beginning"<<endl;
                      deleteBeginning(&head);
                      break;

                    case 2:
                        cout<<"2.Delete at end"<<endl;
                        deleteEnd(&head);
                        break;

                    case 3:
                         cout<<"3.Insert at specific position"<<endl;
                         deletePosition(&head);
                         break;
                    case 4:
                         cout<<"4.All occurrence of nodes with a specific value"<<endl;
                         deleteAllOccurrences(&head);
                         break;
                }
                }while(select != 0);
                break;

            case 3:
                cout << "Update node selected" << endl;
                update(&head);
                break;

            case 4:
                cout <<endl<< "Copy linked list selected" << endl;
                copyList(head);
                break;

            case 5:
                cout <<endl<< "Merge linked list selected" << endl;
                mergelist(head);
                break;

            case 6:
                cout <<endl<< "Split linked list selected" << endl;
                split(head);
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 0);

return 0;
}
