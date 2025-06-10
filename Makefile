CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -I. -Isrc/app/encrypt_decrypt -Isrc/app/file_handling -Isrc/app/processes

MAIN_TARGET = encrypt_decrypt
CRYPTION_TARGET = cryption

MAIN_SRC = main.cpp\
					 src/app/processes/process_management.cpp\
					 src/app/file_handling/IO.cpp\
					 src/app/file_handling/read_env.cpp\
					 src/app/encrypt_decrypt/cryption.cpp\

CRYPTION_SRC = src/app/encrypt_decrypt/cryption_main.cpp\
							 src/app/encrypt_decrypt/cryption.cpp\
							 src/app/file_handling/IO.cpp\
							 src/app/file_handling/read_env.cpp

MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
CRYPTION_OBJ = $(CRYPTION_SRC:.cpp=.o)

all: $(MAIN_TARGET) $(CRYPTION_TARGET)

$(MAIN_TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(CRYPTION_TARGET): $(CRYPTION_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(CRYPTION_OBJ) $(MAIN_TARGET) $(CRYPTION_TARGET)


.PHONY: clean all
