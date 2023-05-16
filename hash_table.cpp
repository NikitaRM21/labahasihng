#include "hash_table.h"
#include <chrono>
#include <set>

/*!
Выбирает функцию для хэширования по объекту в зависимости от используемого алгоритма.
1-hashWithPower 2-rot13 3-rs 4-hashWithSum
\param[object] object Объект
\return хэш
*/
uint64_t hash_table::curHash(const Entry &object) const {
  if (algo == 1) return simpleHash(object.fio);
  else if (algo==2) return hardHash(object.fio);
  else if (algo==3) return hardHash2(object.fio);
  else if (algo==4) return verySimpleHash(object.fio);
  else return -1;
}

/*!
Выбирает функцию для хэширования по имени элемента в зависимости от используемого алгоритма.
1-hashWithPower 2-rot13 3-rs 4-hashWithSum
\param[name] name Имя элемента
\return хэш
*/
uint64_t hash_table::curHash(const string &name) const {
  if (algo == 1) return simpleHash(name);
  else if (algo==2) return hardHash(name);
  else if (algo==3) return hardHash2(name);
  else if (algo==4) return verySimpleHash(name);
  else return -1;
}

/*!
Считает кол-во уникальных хэшей, выводит их кол-во в треминал
\param[vec] vec Массив данных
\return Ничего не возвращает
*/
void countUinqeHash(const vector<Entry> &vec) {
  set<uint64_t> myset;
  for (const auto i: vec) {
    myset.insert(hardHash2(i.fio));
  }
  std::cout << myset.size() << std::endl;
}

/*!
Добавляет элемент в таблицу
\param[object] object Массив данных
\return Ничего не возвращает
*/
void hash_table::addElement(const Entry &object) {
  data.insert(pair<uint64_t, Entry>(curHash(object), object));
}

/*!
Ищет элемент в таблице по указанному имени и выводит его параметры в терминал
\param[name] name Имя элемента
\return Ничего не возвращает
*/
void hash_table::findElement(const string &name) const {
  //first - lower bound, second - upper bounds
  pair<multimap<uint64_t, Entry>::const_iterator, multimap<uint64_t, Entry>::const_iterator> p1;
  p1 = data.equal_range( curHash(name) );
  while (p1.first!=p1.second) {
    if (p1.first->second.fio == name) std::cout << p1.first->second.fio << std::endl;
    p1.first++;
  }
}

/*!
Подсчитывает количество коллизий в таблице
\return Количество коллизий
*/
int hash_table::countCollisions() const {
  auto p0 = data.begin();
  set<uint64_t> myset;
  while (p0!= data.end()) {
    myset.insert(p0->first);
    ++p0;
  }
  return data.size()-myset.size();
}

// out of class functions
/*!
Функция простого хэширования
\return хэш
*/
uint64_t simpleHash(const string &s) {
  uint64_t hash = 0;
  uint64_t power = 1;

  for (unsigned i = 0; i<s.size(); ++i) {
    hash +=  (s[i]-'a'+1) * power;
    power *= magicNumber;
  }

  return hash;
}

/*!
Функция сложного хэширования
\return хэш
*/
uint64_t hardHash(const string &s) {
  uint64_t hash = 0;

  for (unsigned i = 0; i<s.size(); ++i) {
    hash += s[i];
    hash -= (hash << 13) | (hash >> 19);
  }

  return hash;
}

/*!
Функция сложного хэширования №2
\return хэш
*/
uint64_t hardHash2(const string &s) {
  unsigned int b = 378551;
  unsigned int a = 63689;
  unsigned int hash = 0;
  unsigned int i = 0;

  for (i = 0; i < s.size(); i++) {
    int number = s[i];
    hash = hash * a + number;
    a = a * b;
  }
  return hash;
}

/*!
Функция очень простого хэширования
\return хэш
*/
uint64_t verySimpleHash(const string &s) {
  uint64_t hash = 0;

  for (unsigned i = 0; i<s.size(); ++i) {
    hash +=  (s[i]-'a'+1);
  }

  return hash;
}
