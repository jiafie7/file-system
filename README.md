# file-system

This C++ File and Directory Management Library provides a comprehensive API for performing various file and directory operations. It is designed to simplify tasks like file creation, deletion, reading, and directory management with an intuitive interface.

## Features

1. **File Operations**

   - **Path Management**: Get file paths and directories.
   - **File Management**: Create, delete, copy, rename, and check file existence.
   - **Content Operations**: Read from or write to files.
   - **Metadata Retrieval**:
     - File size
     - Number of lines
     - Last modification time

2. **Directory Operations**

   - **Path Management**: Get directory paths and normalize paths.
   - **Directory Management**: Create, delete, rename, clear contents, and check existence.
   - **Content Operations**:
     - Retrieve all files in a directory.
     - Count files in a directory.
     - Get total file sizes and line counts.

3. **Utilities**
   - Normalize paths and handle absolute/relative paths.
   - Cross-platform support for path separators.

## Getting Started

1. Prerequisites

   - C++ 11 or later

2. Clone the Repository

```bash
git clone https://github.com/jiafie7/file-system.git
cd file-system
```

3. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

1. Example code

```c
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

  return 0;
}
```

2. Run the Example

```c
./main
```

3. Output

```bash
/a/b/c/d/file-system/test.txt
/a/b/c/d/file-system
/a/b/c/d/file-system/utility
```

## API Reference

File Class

- Path Operations: `getPath()`, `getDir()`
- File Management: `create()`, `remove()`, `copy()`, `rename()`
- Content Operations: `read()`, `write()`, `clear()`
- Metadata: `exists()`, `size()`, `line()`, `time()`

Directory Class

- Path Operations: `getPath()`
- Directory Management: `create()`, `remove()`, `rename()`, `clear()`
- Content Operations: `file()`, `count()`, `size()`, `line()`
- Static Utilities: `normalizePath()`, `isAbsolutePath()`, `mkdir()`, `rmdir()`

## Contributions

Contributions, bug reports, and feature requests are welcome! Feel free to fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
