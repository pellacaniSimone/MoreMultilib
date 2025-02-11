CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -O0  -fsanitize=address -DSTRICT_WARNINGS
LDFLAGS = -fsanitize=address -DSTRICT_WARNINGS

SRC = main.cpp
SRC += basic/var.cpp basic/files.cpp 
SRC += basic/variadic.cpp basic/datetime.cpp basic/union.cpp
SRC += advanced/basic_namespace.cpp  advanced/basic_object.cpp advanced/object_namespace.cpp advanced/multiple_inheritance.cpp 
SRC += advanced/template_class.cpp advanced/template_inheritance.cpp advanced/mro.cpp
SRC += dp/creational/union_singleton.cpp dp/creational/factory.cpp 

OBJ = $(SRC:.cpp=.o)

EXEC = program.out

all:  $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(CXXFLAGS)


clean:
	rm -rf $(OBJ) 

cleanall:
	rm -rf $(OBJ) $(EXEC)
