#include "fs/directory.h"

using namespace melon::fs;

Directory::Directory()
{
  m_path = ".";
}

Directory::Directory(const std::string& path)
{
  m_path = path;
}

std::string Directory::getPath() const
{
  return m_path;
}

char Directory::seperator()
{
#ifdef WIN32
  return '\\';
#else
  return '/';
#endif
}

bool Directory::isAbsolutePath(const std::string& path)
{
  if (path.empty())
    return false;
  char seperator = Directory::seperator();
  std::string filepath = path;

#ifdef WIN32
  std::replace(filepath.begin(), filepath.end(), '/', seperator);
#endif

  std::vector<std::string> output = String::split(filepath, seperator);

#ifdef WIN32
  if (output[0].find(':') != std::string::npos)
#else
  if (output[0].empty())
#endif
    return true;
  else
    return false;
}

std::string Directory::normalizePath(const std::string& path)
{
  // 获取绝对目录
  // 是绝对目录直接返回
  // 不是再添加
  char seperator = Directory::seperator();
  std::string filepath = path;

#ifdef WIN32
  std::replace(filepath.begin(), filepath.end(), '/', seperator);
#endif

  std::vector<std::string> abs_path_list;
  if (!isAbsolutePath(path))
  {
    char abs_path[PATH_MAX] = {0};
    getcwd(abs_path, PATH_MAX);
    abs_path_list = String::split(abs_path, seperator);
  }

  // generate absolute path
  for (const std::string& dir : String::split(filepath, seperator))
  {
    if (dir.empty())
      continue;
    if (dir == ".")
      continue;
    else if (dir == "..")
      abs_path_list.pop_back();
    else
      abs_path_list.push_back(dir);
  } 

  std::string temp = String::join(abs_path_list, seperator);
  return adjustPath(temp);
 }
        
std::string Directory::adjustPath(const std::string& path)
{
  char seperator = Directory::seperator();
  std::string filepath = path;

#ifdef WIN32
  if (filepath[filepath.size() - 1] == ':')
    filepath += seperator;
#else
  if (filepath[0] != seperator)
    filepath = std::string(1, seperator) + filepath;
#endif

  return filepath;
}

