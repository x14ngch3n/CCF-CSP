OBJDIR=bin

src=$(wildcard *.cc)
obj=$(patsubst %.cc,%,$(src))

all: $(obj)

.PHONY:clean
clean:
	rm -f $(obj)
