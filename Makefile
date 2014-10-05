LIBRARY := libmyojni.so
BASEDIR := .
SRCDIR  := $(BASEDIR)/src/main/cpp/
OBJDIR  := $(BASEDIR)/target/obj/
OUTDIR  := $(BASEDIR)/target/lib/
MYOSDK  := $(BASEDIR)/src/main/resources/myo-sdk/macosx/

CPPFILES := $(wildcard $(SRCDIR)*.cpp)
OBJFILES := $(addprefix $(OBJDIR), $(notdir $(CPPFILES:.cpp=.o)))

INCLUDES := -I/System/Library/Frameworks/JavaVM.framework/Headers -I$(MYOSDK)include
LIBRARIES := -L$(MYOSDK) -lmyo -rpath $(MYOSDK)

CXXFLAGS := $(INCLUDES)

$(LIBRARY): $(OBJFILES)
	mkdir -p $(OBJDIR)
	mkdir -p $(OUTDIR)
	$(CXX) -shared $(LIBRARIES) -v -o $(OUTDIR)$@ $^

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(OUTDIR)/*