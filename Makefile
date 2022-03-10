SRCDIR = src
OBJDIR = build
CXX = /usr/bin/clang++
CXXFLAG = -Wall -std=c++11 -g

FILES = $(shell ls ${SRCDIR})
OBJS = $(foreach file, $(FILES), $(patsubst %.cc,$(OBJDIR)/%,$(file)))

# method one: Static Pattern Rules
# binary is compiled only when the related source code has changed
all: $(OBJS)

$(OBJS): $(OBJDIR)/%: $(SRCDIR)/%.cc
	$(CXX) $(CXXFLAG) $^ -o $@

# method two
# every time it needs to re-compile all source files while only one source code has changed
# SRCS = $(foreach file, $(FILES), $(addprefix ../src/, $(file)))
# all: $(OBJS)
# $(OBJS): $(SRCS)
# 	$(CXX) $(CXXFLAG) $(patsubst %, ../src/%.cc, $@) -o $@

# method three
# a very ugly Makefile, every time it needs to re-compile all source files when only one source code has changed
# .PHONY: all
# all: 
# 	$(foreach file, $(FILES), $(shell $(CXX) $(addprefix ../src/, $(file)) -o $(patsubst %.cc,%,$(file))))

clean:
	rm -f $(OBJS)

