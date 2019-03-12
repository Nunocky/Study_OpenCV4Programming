TARGETS = grayscale grayscale2 equalize threshold adaptive_threshold split

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`

grayscale: grayscale.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

grayscale2: grayscale2.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

equalize: equalize.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

threshold: threshold.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

adaptive_threshold: adaptive_threshold.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

split: split.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)


clean:
	$(RM) $(TARGETS) *.o *~ *.jpg

.PHONY: all clean
