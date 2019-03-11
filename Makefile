TARGETS = create_img read_write

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`

create_img: create_img.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

read_write: read_write.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)


clean:
	$(RM) $(TARGETS) *.o *~

.PHONY: all clean
