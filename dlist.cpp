#include "dlist.h"

template <typename T>
bool Dlist<T>::IsEmpty() const {
  if(first==0)
    return true;

  return false;
}
template <typename T>
void Dlist<T>::InsertFront(const T &o)
{
  if(!IsEmpty())
  {
    node NewNode;
    NewNode.o=o;
    NewNode.prev=last;
    NewNode.next=first;
    *first=NewNode;
  }
}

template <typename T>
void Dlist<T>::InsertBack(const T &o)
{
  if(!IsEmpty())
  {
    node NewNode;
    NewNode.o=o;
    NewNode.prev=last;
    NewNode.next=first;
    *last=NewNode;
  }
}

template <typename T>
T Dlist<T>::RemoveFront()
{
  return;
}

template <typename T>
T Dlist<T>::RemoveBack()
{
  return;
}

template <typename T>
Dlist<T>::Dlist()
{
  MakeEmpty();
}

template <typename T>
Dlist<T>::Dlist(const Dlist &l)
{
  MakeEmpty();
}

template <typename T>
Dlist<T>::~Dlist()
{

}

template <typename T>
void MakeEmpty()
{

}

template <typename T>
void RemoveAll()
{

}

template <typename T>
void CopyAll()
{

}