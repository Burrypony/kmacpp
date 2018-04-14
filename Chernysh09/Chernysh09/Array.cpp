/*#include "Array.h"
#include <iostream>
#include <string>

using namespace std;

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
   throw BadArray("Bad index: ", index);    
  return _allocator[index];
}

template <unsigned int n, typename t>
const t& Array<n, t>::operator[](const size_t index) const {
  if(index < 0 || index >= n) 
   throw BadArray("Bad index: ", index);    
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
}*/