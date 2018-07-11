#ifndef THERMAL_CAMERA_HPP
#define THERMAL_CAMERA_HPP 1

using namespace std;
using namespace cv;

class thermal_camera {
	
	
	public :
		
	thermalCamera(int thermalCameraID);
	Mat getActualFrame() {return frame_;}
	void correctBadPixels();
	void ToneMapping();
	void show(String windowName);
	void CreateResizedFrame(Mat dst_frame, int scaleFactorX ,int scaleFactorY);
	
	private:
		
	int ID_;
	VideoCapture capture_;
	Mat frame_;

}


#endif