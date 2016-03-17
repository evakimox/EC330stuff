#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <string>

class HashTable{
 public:
  HashTable(char* filename);
  SpellCheck(string inputword);
 private:
  int sizedict;
  string dict[];
};

#endif
