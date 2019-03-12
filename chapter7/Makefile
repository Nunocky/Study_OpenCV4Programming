TARGETS = add add_scalar add_mask add_roi add_weight_table absdiff blend or

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`


add: add.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

add_scalar: add_scalar.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

add_mask: add_mask.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

add_roi: add_roi.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

add_weight_table: add_weight_table.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

absdiff: absdiff.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

blend: blend.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

or: or.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)


clean:
	$(RM) $(TARGETS) *.o *~ *.jpg

.PHONY: all clean
