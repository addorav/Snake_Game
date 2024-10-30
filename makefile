CC=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic -g

SRCDIR=src
OBJDIR=obj
BINDIR=bin
APPNAME=Snake

RM=rm -f
ifeq ($(OS),Windows_NT)
	RM=del /Q
endif

MD=mkdir -p
ifeq ($(OS),Windows_NT)
	MD=mkdir
endif

all: init SnakeGame

init:
	$(MD) $(OBJDIR) $(BINDIR)

SnakeGame: apple.o board.o direction.o game_engine.o painter.o point.o snake.o main.o
	$(CC) -o $(BINDIR)/$(APPNAME) \
		$(OBJDIR)/apple.o $(OBJDIR)/board.o $(OBJDIR)/direction.o \
		$(OBJDIR)/game_engine.o $(OBJDIR)/painter.o $(OBJDIR)/point.o \
		$(OBJDIR)/snake.o $(OBJDIR)/main.o

apple.o:
	$(CC) $(SRCDIR)/apple.cpp -o $(OBJDIR)/apple.o -c

board.o:
	$(CC) $(SRCDIR)/board.cpp -o $(OBJDIR)/board.o -c

direction.o:
	$(CC) $(SRCDIR)/direction.cpp -o $(OBJDIR)/direction.o -c

game_engine.o:
	$(CC) $(SRCDIR)/game_engine.cpp -o $(OBJDIR)/game_engine.o -c

painter.o:
	$(CC) $(SRCDIR)/painter.cpp -o $(OBJDIR)/painter.o -c

point.o:
	$(CC) $(SRCDIR)/point.cpp -o $(OBJDIR)/point.o -c

snake.o:
	$(CC) $(SRCDIR)/snake.cpp -o $(OBJDIR)/snake.o -c

main.o:
	$(CC) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o -c

clean:
	$(RM) $(OBJDIR)/*.o $(BINDIR)/$(APPNAME)