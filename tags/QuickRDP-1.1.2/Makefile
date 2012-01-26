ifndef CFG
CFG=release
endif

PROGNAME=quickrdp

CXX = g++
LDFLAGS =
INSTALL = install -s
CFLAGS = -O2 -g -Wall $(shell wx-config --cxxflags)
LIBS = $(shell wx-config --libs)

INCLUDE_DIR=
DEFAULT_DEFINE=-DDATA_PATH=\"$(DESTDIR)/usr/share/$(PROGNAME)/\" 


OBJFILES := $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))

all: $(PROGNAME) $(TOOLS)

devel: DEFAULT_DEFINE=-DDATA_PATH=\"\"
devel: $(PROGNAME) $(TOOLS) 

$(PROGNAME): $(OBJFILES) 
	$(CXX) -o $(PROGNAME) $(INCLUDE_DIR) $(OBJFILES) $(LIBS)

obj/%.o: src/%.cpp 
	@mkdir -p obj
	$(CXX) -c $< -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_DIR) $(DEFAULT_DEFINE)

clean:
	rm -f $(OBJFILES) $(PROGNAME)

rebuild: clean all

install:
	test -d $(DESTDIR)/usr/share/$(PROGNAME)/data || mkdir -p $(DESTDIR)/usr/share/$(PROGNAME)/data
	test -d $(DESTDIR)/usr/bin || mkdir -p $(DESTDIR)/usr/bin
	$(INSTALL) -m 0755 $(PROGNAME) $(DESTDIR)/usr/bin
	$(INSTALL) -m 0644 data/*.* $(DESTDIR)/usr/share/$(PROGNAME)/data

uninstall:
	rm -rf $(DESTDIR)/usr/share/$(PROGNAME)
	rm -f $(DESTDIR)/usr/bin/$(PROGNAME)

.PHONY: install uninstall

