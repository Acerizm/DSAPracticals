/** @file Stack.h */

//typedef float ItemType;

/** ADT stack - Pointer-based implementation. */
template <typename ItemType>
class Stack 
{
private:
	ItemType *Data;
	/** A node on the stack. */
	struct Node
	{
		/** A data item on the stack. */
		ItemType item;
		/** Pointer to next node.     */
		Node    *next;
	}; // end StackNode
	
	/** Pointer to first node in the stack. */
	Node *topNode;
	
public:
   /** Default constructor. */
   Stack();
   /** Destructor. */
   ~Stack();

// Stack operations:
   bool isEmpty();
   bool Push(ItemType& item);
   bool Pop();
   ItemType getTop();
   void displayInOrderOfInsertion();

}; // end Stack
// End of header file.

template <typename ItemType>
Stack<ItemType>::Stack()
{
	topNode = NULL;
}  // end default constructor

template <typename ItemType>
Stack<ItemType>::~Stack()
{
   // pop until stack is empty
   while (!isEmpty())
      Pop();
   // Assertion: topPtr == NULL
}  // end destructor

template <typename ItemType>
bool Stack<ItemType>::isEmpty()
{
   return topNode == NULL;
}  // end isEmpty


template <typename ItemType>
bool Stack<ItemType>::Push(ItemType& item)
{ 
      Node *newNode = new Node;
      newNode->item = item;
	  newNode->next = NULL;

      // insert the new node
      newNode->next = topNode;
      topNode = newNode;
	 return true;
}  // end push

template <typename ItemType>
bool Stack<ItemType>::Pop() 
{
   if (isEmpty())
	   return false;
   else
   {  // stack is not empty; delete top
      Node *temp = topNode;
      topNode = topNode->next;
      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
	  return true;
   }  // end if
}  // end pop

template <typename ItemType>
ItemType Stack<ItemType>::getTop()
{
	ItemType item;
    if (!isEmpty())
      // stack is not empty; retrieve top
    item = topNode->item;
   return item;
}  // end getTop
// End of implementation file.

