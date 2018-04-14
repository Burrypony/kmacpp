#include "String.h"
#include <iostream>

using namespace std;



class String::BadString {
private:
 const string _reason; 
 const size_t _index; 
public:
 BadString(string reason="", const size_t index=0):
 _reason(reason),_index(index) {
 return;
 }
 ~BadString() {} 
};

class String::BadIndex {
private:
 const string _reason; 
 const size_t _index; 
public:
 BadIndex(string reason="", const size_t index=0):
 _reason(reason),_index(index) {
 return;
 }
 ~BadIndex() {} 
};

String::String():_allocator(new char[1]), _len(0) {
 _allocator[0]='\0';
 return;
};

String::~String()
{
	delete [] _allocator;
}

String::String(const char* st) {
 if(st==0)
 throw BadString("Attempt to use not defined pointer"); 
 _len=strlen(st); _allocator=new char[_len+1];
 strcpy(_allocator, st);
 return; 
};

String::String(const string& st)
{
	_len = st.length();
	_allocator = new char[_len + 1];
	strcpy(_allocator, st.c_str());
};


String::String(const char a):_allocator(new char[2]), _len(1) {
 _allocator[0]=a; _allocator[1]='\0';
 return;
}; 


String::String(const String& s, int multiplayer):
 _len(s._len*multiplayer),
 _allocator(new char [_len+1])
 {
 char* target=_allocator;
 for(int i=0; i<multiplayer; i++) {
 strcpy(target, s._allocator); 
 target+=s._len;
 }
 return;
};


const string String::STL_string() const
{
	return string(_allocator);
}

String& String::operator=(const String& st)
{
 delete [] _allocator;
 const char* stChar = st.c_str();
 for(_len=0; stChar[_len]; _len++);
	_allocator=new char[_len+1];
 strcpy(_allocator, stChar);
 return *this;
};

String& String::operator=(const string& st)
{
	delete [] _allocator;
	char *_allocator = new char[st.length() + 1];
	strcpy(_allocator, st.c_str());
	return *this;
}

String& String::operator=(const char* st) {
 if(st==0) 
	return *this;
 delete [] _allocator;
 for(_len=0; st[_len]; _len++);
	_allocator=new char[_len+1];
 strcpy(_allocator, st);
 return *this;
};

String& String::operator=(const char k) {
 delete [] _allocator; 
 _len=1; 
 _allocator=new char[2]; 
 _allocator[0]=k;
 _allocator[1]='\0';
 return *this;
}; 

const char* String::c_str() const
{
	return _allocator;
}

char& String::operator[](const size_t i) {
 if(_len<=i) throw BadIndex("Bad index: ", i);
 return _allocator[i];
}; const char String::operator[](const size_t i) const {
 if(_len<=i) throw BadIndex("Bad index: ", i);
 return _allocator[i];
};bool String::operator==(const String& st) const {
 bool equal=_len==st._len;
 for(int i=0; (i<_len)&&equal; i++)
 equal=*(_allocator+i)==*(st._allocator+i);
 return equal;
};bool String::operator!=(const String& st) const {
 return !(*this==st);
};bool String::operator<(const String& st) const {
 bool res=true;
 int i=0;
 while(res&&(i<_len)&&(i<st._len))
 {
 res=res&&(*(_allocator+i)==*(st._allocator+i)); 
 i++;
 }
 if(res)
	 return _len<st._len; 
	 i--;
 return *(st._allocator+i)<*(_allocator+i);
};bool String::operator<=(const String& st) const {
 if(*this==st)
	return true;
 return st<*this;
};bool String::operator>(const String& st) const {
 bool res=true; 
 int i=0;
 
 while( res && ( i >_len ) && ( i > st._len ) ) 
 {
	res = res && ( *(_allocator+i) == *(st._allocator + i) ); 
	i++;
 }
 if(res) 
	 return _len>st._len; i--;
 return *(_allocator+i) > *(st._allocator+i);
};bool String::operator>=(const String& st) const {
 if(*this==st) return true;
 return *this>st;
};String String::operator+(const String& st) const {
 String chr('.'); 
 size_t len=_len+st._len; 
 String res(chr, len);
 strcpy(res._allocator, _allocator);
 strcpy(res._allocator+_len, st._allocator); 
 return res; 
};String& String::operator+=(const String& st) {
 size_t len=_len+st._len; 
 char* newAllocator=new char[len+1]; 
 strcpy(newAllocator, _allocator); 
 delete [] _allocator;
 _allocator=newAllocator;
 strcpy(_allocator+_len, st._allocator); 
 _len=len; 
 return *this; 
};String& String::operator+=(const char* st) {
 if(st==0) return *this;
 size_t len=strlen(st); 
 char* newAllocator=new char[len+_len+1]; 
 strcpy(newAllocator, _allocator); 
 delete [] _allocator; 
 _allocator=newAllocator; 
 strcpy(_allocator+_len, st); 
 _len+=len; 
 return *this;
};ostream& operator<<(ostream& os, const String& s) {
 for(size_t i=0; i<s.length(); i++)
 {
	 os<<s[i];
 }
 return os;
} 