SRCDIR = src
OBJDIR = build
CXX = g++
CXXFLAG = -Wall

FILES = $(shell ls ${SRCDIR})
OBJS = $(foreach file, $(FILES), $(patsubst %.cc,%,$(file)))

# method one: Static Pattern Rules
# binary is compiled only when the related source code has changed
all: $(OBJS)

$(OBJS): % : $(SRCDIR)/%.cc
	$(CXX) $(CXXFLAG) $^ -o $(OBJDIR)/$@

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

