TARGETS = bitwise_not blur median_blur gaussian_blur laplacian sobel canny dilate erode box_filter mozaic

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`


bitwise_not: bitwise_not.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

blur: blur.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

median_blur: median_blur.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

gaussian_blur: gaussian_blur.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

laplacian: laplacian.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

sobel: sobel.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

canny: canny.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

dilate: dilate.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

erode: erode.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

box_filter: box_filter.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

mozaic: mozaic.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)



clean:
	$(RM) $(TARGETS) *.o *~ *.jpg

.PHONY: all clean
