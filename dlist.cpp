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