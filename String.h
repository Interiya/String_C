//
// Created by Esteno on 20.04.2016.
//

#ifndef STRING_C_STRING_H
#define STRING_C_STRING_H
#include <iostream>
#include <cstring>
using namespace std;

class String{
    struct Representation{
        char *data;
        size_t l;
        int counter;
        Representation(const char *_data);
        Representation(const char *_data, size_t);
        Representation *Copy();
        ~Representation();
    };
    Representation *representation;
    static char *buf;

    struct CharReference{
        String *s;
        size_t i;
        CharReference(String*,size_t);
        CharReference &operator= (char);
        operator char();
    };
public:

    String(const String&);
    String(const char *_data);
    ~String();

    const char *c_str() const;
    void decrease_counter();
    bool operator==(const String&);
    bool operator!=(const String&);
    String operator+(const String&);
    String operator+=(const String&);
    CharReference operator[](size_t);

};


#endif //STRING_C_STRING_H
