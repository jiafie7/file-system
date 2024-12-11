#include "fs/file.h"

using namespace melon::fs;

File::File(const std::string& path)
{
  m_path = path;
}
       
std::string File::getPath() const
{
  return m_path;
}

std::string File::getDir() const
{
  if (m_path.empty())
    return "";
  char seperator = '/';
  std::size_t pos = m_path.find_last_of(seperator);
  if (pos == std::string::npos)
    return "";
  return m_path.substr(0, pos);
}

bool File::create()
{
  if (exists())
    return false;
  
  // to check directory exist

  std::ofstream ofs(m_path);
  return ofs.is_open();
}

bool File::remove()
{

  return true;
}

bool File::copy(const std::string& path)
{

  return true;
}

bool File::rename(const std::string& path)
{

  return true;
}

bool File::exists() const
{
  std::ifstream ifs(m_path);
  return ifs.good();
}

void File::clear()
{

}

int File::line() const
{
  return 0;
}

long File::size() const
{
  return 0;
}

time_t File::time() const
{
  struct stat info = {0};
  if (stat(m_path.c_str(), &info) != 0)
  {
    std::cerr << "Stat file error: " << m_path << '\n';
    return 0;
  }
  return info.st_mtime;
}

std::string File::read() const
{
  return "";
}

bool File::write(const std::string& data) const
{
  return true;
}


