#ifndef _ARRAY_H_ 
#define _ARRAY_H_
#include <iostream>
#include <string>
using namespace std;

template <unsigned int n, typename t>

class Array {
public:
 class BadArray;
 class BadArray {
 private:
 string _reason; 
 size_t _index;
 public:
 BadArray(const string& reason="unknown", const size_t index=0):
	   _reason(reason),
	   _index(index) 
	   {
		 return;
       }
 ~BadArray() {}
 void diagnose() const { 
     cerr << _reason; 
     if( _index != 0 ) 
      cerr << ' ' << _index;          
     cerr << endl;          
     return;       
    }   
 };
 explicit Array();
 ~Array();
 t& operator[](const size_t index);
 const t& operator[](const size_t index) const;
 size_t size() const; 
private:
 t* _allocator;
 bool operator==(const Array&) const;
 Array(const Array&);
 Array& operator=(const Array&);
};

template <unsigned int n, typename t>
ostream& operator<<(ostream& os, const  Array<n, t>& seq);
template <unsigned int n, typename t>
Array<n, t>::Array():
	_allocator(new t[n])
{
	return;
}

template <unsigned int n, typename t> 
Array<n, t>::~Array() {
 delete [] _allocator;
}

template <unsigned int n, typename t>  t& Array<n, t>::operator[](const size_t index)
{
  if(index < 0 || index >= n) 
   throw BadArray("Bad array's index: ", index);    
  return _allocator[index];
}

template <unsigned int n, typename t>
const t& Array<n, t>::operator[](const size_t index) const {
  if(index < 0 || index >= n) 
   throw BadArray("Bad array's index: ", index);    
  return _allocator[index];
}

template <unsigned int n, typename t>
size_t Array<n, t>::size() const {
 return n;
}

template <unsigned int n, typename t>
ostream& operator<<(ostream& os,const Array<n, t>& ar) {
 char chr=' ';
 cout<<"Array of "<<ar.size()<<':';
 for(size_t i=0; i<ar.size(); i++) {
 cout<<chr<<ar[i]; if(chr=' ') chr=',';
 }
 cout<<'.'<<endl;
 return os;
}
#endif