// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
};

class Queue
{

  struct node *head;
  struct node *tail;

public:
  Queue () : head (NULL), tail (NULL) {}
  void enQueue (int data);
  int deQueue ();
  void displayQueue ();
};

void
Queue::enQueue (int data)
{
  struct node *newnode = NULL;
  if (tail == NULL)
    {
      newnode = new struct node;
      newnode->data = data;
      newnode->next = NULL;
      head = newnode;
      tail = newnode;
    }
  else
    {
      newnode = new struct node;
      newnode->data = data;
      newnode->next = NULL;
      tail->next = newnode;
      tail = newnode;
    }
}

int
Queue::deQueue ()
{
  int val;
  if (head == tail && head == NULL)
    {
      cout << "Queue is empty";
      return 0;
    }
  else if (head == tail)
    {
      struct node *tmpnode;
      // cout<<head->data<<endl;
      val = head->data;
      tmpnode = head;
      delete tmpnode;
      head = NULL;
      tail = NULL;
    }
  else
    {
      struct node *tmpnode;
      // cout<<head->data<<endl;
      val = head->data;
      tmpnode = head;
      head = head->next;
      delete tmpnode;
    }

  return val;
}
void
Queue::displayQueue ()
{
  struct node *headptr = head;
  if (headptr == NULL)
    {
      cout << "Queue is empty" << endl;
      return;
    }
  while (headptr != NULL)
    {
      cout << headptr->data << endl;
      headptr = headptr->next;
    }
}

int
main ()
{
  // Write C++ code here
  // std::cout << "Try programiz.pro"<<endl;

  Queue obj;
  obj.enQueue (1);
  obj.enQueue (2);
  obj.enQueue (3);

  obj.displayQueue ();
  obj.deQueue ();
  obj.deQueue ();
  obj.deQueue ();

  cout << "After delete" << endl;
  obj.displayQueue ();
  return 0;
}
