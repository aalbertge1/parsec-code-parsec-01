
#include "mylib.h"
using namespace cv;

std::string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method) {
    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" +
           std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
           std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}


int main(int, char**)

{ 

 int capture_width = 1280 ;
    int capture_height = 720 ;
    int display_width = 1280 ;
    int display_height = 720 ;
    int framerate = 60 ;
    int flip_method = 0 ;

    std::string pipeline = gstreamer_pipeline(capture_width,
	capture_height,
	display_width,
	display_height,
	framerate,
	flip_method);
    std::cout << "Using pipeline: \n\t" << pipeline << "\n";

cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);
	//VideoCapture cap(); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;

	while(1){

	    Mat frame, out;

	    char c=(char)waitKey(25);
	    if(c=='a')
	    	{ 
		 while (1){
		 cap >> frame;
	    	 if (frame.empty())
	      	 break;
		 out = seuillage_cv(frame);
		 imshow( "Frame", out );
		 c =(char)waitKey(25);
	         if(c==27)
		 break;}
		}
	    else if(c=='z')
	    	{
		 while (1){
		 cap >> frame;
	    	 if (frame.empty())
	      	 break;
		 out = bandw_cv(frame);
		 imshow( "Frame", out );
		 c=(char)waitKey(25);
	         if(c==27)
		 break;}
		}
	     else
		{
		 cap >> frame;
	    	 if (frame.empty())
	      	 break;
		 imshow( "Frame", frame);
		}


	    // Press  ESC on keyboard to exit           
	    c=(char)waitKey(25);
	    if(c==27)
	      break;
	  }

	  // When everything done, release the video capture object
	  cap.release();

	  // Closes all the frames
	  destroyAllWindows();

	  return 0;
}


/*	    sobel
	    cvtColor(frame, gray, CV_BGR2GRAY);

	    for (int j=0; j<frame.cols; j++){
	    for (int i=0; i<frame.rows; i++){	
		short gx, gy;
		gx = gray.at<uchar>(i-1, j-1) + 2*gray.at<uchar>(i, j-1) + gray.at<uchar>(i+1, j-1)
		   - gray.at<uchar>(i-1, j+1) - 2*gray.at<uchar>(i, j+1) - gray.at<uchar>(i+1, j+1);
		gy = gray.at<uchar>(i-1, j-1) + 2*gray.at<uchar>(i-1, j) + gray.at<uchar>(i-1, j+1)
		   - gray.at<uchar>(i+1, j-1) - 2*gray.at<uchar>(i+1, j) - gray.at<uchar>(i+1, j+1);

		out = (uchar) abs (gx + gy);
		}}
*/









