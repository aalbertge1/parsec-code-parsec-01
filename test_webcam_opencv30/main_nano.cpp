
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
		 out = detect_cv(frame);
		 imshow( "Frame", out );
		 c=(char)waitKey(25);
	         if(c==27)
		 break;}
		}
	    else if(c=='e')
	    	{
		 while (1){
		 cap >> frame;
	    	 if (frame.empty())
	      	 break;
		 out = moyenne(frame);
		 imshow( "Frame", out );
		 c=(char)waitKey(25);
	         if(c==27)
		 break;}
		}
	    else if(c=='r')
	    	{
		 while (1){
		 cap >> frame;
	    	 if (frame.empty())
	      	 break;
		 out = glitch(frame);
		 imshow( "Frame", out );
		 c=(char)waitKey(25);
	         if(c==27)
		 break;}
		}
	    else if(c=='t')
	    	{
		 while (1){
		 cap >> frame;
	    	 if (frame.empty())
	      	 break;
		 out = sobel(frame);
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











