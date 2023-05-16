#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include "entry.h"
#include <iostream>
#include <map>

const int magicNumber = 31;
/*!
    \brief Класс, содержащий хэш таблицу
    \author Никита Романов
    \version 1.0
    \date Май 2023 года

    Содержит саму хэш таблицу из пар хэш и хранимый элемент, а также используемый алгоритм и число коллизий.
    Присутствуют следующий методы: добавление элемента, подсчёт коллизий, поиск элемена, вычисление хэша по объекту,
    вычисление хэша по имени.
*/
class hash_table
{
public:
  hash_table() {}
  hash_table(const int a): algo(a) {}
  void addElement(const Entry &object);
  int countCollisions() const;
  void findElement(const string &name) const;
  uint64_t curHash(const Entry &object) const;
  uint64_t curHash(const string &name) const;

private:
  multimap<uint64_t, Entry> data;
  int algo = 0;
  int collisions = 0;
};
void countUinqeHash(const vector<Entry> &vec);
uint64_t simpleHash(const string &s);
uint64_t hardHash(const string &s);
uint64_t hardHash2(const string &s);
uint64_t verySimpleHash(const string &s);


#endif // HASH_TABLE_H
