#include <iostream>
#include <string>
#include <fstream>
#include "IO.hpp"
#include <string>
#include <sstream>

class readEnv
{
  public:
    std::string get_env()
    {
      std::string env_path = ".env";
      IO io(env_path);
      std::fstream f_stream = io.get_file_stream();
      std::stringstream buffer;
      buffer << f_stream.rdbuf();
      std::string content = buffer.str();
      retyrn content; 
     }
};
