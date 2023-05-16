#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <iostream>

using namespace  std;
/*!
    \brief Класс записи из CSV
    \author Никита Романов
    \version 1.0
    \date Май 2023 года

    Содержит ФИО, название улицы, номер дома, квартиры, дату рождения. Перегружены операторы сравнения.
    Приоритет сравнения: улица, дом, квартира, фио, рождение.
*/
class Entry {
public:
  Entry();
  Entry(string fio, string street, int home, int flat, int birth);
  Entry(string fio, string street, int home, int flat, int birth, uint64_t hash);

  void addHash(uint64_t hash) {
    this->hash=hash;
  }

  //приоритет сравнения: улица дом квартира фио рождение
  bool operator>(Entry &second);
  bool operator<(Entry &second);
  bool operator>=(Entry &second);
  bool operator<=(Entry &second);

  string fio;
  string street;
  int home;
  int flat;
  int birth;
  uint64_t hash;
};

ostream& operator<<(ostream &out, const Entry &entry);

#endif // ENTRY_H
