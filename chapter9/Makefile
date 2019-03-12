TARGETS = detect_corners detect_objects detect_objects_camera eliminate_objects repair_dmg_img match_template akaze

all: $(TARGETS)

CXX=g++
CXXFLAGS= -Wall `pkg-config opencv4 --cflags`
# std=c++11 
OPENCV_LIBS= `pkg-config opencv4 --libs`


detect_corners: detect_corners.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

detect_objects: detect_objects.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

detect_objects_camera: detect_objects_camera.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

eliminate_objects: eliminate_objects.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

repair_dmg_img: repair_dmg_img.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

match_template: match_template.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)

akaze: akaze.o
	$(CXX) -g -o $@ $^ $(OPENCV_LIBS)




clean:
	$(RM) $(TARGETS) *.o *~ corners.jpg dobj.jpg dst.jpg dst_match.jpg

.PHONY: all clean
