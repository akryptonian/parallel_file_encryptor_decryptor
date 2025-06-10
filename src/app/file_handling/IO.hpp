#ifndef IO_HPP
#define IO_HPP

#include <fstream>
#include <string>
#include <iostream>

class IO
{
  public:
    IO(const std::string &file_path);
    ~IO();
    std::fstream get_file_stream();

  private:
    std::fstream file_stream;
};

#endif
