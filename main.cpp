#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#include "fs/file.h"
#include "fs/directory.h"

using namespace melon::fs;

int main()
{
  File f1("./../test.txt");
  std::cout << f1.getPath() << '\n';
  std::cout << f1.getDir() << '\n';

  Directory dir1("./../utility");
  std::cout << dir1.getPath() << '\n';

  std::cout << Directory::normalizePath("/root/usr/../utility") << '\n';


  return 0;
}
