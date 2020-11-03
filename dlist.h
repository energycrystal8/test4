#ifndef __DLIST_H__
#define __DLIST_H__


/***************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList {
    // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
    // OVERVIEW: contains a double-ended list of Objects

public:


    // Operational methods

    bool IsEmpty() const;
    // EFFECTS: returns true if list is empty, false otherwise

    void InsertFront(const T &o);
    // MODIFIES this
    // EFFECTS inserts o at the front of the list

    void InsertBack(const T &o);
    // MODIFIES this
    // EFFECTS inserts o at the back of the list

    T RemoveFront();
    // MODIFIES this
    // EFFECTS removes and returns first object from non-empty list
    //         throws an instance of emptyList if empty

    T RemoveBack();
    // MODIFIES this
    // EFFECTS removes and returns last object from non-empty list
    //         throws an instance of emptyList if empty

    // Maintenance methods
    Dlist();                                   // ctor (constructor)
    Dlist(const Dlist &l);                     // copy ctor (constructor)
    Dlist &operator=(const Dlist &l);          // assignment
    ~Dlist();                                  // dtor (destructor)

private:
    // A private type
    struct node {
        node   *next;
        node   *prev;
        T      o;
    };

    node   *first; // The pointer to the first node (0 if none)
    node   *last;  // The pointer to the last node (0 if none)
    //How us this different than the doubly linked list in class?

    // Utility methods

    void MakeEmpty();
    // EFFECT: called by constructors to establish empty
    // list invariant

    void RemoveAll();
    // EFFECT: called by destructor and operator= to remove and destroy
    // all list nodes

    void CopyAll(const Dlist &l);
    // EFFECT: called by copy constructor/operator= to copy nodes
    // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
*/



////////////////////////
template <typename T>
bool Dlist<T>::IsEmpty() const
{
  return first==nullptr;
}

////////////////////////
template <typename T>
void Dlist<T>::InsertFront(const T &o)
{
  node *NewNode=new node;

  NewNode->o=o;
  NewNode->next=nullptr;
  NewNode->prev=nullptr;

  if(IsEmpty())
  {
    first=last=NewNode;
  }
  else
  {
    NewNode->next=first;
    first->prev=NewNode;
    first=NewNode;
  }
}

////////////////////////
template <typename T>
void Dlist<T>::InsertBack(const T &o)
{
  node *NewNode=new node;

  NewNode->o=o;
  NewNode->next=nullptr;
  NewNode->prev=nullptr;

  if(!IsEmpty())
  {
    NewNode->prev = last;
    NewNode->next=nullptr;
    last=NewNode;
  }
  else
  {
    first=last=NewNode;
  }
}

////////////////////////
template <typename T>
T Dlist<T>::RemoveFront()
{
  node *dataNode=new node;

  if(IsEmpty())
  {
    emptyList e;
    throw e;
  }

  //single case
  if(first==last)
  {
    node *delNode=new node;
    delNode=first;
    first=last=nullptr;
    delete first;
    delete last;
    return delNode->o;
  }

  if(!IsEmpty())
  {
    node *nextNode = first->next;
    dataNode->o = first->o;

    if (nextNode->next != nullptr) {
      nextNode->prev = nullptr;
    }

    // remove first
    first=nullptr;
    delete first;

    first = nextNode;
  }
  else
  {
    emptyList e;
    throw e;
  }

  return dataNode->o;

}

////////////////////////
template <typename T>
T Dlist<T>::RemoveBack()
{
  if(IsEmpty())
  {
    emptyList e;
    throw e;
  }

  node *dataNode=new node;

  //single case
  if(first==last)
  {
    node *delNode=new node;
    delNode=last;
    last=first=nullptr;
    delete first;
    delete last;
    return delNode->o;
  }

  if(!IsEmpty())
  {
    node *prevPtr = last->prev;
    dataNode->o = last->o;

    if (prevPtr != nullptr) {
      prevPtr->next = nullptr;
    }

    // remove last
    last=nullptr;
    delete last;

    last = prevPtr;
  }
  else
  {
    emptyList e;
    throw e;
  }

  return dataNode->o;

}

////////////////////////
template <typename T>
Dlist<T>::Dlist()
{
  MakeEmpty();
}

////////////////////////
template <typename T>
Dlist<T>::Dlist(const Dlist &l)
{
  CopyAll(l);
}

////////////////////////
template <typename T>
Dlist<T>& Dlist<T>::operator=(const Dlist &l)
{
  if(&l == this)
    return *this;
  if(!l.IsEmpty())
  {
    RemoveAll();
    CopyAll(l);
  }
  return *this;
}

////////////////////////
template <typename T>
Dlist<T>::~Dlist()
{
  RemoveAll();
}

////////////////////////
template <typename T>
void Dlist<T>::MakeEmpty()
{
  first= nullptr;
  last=first;
}

////////////////////////
template <typename T>
void Dlist<T>::RemoveAll()
{
    if(!IsEmpty())
    {
      first = last = nullptr;
      delete first;
      delete last;

      node *delNode = first;
      node *del = new node;
      while (!IsEmpty()) {
        del = first;
        first = nullptr;
        delete first;
        del->next = first;
      }
      first = last = nullptr;
    }

}

////////////////////////
template <typename T>
void Dlist<T>::CopyAll(const Dlist &l) {
  if (l.first == nullptr) {
    first = nullptr;
    last = nullptr;
  } else {
    node *current = l.first;

    first = last = nullptr;

    while (current != nullptr) {
      //create a new Node to enter into the new List
      node *newNode = new node;
      newNode->prev = nullptr;
      newNode->next = nullptr;
      newNode->o = current->o;

      //add newNode to new List
      if (l.IsEmpty()) //new list is empty
        first = last = newNode;
      else //add newNode to end of new List
      {
        InsertBack(newNode->o);
      }
      current = current->next;
    }

  }
}


/*
 ***************************************/


/* this must be at the end of the file */
#endif /* __DLIST_H__ */
