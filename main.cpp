#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include "opencv2/imgproc/imgproc_c.h"

#define N 3

using namespace std;
using namespace cv;

int main()
{	
	
	while(1) {
			
		time_t start,end;
		double alpha = 1.5;
		double beta = -25;
		
		
		VideoCapture capture(0);
		cout << capture.set(CAP_PROP_MODE,CAP_MODE_GRAY);

		if(!capture.isOpened()){
			printf("Capture failure\n");
			return -1;
		}
	
		time(&start);
		int counter=0;
		Mat frame, new_frame;
		//~ vector<Mat> channels;
		
		    	while(1)
			{
				capture >> frame;
				resize(frame,new_frame,Size(),3,8/3);
				
				if(frame.empty()) break;
				
				time(&end);
				++counter;
				double sec=difftime(end,start);
				double fps=counter/sec;
				printf("FPS = %.2f\n\n",fps);
				
				imshow("Raw Image",frame);
				imshow(" Image",new_frame);
				if ( (cvWaitKey(10) & 255) == 27 ) break; 
	      		}
			
		destroyAllWindows();
	}
	return 0;
}
