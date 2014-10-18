PROGNAME=quickrdp

CXX = g++
INSTALL = install -o root -g root -m 755
INSTALL_DIR = install -p -d -o root -g root -m 755
INSTALL_DATA = install -p -o root -g root -m 644
CFLAGS += 
CPPFLAGS +=
CXXFLAGS += -g -Wall $(shell wx-config --cxxflags)
LDFLAGS += $(shell wx-config --libs base,core,adv)$(shell curl-config --libs)
SVN_INFO_REV = $(shell svn info | grep Revision | cut -d' ' -f2)
SVN_DEFINE=-DSVN_REVISION=0

ifneq (,$(filter noopt,$(DEB_BUILD_OPTIONS)))
	CXXFLAGS += -O0
else
	CXXFLAGS += -O2
endif
ifeq (,$(filter nostrip,$(DEB_BUILD_OPTIONS)))
	INSTALL += -s
endif
ifneq (,$(filter parallel=%,$(DEB_BUILD_OPTIONS)))
	NUMJOBS = $(patsubst parallel=%,%,$(filter parallel=%,$(DEB_BUILD_OPTIONS)))
	MAKEFLAGS += -j$(NUMJOBS)
endif

ifneq (,$(SVN_INFO_REV))
	SVN_DEFINE=-DSVN_REVISION=$(SVN_INFO_REV)
endif

INCLUDE_DIR=
DEFAULT_DEFINE=-DDATA_PATH=\"$(DESTDIR)/usr/share/$(PROGNAME)/\" 

OBJFILES := $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))

all: $(PROGNAME)

devel: DEFAULT_DEFINE=-DDATA_PATH=\"\"
devel: $(PROGNAME)

$(PROGNAME): $(OBJFILES) 
	$(CXX) -o $(PROGNAME) $(INCLUDE_DIR) $(OBJFILES) $(LDFLAGS)

obj/%.o: src/%.cpp 
	@mkdir -p obj
	$(CXX) -c $< -o $@ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIR) $(DEFAULT_DEFINE) $(SVN_DEFINE)

clean:
	rm -f $(OBJFILES) $(PROGNAME)

rebuild: clean all

install:
	$(INSTALL_DIR) mkdir -p $(DESTDIR)/usr/share/$(PROGNAME)/data
	$(INSTALL_DIR) $(DESTDIR)/usr/bin
	$(INSTALL_DATA) data/*.* $(DESTDIR)/usr/share/$(PROGNAME)/data
	$(INSTALL_DATA) ChangeLog $(DESTDIR)/usr/share/$(PROGNAME)/data
	$(INSTALL) $(PROGNAME) $(DESTDIR)/usr/bin

uninstall:
	rm -rf $(DESTDIR)/usr/share/$(PROGNAME)
	rm -f $(DESTDIR)/usr/bin/$(PROGNAME)

.PHONY: install uninstall

