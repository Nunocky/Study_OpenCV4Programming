TARGETS = sample02_04

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`

sample02_04: sample02_04.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)


clean:
	$(RM) $(TARGETS) *.o *~

.PHONY: all clean
