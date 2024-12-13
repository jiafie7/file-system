#pragma once

#include <algorithm>
#include <dirent.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>

#include "utility/string.h"
#include "fs/file.h"

using namespace melon::utility;

namespace melon
{
  namespace fs
  {
    class Directory
    {
      public:
        Directory();
        Directory(const std::string& path);
        ~Directory() = default;

        std::string getPath() const;
        bool exists() const;
        bool create() const;
        bool remove() const;
        void clear();
        bool rename(const std::string& path);
        std::vector<File> file() const;
        bool copy(const std::string& path);
        int count() const;
        int line() const;
        long size() const;

      public:
        static char seperator();
        static bool isAbsolutePath(const std::string& path);
        static std::string normalizePath(const std::string& path);
        static std::string adjustPath(const std::string& path);
        // static int mkidr(const char* path);
        // static int rmdir(const char* path);
        // static int unlink(const char* path);
        // static char* getcwd(char* buf, int len);

      private:
        std::string m_path;
    };
  }
}
