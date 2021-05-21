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

# link object files to Executable
$(APP): $(OBJS)
	$(CXX) $(CXXFLANGS) $^ -o $@

# compile source code to object files
obj/%.o: src/%.cpp
	$(CXX) $(CXXFLANGS) -c $^ -o $@

# clean object folder
clean:
	rm -r obj
