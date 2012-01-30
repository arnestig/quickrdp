ifndef CFG
CFG=release
endif

PROGNAME=quickrdp

CXX = g++
LDFLAGS =
INSTALL = install -o root -g root -m 755
INSTALL_DIR = install -p -d -o root -g root -m 755
INSTALL_DATA = install -p -o root -g root -m 644
CFLAGS = -g -Wall $(shell wx-config --cxxflags)
LIBS = $(shell wx-config --libs)

ifneq (,$(filter noopt,$(DEB_BUILD_OPTIONS)))
	CFLAGS += -O0
else
	CFLAGS += -O2
endif
ifeq (,$(filter nostrip,$(DEB_BUILD_OPTIONS)))
	INSTALL += -s
endif
ifneq (,$(filter parallel=%,$(DEB_BUILD_OPTIONS)))
	NUMJOBS = $(patsubst parallel=%,%,$(filter parallel=%,$(DEB_BUILD_OPTIONS)))
	MAKEFLAGS += -j$(NUMJOBS)
endif

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
	$(INSTALL_DIR) mkdir -p $(DESTDIR)/usr/share/$(PROGNAME)/data
	$(INSTALL_DIR) $(DESTDIR)/usr/bin
	$(INSTALL_DATA) data/*.* $(DESTDIR)/usr/share/$(PROGNAME)/data
	$(INSTALL) $(PROGNAME) $(DESTDIR)/usr/bin

uninstall:
	rm -rf $(DESTDIR)/usr/share/$(PROGNAME)
	rm -f $(DESTDIR)/usr/bin/$(PROGNAME)

.PHONY: install uninstall

