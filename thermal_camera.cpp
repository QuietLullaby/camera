#include "thermal_camera.hpp"

using namespace std;
using namespace cv;

thermal_camera::thermal_camera(int thermalCameraID) {
	capture_(thermalCameraID);
	capture_.set(CAP_PROP_MODE,CAP_MODE_GRAY);
	
	if (!capture_.isOpened()){
		cout << "Capture failure\n";
		return -1;
	}
	ID_ = thermalCameraID;
}


void thermal_camera::correctBadPixels();

void thermal_camera::ToneMapping();

void thermal_camera::show(String windowName, Mat frame) {
	capture_ >> frame;
	imshow(windowName, frame);
}

void thermal_image::CreateResizedFrame(Mat dst_frame, int scaleFactorX ,int scaleFactorY) {
	resize(frame_,dst_frame,scaleFactorX,scaleFactorY);
}