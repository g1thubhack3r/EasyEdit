CC := g++
CPPFLAGS := -std=c++11 $(OPTFLAGS)
PREFIX ?= /usr/local

all: build EasyEdit

build:
	@mkdir -p bin
  
EasyEdit:
	$(CC) $(CPPFLAGS) src/EasyEdit.cpp -o bin/EasyEdit

install: all
	install -d $(DISTDIR)/$(PREFIX)/bin/
	install bin/EasyEdit $(DISTDIR)/$(PREFIX)/bin/

clean:
	rm -rf bin
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`
