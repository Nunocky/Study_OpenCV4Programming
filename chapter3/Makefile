TARGETS = circle lines_on_image circles_on_image draw_text

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`

circle: circle.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

lines_on_image: lines_on_image.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

circles_on_image: circles_on_image.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

draw_text: draw_text.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

clean:
	$(RM) $(TARGETS) *.o *~ *.jpg

.PHONY: all clean
