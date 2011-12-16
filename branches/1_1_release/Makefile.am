# do not check for files README, TODO, etc
AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = quickRDP
datadir = $(bindir)/data
quickRDP_SOURCES = 	aboutDialog.cpp \
					aboutDialog.h \
					Configuration.h \
					FileParser.h \
					generalTabPanel.cpp \
					generalTabPanel.h \
					quickRDPApp.cpp \
					quickRDPApp.h \
					quickRDPMain.cpp \
					quickRDPMain.h \
					RDPDatabase.cpp \
					RDPDatabase.h \
					RDPFrame.cpp \
					RDPFrame.h \
					resourcesTabPanel.cpp \
					resourcesTabPanel.h \
					windowTabPanel.cpp \
					windowTabPanel.h					
quickRDP_LDADD = @LIBS@
quickRDP_CXXFLAGS = @CXXFLAGS@
