include $(ROOTSYS)/etc/Makefile.arch

HEADERS = TFLcut.h TFWcut.h
SOURCES = TFLcut.C TFWcut.C
OBJECTS = TFLcut.o TFWcut.o

all: libTFcutLib.so

TFcutDict.cxx: $(HEADERS) Linkdef.h
	rootcint -f $@ -c $(CXXFLAGS) -p $^

libTFcutLib.so: TFcutDict.cxx $(OBJECTS)
	$(CXX) -shared -o$@ `root-config --ldflags` $(CXXFLAGS) -I$(ROOTSYS)/include `root-config --libs` $^

clean:
	rm *.so *.d *.pcm *.o rm *Dict*

