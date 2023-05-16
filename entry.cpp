#include "entry.h"

using namespace std;

Entry::Entry() {
  this->street="-";
  this->fio="-";
  this->home=0;
  this->flat=0;
  this->birth=0;
}

Entry::Entry(string fio, string street, int home, int flat, int birth) {
  this->street=street;
  this->fio=fio;
  this->home=home;
  this->flat=flat;
  this->birth=birth;
}

Entry::Entry(string fio, string street, int home, int flat, int birth, uint64_t hash){
  this->street=street;
  this->fio=fio;
  this->home=home;
  this->flat=flat;
  this->birth=birth;
  this->hash=hash;
}

bool Entry::operator>(Entry &second) {
    if (this->fio!=second.fio) {
        return this->fio > second.fio;

    } else if(this->street!=second.street) {
        return this->street > second.street;

    } else if(this->home!=second.home) {
        return this->home > second.home;

    } else if(this->flat!=second.flat) {
        return this->flat > second.flat;

    } else {
        return this->birth > second.birth;
    }
}

bool Entry::operator<(Entry &second) {
    if (this->fio!=second.fio) {
        return this->fio < second.fio;
    } else if(this->street!=second.street) {
        return this->street < second.street;

    } else if(this->home!=second.home) {
        return this->home < second.home;

    } else if(this->flat!=second.flat) {
        return this->flat < second.flat;
    } else {
        return this->birth < second.birth;
    }
}

bool Entry::operator>=(Entry &second) {
    if (this->fio!=second.fio) {
        return this->fio >= second.fio;

    } else if(this->street!=second.street) {
        return this->street >= second.street;

    } else if(this->home!=second.home) {
        return this->home >= second.home;

    } else if(this->flat!=second.flat) {
        return this->flat >= second.flat;
    } else {
        return this->birth >= second.birth;
    }
}

bool Entry::operator<=(Entry &second) {
    if (this->fio!=second.fio) {
        return this->fio <= second.fio;

    } else if(this->street!=second.street) {
        return this->street <= second.street;

    } else if(this->home!=second.home) {
        return this->home <= second.home;

    } else if(this->flat!=second.flat) {
        return this->flat <= second.flat;
    } else {
        return this->birth <= second.birth;
    }
}

ostream& operator<<(ostream &out, const Entry &entry) {
    return out << entry.fio << "," << entry.street << "," << entry.home << "," << entry.flat << "," << entry.birth << std::endl;
}
