//
// Created by Esteno on 20.04.2016.
//

#include "String.h"

String::Representation::Representation(const char *_data){
    l = strlen(_data);
    data = new char[l];
    strcpy(data,_data);
    counter = 1;
}

String::Representation::Representation(const char *_data, size_t _l) {
    l = _l;
    data = new char[l];
    strncpy(data,_data,l);
    counter = 1;
}

Representation *String::Representation::Copy() {
    if (counter == 1) return this;
    counter--;
    return new Representation(data,l);
}

String::Representation::~Representation() {
    delete[] data;
}

char *String::buf = 0;

String::CharReference::CharReference(String *string1, size_t _i):
        s(string1),i(_i){}

String::CharReference &String::CharReference::operator=(char c) {
    s->representation = s->representation->Copy();
    s->representation->data[i] = c;
    return *this;
}

String::CharReference::operator char() {
    return s->representation->data[i];
}

String::String(const String &a){
    a.representation->counter ++;
    representation = a.representation;
}

String::String(const char *_data){
    representation = new Representation(_data);
};

String::~String(){
    decrease_counter();
}

const char* String::c_str() const{
    if (buf) delete[] buf;
    buf = new char[representation->l + 1];
    strcpy(buf, representation->data);
    buf[representation->l] = '\0';
    return buf;
}

void String::decrease_counter(){
    representation->counter --;
    if (representation->counter == 0){
        delete representation;
    }
}

bool String::operator==(const String &a) {
    if (representation->l == a.representation->l){
        for (int i = 0; i < representation->l; ++i) {
            if (representation->data[i] != a.representation->data[i])
                return false;
        }
        return true;
    } else return true;
}

String::CharReference String::operator[](size_t _i) {
    //проверить выход за границу
    return CharReference(this,_i);
}

