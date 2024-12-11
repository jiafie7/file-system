#include "fs/file.h"

using namespace melon::fs;

File::File(const std::string& path)
{
  m_path = path;
}

