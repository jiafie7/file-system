#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#include "fs/file.h"

using namespace melon::fs;

int main()
{
  File f1("./../test.txt");
  std::cout << f1.getPath() << '\n';
  std::cout << f1.getDir() << '\n';

  return 0;
}
