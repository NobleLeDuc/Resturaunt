/**
 * @file doublylinkedlist.h
 *
 * @brief
 *    Template for doubly linked list class.
 *
 * @date 1/1/16
 */
//Author: Noble LeDuc
//Data  : 9/13/2020
//Contains function definitions for the doubly linked list
#ifndef CSCI_311_DOUBLYLINKEDLIST_H
#define CSCI_311_DOUBLYLINKEDLIST_H
using namespace std;
template <class T>
class DoublyLinkedList {

 public:
   DoublyLinkedList();
   ~DoublyLinkedList();
   void append(T* data);
   bool empty() const { return (head == nullptr); }
   T* remove();
   T* first();
   T* next();

 private:
   class Node {
    public:
      Node();
      Node(T* data);
      Node* next;
      Node* prev;
      T* data;
   };
   Node* head;
   Node* tail;
   Node* current;
};
#endif // CSCI_311_DOUBLYLINKEDLIST_H
/**
 * @brief   Node constructor.
 */
template <class T>
DoublyLinkedList<T>::Node::Node() {

   // Your code here...
    next=NULL;
    prev=NULL;
    data=NULL;

}

/**
 * @brief   DoublyLinkedList constructor.
 */
template <class T>
DoublyLinkedList<T>::Node::Node(T* d){
    //variable d contains the data to be stored in the node
    data=d;
    next=NULL;
    prev=NULL;
}
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {

    head=NULL;
    tail=NULL;
    current=NULL;
}

/**
 * @brief   DoublyLinkedList destructor.
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {

    if(head!=NULL){
	Node *p=head;
	Node *curr=p->next;
	while(curr != NULL){
	    head = curr;
	    delete p;
	    p=head;
	    curr=curr->next;
	}
	head=NULL;
	tail=NULL;
	delete p;
	p=NULL;
	curr=NULL;
    }
}

/**
 * @brief   Appends a new Node at the end of the DoublyLinkedList.
 * @param   data A pointer to the data to be stored in the new Node.
 * @return  Nothing.
 *
 * Creates a new Node to hold the data and appends the Node at the end
 * of the list. The current Node pointer is set to point to the newly
 * appended Node.
 */
template <class T>
void DoublyLinkedList<T>::append(T* d) {

   // Your code here...
    //variable d contains the data to be stored in the node
    Node *n = new Node(d);
    if(head==NULL){
	head=n;
	tail=n;
	current=n;
    }
    else{
	tail->next=n;
	n->prev=tail;
	tail=n;
	current=n;
    }
}

/**
 * @brief   Get the first thing on the list.
 * @return  A pointer to the data stored in the first Node on the list,
 *          or nullptr if the list is empty.
 *
 * The current pointer is set to point to the first Node in the list,
 * or nullptr if the list is empty.
 */
template <class T>
T* DoublyLinkedList<T>::first() {

   // Your code here...
    current=head;
    if(head!=NULL){
	return head->data;
    }
    else{
	return NULL;
    }

}

/**
 * @brief   Get the next thing on the list.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following whatever the current pointer is pointing
 *          to. If there is no next Node then nullptr is returned.





 *
 * The current pointer is set to point to the next Node in the list,
 * or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::next() {

   // Your code here...
	//current=head;
    if(current!=NULL){
	Node *tmp=current->next;
	current=tmp;
	if(tmp!=nullptr){
            return tmp->data;
	}
	else{
	    return nullptr;
	}
    }
    else{
            return NULL;
    }
}

/**
 * @brief   Remove the Node pointed to by the current pointer.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following the Node that was removed. If there is
 *          no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list, following
 * the Node that was removed, or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::remove() {

   // Your code here...
   //1.base case
    Node *tmp=current;
    if(head==NULL){
	return NULL;
    }
   //2.delete head node
    if(current==head){
	head=current->next;
	current=head;
	delete tmp;
	if(head!=nullptr){
	    current->prev=nullptr;
	    return head->data;
	}
	else{
	    return nullptr;
	}
    }
   //3.delete not last node
    if(current->next !=NULL){
	current->next->prev=current->prev;
	current->prev->next=current->next;
	current=current->next;
	delete tmp;
	return current->data;
    }
   //4.delte last node
    if(current->next==NULL){
	current->prev->next=current->next;
	tail=current->prev;
	current=current->next;
	delete tmp;
	if(current!=nullptr){
	    return current->data;
	}
	else{
	    return nullptr;
	}
    }
    return nullptr;
}
//#endif // CSCI_311_DOUBLYLINKEDLIST_H
