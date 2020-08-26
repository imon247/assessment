#include "yourString.h"

String::String(){
    if(_str){
        delete[] _str;
        _str = nullptr;
        _len = 0;
    }
}
String::String(const char* s){
    if(s){
        size_t len = strlen(s);
        _str = new char[len+1];
        strcpy(_str, s);
        _str[len] = '\0';
        _len = len;
    }
}

String::String(const String& o){
    if(o._str){
        size_t len = strlen(o._str);
        _str = new char[len+1];
        strcpy(_str, o._str);
        _str[len] = '\0';
        _len = len;
    }
}

String::String(String&& o) noexcept{
    if(_str){
        delete[] _str;
        _str = nullptr;
        _len = 0;
    }
    _str = o._str;
    _len = o._len;
    o._str = nullptr;
    o._len = 0;
}

String::~String(){
    delete[] _str;
    _str = nullptr;
    _len = 0;
}

String& String::operator= (String o){
    std::swap(_str, o._str);
    std::swap(_len, o._len);
    return *this;
}
// String& String::operator= (const String&&){

// }

String& String::operator+=(const String& o){
    if(o._str){
        size_t len = _len + strlen(o._str);
        size_t rhslen = len - _len;
        if(rhslen<1) return *this;
        char *buffer = new char[len+1]();
        memcpy(buffer, _str, _len);
        memcpy(buffer+_len, o._str, rhslen);
        if(_str){
            delete[] _str;
        }
        _str = buffer;
        _len = len;
    }
    return *this;
}

String operator+(const String& lhs, const String& rhs) {
    String s = lhs;
    s += rhs;
    return s;
}

bool String::operator==(const String& o) const{
    if(strcmp(_str, o._str)==0 && _len==o._len) return true;
    else return false;
}

bool String::operator != (const String& o) const{
    if(strcmp(_str, o._str)!=0) return true;
    else return false;
}
bool String::operator > (const String& o) const {
    if(strcmp(_str, o._str)>0) return true;
    return false;
}
bool String::operator < (const String& o) const {
    if(strcmp(_str, o._str)<0) return true;
    return false;
}
bool String::operator >= (const String& o) const {
    if(strcmp(_str, o._str)>=0) return true;
    return false;
}
bool String::operator <= (const String& o) const {
    if(strcmp(_str, o._str)<=0) return true;
    return false;
}

char& String::operator[] (const int i) {
    // if(i<0 || i>=(int)_len) return 0;
    return _str[i];
}

char String::operator[] (const int i) const {
    if(i<0 || i>=(int)_len) return 0;
    return _str[i];
}

String::operator const char* () const {
    return _str;
}

String String::operator()(char * s) const {
    return String(s);
}

String String::operator() (int start, int length) const {
    String substring;
    char * buffer;
    start = start >= 0 ? start : 0;
    size_t len;
    if(start+length>_len) len = _len - start;
    else len = length;
    if(!_str) return substring;

    buffer = new char[len+1]();
    strncpy(buffer, _str + start, len);
    substring = buffer;
    delete[] buffer;
    return substring;
}

const char* String::c_str() const {
    return _str;
}

size_t String::length() const {
    return _len;
}