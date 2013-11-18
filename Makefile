CC=g++

SRCDIR = src
BINDIR = bin

#SOURCES = $(shell find $(SRCDIR) -name '*.cpp') #Old find that returns everything in src directory
SOURCES = $(shell find $(SRCDIR) -type f \( -iname '*.cpp' ! -iname 'Main.cpp' ! -iname 'Test.cpp' \)  )
_OBJS = $(patsubst %.cpp,%.o,$(SOURCES))
OBJS = $(patsubst $(SRCDIR)/%,$(BINDIR)/%,$(_OBJS))

all: $(OBJS) $(BINDIR)/Main.o
	$(CC) $^ -o $(BINDIR)/c4

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p bin
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

run:
	$(BINDIR)/c4