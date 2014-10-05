LIBRARY := libmyojni.so
BASEDIR := .
CPPDIR  := $(BASEDIR)/src/main/cpp/
CLSDIR  := $(BASEDIR)/target/classes/
OBJDIR  := $(BASEDIR)/target/obj/
OUTDIR  := $(BASEDIR)/target/lib/
MYOSDK  := $(BASEDIR)/src/main/resources/myo-sdk/macosx/

CPPFILES := $(wildcard $(CPPDIR)*.cpp)
OBJFILES := $(addprefix $(OBJDIR), $(notdir $(CPPFILES:.cpp=.o)))
JNIFILES := $(wildcard $(CLSDIR)myojni/jni/*.class)

INCLUDES := -I/System/Library/Frameworks/JavaVM.framework/Headers -I$(MYOSDK)include
LIBRARIES := -L$(MYOSDK) -lmyo -rpath $(MYOSDK)

CXXFLAGS := $(INCLUDES)

.SILENT:

build: clean init generate-jni-headers $(LIBRARY)

$(LIBRARY): $(OBJFILES)
	echo "   Building native library..."
	$(CXX) -shared $(LIBRARIES) -o $(OUTDIR)$@ $^

init:
	echo "   Creating artifact directories..."
	mkdir -p $(OBJDIR)
	mkdir -p $(OUTDIR)

clean:
	echo "   Cleaning previous artifacts..."
	rm -rf $(OBJDIR)/*
	rm -rf $(OUTDIR)/*

generate-jni-headers:
	echo "   Generating JNI .h files..."
	javah -jni -classpath $(CLSDIR) -d $(CPPDIR) $(subst /,.,$(subst .class,,$(subst $(CLSDIR),,$(JNIFILES))))

$(OBJDIR)%.o: $(CPPDIR)%.cpp
	echo "   Compiling .cpp..."
	$(CXX) $(CXXFLAGS) -c -o $@ $<