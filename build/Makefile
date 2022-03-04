SRCDIR = ../src
CXX = g++

FILES = $(shell ls ${SRCDIR})
OBJS = $(foreach file, $(FILES), $(patsubst %.cc,%,$(file)))
SRCS = $(foreach file, $(FILES), $(addprefix ../src/, $(file)))

.PHONY:all
all: $(OBJS)
	
$(OBJS): $(SRCS)
	$(CXX) $< -o $@

clean:
	rm -f $(OBJS)

# clang ../src/20xxxx-x.cc -o 20xxxx-x
# a very ugly Makefile, every time it needs to re-compile all source files
# all: 
# 	$(foreach file, $(FILES), $(shell $(CXX) $(addprefix ../src/, $(file)) -o $(patsubst %.cc,%,$(file))))

# all: $(foreach file, $(OBJS), $(file))