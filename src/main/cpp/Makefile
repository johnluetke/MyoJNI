LIBRARY := libmyo-jni.so
OBJFILES := jni_Myo.o
INCLUDES := -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux
CXXFLAGS := $(INCLUDES)

$(LIBRARY): $(OBJFILES)
    $(CXX) -shared -o $@ $^