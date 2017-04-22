
struct Node
{
   int data;
   struct Node *next;
}

/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
*/
Node* InsertInTail(Node *head, int data)
{
    if (head == NULL)
    {
      head = new Node;
      head->data = data;
      head->next = NULL;
    }
    else
    {
        Node *temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
    }
    return head;
}

/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as
  struct Node
  {\a
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* InsertInHead(Node *head,int data)
{
  // Complete this method
    if(head == NULL)
    {
        head = new Node;
        head->data = data;
        head->next = NULL;
    }
    else
    {
        Node *temp = head;
        head= new Node;
        head->data = data;
        head->next = temp;
    }
    return head;
}

/*
  Insert Node at a given position in a linked list
  head can be NULL
  First element in the linked list is at position 0
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
       // Complete this method only
  // Do not write main function.
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    if (position == 0)
    {
       newNode->next = head;
       return newNode;
    }


    Node *temp = head;
    for (int i = 0; i < position - 1; i++)
        temp = (temp->next != NULL) ? temp->next : temp;

    Node *tempBack = temp->next;
    newNode->next = tempBack;

    temp->next = newNode;

    return head;
}

/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    if (head == NULL || head->next == NULL)
        return NULL;

    if (position == 0)
        return head->next;

    Node *temp = head;
    for (int i = 0; i < position - 1; ++i)
        temp = (temp->next != NULL) ? temp->next : temp;

    temp->next = temp->next->next;
    return head;
}

/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
    if (head != NULL)
    {
        ReversePrint(head->next);
        std::cout << head->data << std::endl;
    }
}

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    // Complete this method
    if (head->next == NULL)
        return head;
    else
    {
        Node *reverseHead = Reverse(head->next);

        Node *temp = reverseHead;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = head;
        head->next = NULL;

        return reverseHead;
    }
}

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission.
  // You only need to complete this method
    if (headA == NULL && headB == NULL)
        return NULL;
    else if (headA == NULL && headB != NULL)
        return headB;
    else if (headA != NULL && headB == NULL)
        return headA;
    else if (headA->data < headB-> data)
    {
        headA->next = MergeLists(headA->next, headB);
        return headA;
    }
    else
    {
        headB->next = MergeLists(headA, headB->next);
        return headB;
    }
}

/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    Node *temp = head;
    int noNode = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        ++noNode;
    }

    int positionFromHead = noNode - positionFromTail - 1;

    temp = head;
    while (positionFromHead > 0)
    {
        temp = temp->next;
        --positionFromHead;
    }
    return temp->data;
}

/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    if (head == NULL)
        return NULL;

    else if (head->next == NULL)
        return head;

    else
    {
        Node *temp = head;
        Node *tempNext = temp->next;

        int dataTemp = temp->data;

        if (dataTemp == tempNext->data)
            temp->next = tempNext->next;
        else
            temp = temp->next;

        RemoveDuplicates(temp);

        return head;
    }
}

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method

    if (head == NULL || head->next == NULL)
        return false;

    Node * fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

/*
    Insert Node in a doubly sorted linked list
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.


    if (head == NULL)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
               return newNode;
    }

    else if (head->data > data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev = newNode;
        return newNode;
    }
    else
    {
        Node *newTemp = SortedInsert(head->next, data);
        head->next = newTemp;
        newTemp->prev = head;
        return head;
    }
}

/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method.
    //std::cout <<"head->data: ";// << head->data << std::endl;

    if (head == NULL || head->next == NULL)
        return head;

    while (head->next != NULL)
    {
        Node *headPrev = (head->prev != NULL) ? head->prev : NULL;
        head->prev = head->next;
        head->next = headPrev;

        head = head->prev;
    }

    head->next = head->prev;
    head->prev = NULL;

    return head;
}
