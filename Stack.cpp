// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    
};

class Stack{
    
    struct node *head;
    public:
        Stack():head(NULL){}
	~Stack();
        void push(int data);
	int Pop();
        void displayStack();
};

Stack::~Stack()
{
    while( head !=NULL )
    {
        struct node *tmp;
	tmp = head;
	head = head->next;
	delete tmp;
    }
    head = NULL;
}

void Stack::push(int data)
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

int Stack::Pop()
{ 
    int val;
    struct node *headptr;
    
    if(NULL == head)
    {
        cout<<"Stack is empty"<<endl;
	return 0;
    }

    headptr = head;
    val = head->data;
    head = head->next;
    delete headptr;
    
    return val;
}

void Stack::displayStack()
{
    struct node *headptr = head;
    if(NULL == headptr )
    {
        cout<<"Stack is empty"<<endl;
	return;
    }
    
    while(headptr != NULL )
    {
         cout<<headptr->data<<endl;
         headptr = headptr->next;
    }
}

int main() {
    // Write C++ code here
    
    Stack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);

    obj.displayStack();

    obj.Pop();

    cout<<"After poping"<<endl;

    obj.displayStack();

    return 0;
}
