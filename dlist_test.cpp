/*#include <iostream>
#include <string>
#include "dlist.h"

using namespace std;

enum Job {STUDENT, FACULTY, STAFF};

struct Record {
    string name;
    string uniqname;
    Job job;
};

int main() {

  Dlist<Record*> catsweb; //records are big, so store pointer

  Record* p = new Record;
  p->name = "Andrew DeOrio";
  p->uniqname = "awdeorio";
  p->job = FACULTY;
  catsweb.InsertFront( p );

  Record* q = new Record;
  q->name = "Preston DeLeon";
  q->uniqname = "pdeleon";
  q->job = STUDENT;
  catsweb.InsertFront( q );

  Record* s = new Record;
  s->name = "Elyse Coleman";
  s->uniqname = "ecole";
  s->job = STAFF;
  catsweb.InsertFront( s );

  Record *c=catsweb.RemoveBack();
  cout << c->uniqname<<endl;

  Record* y = new Record;
  y->name = "Micheala Willis";
  y->uniqname = "mwillis";
  y->job = STAFF;
  catsweb.InsertBack( y );


  Dlist<Record*> copycat(catsweb);

  catsweb=copycat;
  // do something with "catsweb"

  // don't forget to delete objects on the heap
  while ( !copycat.IsEmpty() ) {
    Record *r = copycat.RemoveBack();
    cout << r->uniqname << endl;
    r=nullptr;
    delete r;
  }

  return 0;
}
*/