// stats.cxx - implements statistician class as defined in stats.h
// Crystal Eskander, April 11, 2017

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented

 namespace main_savitch_2C {
   
  // NON-MEMBER functions for the statistician class
  //statistican operator +(const statistician& s1, const statistician& s2);
   // statistician operator *(double scale, const statistician& s);
   //bool operator ==(const statistician& s1, const statistician& s2);

  statistician::statistician()
  {
    count=0;
    total=0;
  }

  void statistician:: next(double r)
  {
    if (count<=0)
      {
	count=1;
	total=r;
    tiniest=r;
	largest=r;

	return;

	count = count +1;
	total=total+r;
	if(r<tiniest)
	  {
	    tiniest=r;
	  }
	else if(largest <r)
	  {
	    largest =r;
	  }
          }
       
  }

  void statistician::reset()
  {
    count=0;
    total=0;

  }

  double statistician::mean () const
  {
    assert(length()>0);
    double average=0.0;
    average=total/count;
    return average;
  }

  double statistician::minimum() const
  {
    assert(length()>0);
    return tiniest;
  }

  double statistician::maximum () const
  {
    assert(length()>0);
    return largest;
  }

   //NON-MEMBER FUNCTIONS
   statistician operator +(const statistician& s1, const statistician& s2)
   {
     statistician end;
     end.next(s1.sum() + s2.sum());
     return end;
   }

   statistician operator *(double scale, const statistician& s)
   {
     statistician end;
     end.next(s.sum()*scale);
     return end;
   }
   bool operator ==(const statistician& s1, const statistician& s2)
   {
     return true;
   }
  
}    // STUDENT WORK HERE


  
 

