# Variables
##########
CXX = clang++
CXXFLANGS = -Wall -g

APP = Archery

SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, obj/%.o, $(SRCS))

# Rules
##########
all: obj $(APP)

# create object folder
obj:
	mkdir obj

# compile source code to object files
$(APP): $(OBJS)
	$(CXX) $(CXXFLANGS) $^ -o $@

# link object files to Executable
obj/%.o: src/%.cpp
	$(CXX) $(CXXFLANGS) -c $^ -o $@

# clean object folder
clean:
	rm -r obj
