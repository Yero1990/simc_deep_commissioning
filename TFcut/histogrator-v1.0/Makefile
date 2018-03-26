#***************************************************************************
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
#***************************************************************************/

#
# start configure
#

PREFIX        = ./
INCDIR        = $(PREFIX)/include
LIBDIR        = $(PREFIX)/lib
MACRODIR      = $(PREFIX)/macros

#
# end configure
#

ARCH          = $(shell root-config --arch)

CXX           =
ObjSuf        = o
SrcSuf        = cxx
ExeSuf        =
DllSuf        = so
OutPutOpt     = -o # keep whitespace after "-o"

ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTGLIBS    := $(shell root-config --glibs)

ifeq ($(ARCH),linux)
# Linux with egcs, gcc 2.9x, gcc 3.x (>= RedHat 5.2)
CXX           = g++
CXXFLAGS      = -O -Wall -fPIC
LD            = g++
LDFLAGS       = -O
SOFLAGS       = -shared
endif

ifeq ($(ARCH),macosx)
# MacOS X with cc (GNU cc 2.95.2)
CXX           = c++
CXXFLAGS      = -O -pipe -Wall
LD            = c++
LDFLAGS       = -O -Xlinker -bind_at_load -flat_namespace
# The SOFLAGS will be used to create the .dylib; the .so will
# be created separately
DllSuf        = dylib
SOFLAGS       = -dynamiclib -flat_namespace -undefined suppress
endif

ifeq ($(CXX),)
$(error $(ARCH) invalid architecture)
endif

CXXFLAGS     += $(ROOTCFLAGS) -Wno-deprecated
LIBS          = $(ROOTLIBS) $(SYSLIBS)
GLIBS         = $(ROOTGLIBS) $(SYSLIBS)

#------------------------------------------------------------------------------
.PHONY      = clean distclean distclean ci install uninstall

HDRS        = THistograteUtil.h grootutil.h THistList.h THistogrator.h THistogrator1.h THistogrator2.h
SRCS        = THistograteUtil.C grootutil.C THistList.C THistogrator.C THistogrator1.C THistogrator2.C
OBJS        = THistograteUtil.o grootutil.o THistList.o THistogrator.o THistogrator1.o THistogrator2.o

PROGRAM     = libHistogrator.so

DICTHDRS        = THistograteUtilDict.h grootutilDict.h THistListDict.h THistogratorDict.h THistogrator1Dict.h THistogrator2Dict.h
DICTSRCS        = THistograteUtilDict.C grootutilDict.C THistListDict.C THistogratorDict.C THistogrator1Dict.C THistogrator2Dict.C
DICTOBJS        = THistograteUtilDict.o grootutilDict.o THistListDict.o THistogratorDict.o THistogrator1Dict.o THistogrator2Dict.o

all:    $(PROGRAM)

$(PROGRAM): $(OBJS) $(DICTOBJS)
	@echo "Linking $(PROGRAM)"
	@/bin/rm -f $(PROGRAM)
#	ifeq ($(ARCH),macosx)
#	$(LD)  $(SOFLAGS) $(OBJS) $(DICTOBJS) $(GLIBS)-o $(subst .so,.dylib,$@)
#	$(LD) -bundle $(LDFLAGS) $(OBJS) $(DICTOBJS) $(GLIBS)-o $(PROGRAM) 
#	@chmod 555 $(PROGRAM)
#	@echo "done"
#	else
	$(LD) $(SOFLAGS) $(LDFLAGS) $(OBJS) $(DICTOBJS) $(GLIBS)-o $(PROGRAM) 
	@chmod 555 $(PROGRAM)
	@echo "done"
#	endif	

install:
	@cp -iv $(PROGRAM) $(LIBDIR)/
#	@cp -iv $(HDRS) $(INCDIR)/
	@cp -iv scripts/Histograte.C $(MACRODIR)/

uninstall:
	@(cd $(LIBDIR) && rm -vf $(PROGRAM))
#	@(cd $(INCDIR) && rm -vf $(HDRS))
	@(cd $(MACRODIR) && rm -vf Histograte.C)

ci:
	@(ci -l $(HDRS))
	@(ci -l $(SRCS))
	@(ci -l Makefile)
	@(ci -l *LinkDef*)
	@(ci -l README INSTALL COPYING AUTHORS)

clean:
	@/bin/rm -f $(OBJS) $(DICTOBJS) $(DICTSRCS) $(DICTHDRS) G_* *.o core

distclean:	clean
	@/bin/rm -f $(PROGRAM) *.so

dist: clean
	@tar czf $(DISTNAME)-v$(VERSION).tar.gz .
	@mv $(DISTNAME)-v$(VERSION).tar.gz dist/

###

THistograteUtil.o: THistograteUtil.h

THistograteUtilDict.C: THistograteUtil.h
	@echo "Generating dictionary $@"
	@/bin/rm -f $@
	@rootcint $@ -c $^
	@echo "done"

grootutil.o: grootutil.h

grootutilDict.C: grootutil.h grootutilLinkDef.h
	@echo "Generating dictionary $@"
	@/bin/rm -f $@
	@rootcint $@ -c $^
	@echo "done"

THistList.o: THistList.h

THistListDict.C: THistList.h
	@echo "Generating dictionary $@"
	@/bin/rm -f $@
	@rootcint $@ -c $^
	@echo "done"

THistogrator.o: THistogrator.h

THistogratorDict.C: THistogrator.h
	@echo "Generating dictionary $@"
	@/bin/rm -f $@
	@rootcint $@ -c $^
	@echo "done"

THistogrator1.o: THistogrator1.h

THistogrator1Dict.C: THistogrator1.h
	@echo "Generating dictionary $@"
	@/bin/rm -f $@
	@rootcint $@ -c $^
	@echo "done"

THistogrator2.o: THistogrator2.h

THistogrator2Dict.C: THistogrator2.h
	@echo "Generating dictionary $@"
	@/bin/rm -f $@
	@rootcint $@ -c $^
	@echo "done"
