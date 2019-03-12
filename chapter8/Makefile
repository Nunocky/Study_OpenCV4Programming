TARGETS = get_frame_size capture_basic capture_grayscale capture_equlize capture_canny shuffle rotate rotate_part

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`


get_frame_size: get_frame_size.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

capture_basic: capture_basic.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

capture_grayscale: capture_grayscale.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

capture_equlize: capture_equlize.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

capture_canny: capture_canny.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

shuffle: shuffle.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

rotate: rotate.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

rotate_part: rotate_part.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)



clean:
	$(RM) $(TARGETS) *.o *~ *.jpg

.PHONY: all clean
