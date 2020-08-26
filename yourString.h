#ifndef MY_STRING_H
#define MY_STRING_H
#include <stdlib.h>
#include <cstring>
#include <memory>

class String{
    char* _str = nullptr;
    size_t _len = 0;
public:
    String();
    String(const char*);
    String(const String&);
    String(String &&) noexcept;
    ~String();

    // String& operator= (const String&);
    // String& operator= (const String&&);
    String& operator= (String o);
    String& operator+=(const String&);
    friend String operator+(const String&, const String&);

    bool operator==(const String&) const;
    bool operator != (const String &) const;
    bool operator > (const String &) const;
    bool operator < (const String &) const;
    bool operator >= (const String &) const;
    bool operator <= (const String &) const;

    char operator[] (const int) const;          // subscript operator
    char& operator[] (const int);
    operator const char* () const;              // conversion operator
    String operator()(char *) const;            // type casting operator

    String operator() (int, int) const;

    const char* c_str() const;
};
String operator+(const String&, const String&);
#endif