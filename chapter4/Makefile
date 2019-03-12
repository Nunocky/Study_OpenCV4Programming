TARGETS = flip resize rotate perspective trimming

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`

flip: flip.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

resize: resize.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

rotate: rotate.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

perspective: perspective.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

trimming: trimming.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)


clean:
	$(RM) $(TARGETS) *.o *~ *.jpg

.PHONY: all clean
