ifndef CFG
CFG=debug
endif

PROGNAME=QuickRDP

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

INCLUDE_DIR=-I/usr/include/wx 
DEFAULT_DEFINE=-DDATA_PATH=\"$(prefix)/usr/share/$(PROGNAME)/\" 


OBJFILES := $(patsubst %.cpp,obj/%.o,$(wildcard *.cpp))

all: $(PROGNAME) $(TOOLS)

devel: DEFAULT_DEFINE=-DDATA_PATH=\"\"
devel: $(PROGNAME) $(TOOLS) 

$(PROGNAME): $(OBJFILES) 
	@echo Linking $(PROGNAME)
	$(CXX) -o $(PROGNAME) $(INCLUDE_DIR) $(OBJFILES) $(LIBS)

obj/%.o: %.cpp 
	@mkdir -p obj
	@echo Compiling $<
	@$(CXX) -c $< -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_DIR) $(DEFAULT_DEFINE)

clean:
#       @echo Deleting some files...
	rm -f $(OBJFILES) $(PROGNAME)

rebuild: clean all

install:
	echo $(DEFAULT_DEFINE)
	test -d $(prefix)/usr/share/$(PROGNAME)/data || mkdir -p $(prefix)/usr/share/$(PROGNAME)/data
	test -d $(prefix)/usr/bin || mkdir -p $(prefix)/usr/bin
	install -m 0755 $(PROGNAME) $(prefix)/usr/bin
	install -m 0644 data/*.* $(prefix)/usr/share/$(PROGNAME)/data

uninstall:
	rm -rf $(prefix)/usr/share/$(PROGNAME)
	rm -f $(prefix)/usr/bin/$(PROGNAME)

.PHONY: install uninstall

