// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    
};

class List{
    
    struct node *head;
    
    public:
        List():head(NULL){}
	~List();
        void addNode(int data);
        void displayList();
};

List::~List()
{
    struct node *headptr;
    while(head != NULL )
    {
         headptr = head;
	 head = head->next;
	 delete headptr;
    }
}

void List::addNode(int data)
{
    struct node *newnode = NULL;
    if(head == NULL)
    {
        newnode = new struct node;
        newnode->data =  data;
        newnode->next = NULL;
        head = newnode;
    } else {
        newnode = new struct node;
        newnode->data =  data;
        newnode->next = head;
        head = newnode;
    }
}

void List::displayList()
{
    struct node *headptr = head;
     while(headptr != NULL )
     {
         cout<<headptr->data<<endl;
         headptr = headptr->next;
     }
}

int main() {
    // Write C++ code here
    
    List obj;
    obj.addNode(1);
    obj.addNode(2);
    obj.addNode(3);

    obj.displayList();
    return 0;
}
