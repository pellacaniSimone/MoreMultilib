CXX = gcc
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c17 -g -O0 -lm -fsanitize=address -DSTRICT_WARNINGS
LDFLAGS = -fsanitize=address -DSTRICT_WARNINGS

CFLAGS += -g -fsanitize=address -fno-omit-frame-pointer -Wall -Wextra

SRC = main.c
SRC += basic/var.c basic/files.c basic/variadic.c basic/datetime.c basic/union.c 
SRC += advanced/basic_object.c  advanced/mt_data_race.c
SRC += dp/creational/singleton.c dp/creational/factory.c dp/creational/union_singleton.c

OBJ = $(SRC:.c=.o)

EXEC = program.out

all:  $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(CXXFLAGS)

clean:
	rm -rf $(OBJ) 

cleanall:
	rm -rf $(OBJ) $(EXEC)