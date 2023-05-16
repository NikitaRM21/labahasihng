#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "entry.h"
#include "hash_table.h"
#include <random>
#include <map>
#include <chrono>

using namespace std;
/*!
Парсит данные из файла по указанному пути в Массив данных.
\param[data] data Массив данных
\param[path] path Путь до файла
\return Ничего не возвращает
*/
void parseFromFile(vector<Entry> &data, string path) {
  ifstream file(path);
  string line, field;
  //parce from the file into data
  while ( getline(file,line) )    // get next line in file
  {
      stringstream ss(line);
      int i = 0;
      string fio, street;
      int home, flat, birth;
      while (getline(ss,field,','))
      {
          switch (i) {
          case 0:
              fio = field;
              break;
          case 1:
              street = field;
              break;
          case 2:
              home = stoi(field);
              break;
          case 3:
              flat = stoi(field);
              break;
          case 4:
              birth = stoi(field);
              break;
          default:
              break;
          }
          ++i;
      }
      Entry entry(fio,street,home,flat,birth);
      data.push_back(entry);
  }
}

/*!
Парсит данные с файла и заполняет хэш таблицу.
\param[fileName] fileName Имя файла, откуда парсить данные.
\param[hashAlgo] hashAlgo Алгоритм хэширования
\param[name] name Алгоритм хэширования
\return Ничего не возвращает
*/
void handleFile (string fileName, int hashAlgo, const string& name) {
  vector<Entry> data;
  parseFromFile(data, fileName);

  hash_table hTable(hashAlgo);

  for (unsigned i=0; i < data.size(); ++i) {
    hTable.addElement(data[i]);
  }

//  countUinqeHash(data);

  std::cout << "Collisions:" << hTable.countCollisions() << endl;

  auto begin = chrono::steady_clock::now();
  hTable.findElement(name);//внутри можно вывести найденный элемент
  auto end = chrono::steady_clock::now();
  auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
  std::cout << "Search time:" << elapsed_ms.count() << std::endl;
}

int main()
{
  // 1-hashWithPower 2-rot13 3-rs 4-hashWithSum

  std::cout << "bad hash" << std::endl;
  handleFile("tests/test200.txt", 2, "epfmjjjfuj iwpscnwz ivgcbxgdew");
  handleFile("tests/test500.txt", 2, "bjqfwjt adkjkuw sdslowp");
  handleFile("tests/test1000.txt", 2, "zmyfbrykmmz oefene ocdptlga");
  handleFile("tests/test8000.txt", 2, "xhecfl qmoqoniexj pkjxtwto");
  handleFile("tests/test30000.txt", 2, "zgkhaqvgbpk mgctipwo kwliqssiw");
  handleFile("tests/test60000.txt", 2, "cgzdjqlunco aefolav tzvtsmxdh");
  handleFile("tests/test120000.txt", 2,"wfugkjvodle akvnvuw trbaub");
  std::cout << "=============================" << std::endl;
  std::cout << "good hash" << std::endl;
  handleFile("tests/test200.txt", 3, "epfmjjjfuj iwpscnwz ivgcbxgdew");
  handleFile("tests/test500.txt", 3, "bjqfwjt adkjkuw sdslowp");
  handleFile("tests/test1000.txt", 3, "zmyfbrykmmz oefene ocdptlga");
  handleFile("tests/test8000.txt", 3, "xhecfl qmoqoniexj pkjxtwto");
  handleFile("tests/test30000.txt", 3, "zgkhaqvgbpk mgctipwo kwliqssiw");
  handleFile("tests/test60000.txt", 3, "cgzdjqlunco aefolav tzvtsmxdh");
  handleFile("tests/test120000.txt", 3,"wfugkjvodle akvnvuw trbaub");
  std::cout << "Constant time, you see" << std::endl;




  return 0;
}
