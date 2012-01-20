ifndef CFG
CFG=release
endif

PROGNAME=quickrdp

WARNING= -Wno-long-long -Wall -Wextra -pedantic

LIBS=

ifeq "$(CFG)" "debug"
CFLAGS=-g -s -c $(WARNING)
CFLAGS_NO_WARNINGS=-g -s -c 
#-fvisibility=hidden
LDFLAGS=-g -s $(WARNING) 
endif
ifeq "$(CFG)" "release"
CFLAGS=-O3 -c $(WARNING) -DNDEBUG 
CFLAGS_NO_WARNINGS=-O3 -c 
#-fvisibility=hidden
LDFLAGS=-O3 $(WARNING) 
endif

CFLAGS := $(shell wx-config --cxxflags)
LIBS := $(shell wx-config --libs)

INCLUDE_DIR=
DEFAULT_DEFINE=-DDATA_PATH=\"$(DESTDIR)/usr/share/$(PROGNAME)/\" 


OBJFILES := $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))

all: $(PROGNAME) $(TOOLS)

devel: DEFAULT_DEFINE=-DDATA_PATH=\"\"
devel: $(PROGNAME) $(TOOLS) 

$(PROGNAME): $(OBJFILES) 
	@echo Linking $(PROGNAME)
	$(CXX) -o $(PROGNAME) $(INCLUDE_DIR) $(OBJFILES) $(LIBS)

obj/%.o: src/%.cpp 
	@mkdir -p obj
	@echo Compiling $<
	@$(CXX) -c $< -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_DIR) $(DEFAULT_DEFINE)

clean:
#       @echo Deleting some files...
	rm -f $(OBJFILES) $(PROGNAME)

rebuild: clean all

install:
	echo $(DEFAULT_DEFINE)
	test -d $(DESTDIR)/usr/share/$(PROGNAME)/data || mkdir -p $(DESTDIR)/usr/share/$(PROGNAME)/data
	test -d $(DESTDIR)/usr/bin || mkdir -p $(DESTDIR)/usr/bin
	install -m 0755 $(PROGNAME) $(DESTDIR)/usr/bin
	install -m 0644 data/*.* $(DESTDIR)/usr/share/$(PROGNAME)/data

uninstall:
	rm -rf $(DESTDIR)/usr/share/$(PROGNAME)
	rm -f $(DESTDIR)/usr/bin/$(PROGNAME)

.PHONY: install uninstall

