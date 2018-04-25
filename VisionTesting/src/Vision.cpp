#include <Vision.h>

Vision::Vision() {

}

void Vision::VisionThread() {
	//Create Camera object
	cs::UsbCamera camera = cs::UsbCamera();

	//Set brightness and exposure-
	camera.SetBrightness(5);
	camera.SetExposureManual(50);

	//Start capturing video
	camera = CameraServer::GetInstance()->StartAutomaticCapture();

	//Set resolution
	camera.SetResolution(320, 240); //use 320, 240 for usb camera so that the roborio does not have to convert the image before sending it

	//takes the video and makes a new output to the smart dashboard(switch to "FindYellow" in the properties of the camera viewer
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
	cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("FindYellow", 320, 240);

	cv::Mat src;
	cv::Mat gray;
	cv::Mat hsv;
	cv::Mat threshOutput;

	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	while(true) {
		cvSink.GrabFrame(src);
//
		if(src.empty()){
		    continue;}
		else if(src.channels()>1){
		    cv::cvtColor(src, hsv, CV_BGR2HSV);}
		else {gray = src;}

//		cv::cvtColor(src, hsv, CV_BGR2HSV);

		//find green from hsv mat-put to threshOutput mat
		cv::inRange(hsv, cv::Scalar(20, 50, 50), cv::Scalar(30, 255, 255), threshOutput);

		//group pixels into contours
		cv::findContours(threshOutput, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

		int contoursFound = 0;

		for(unsigned int i = 0; i < contours.size(); i++) {

			//if the area of the contour is too small, it will not be drawn
			float contourArea = cv::contourArea(contours[i]);
			if(contourArea < 20){
				continue;
			}
			else {
				contoursFound++;
			}
			cv::drawContours(src, contours, i, cv::Scalar(255, 0, 255), 3, 8, hierarchy, 0, cv::Point() );
		}

		if(contoursFound > 0){
			Vision::seeYellow = true;
		}
		else{
			Vision::seeYellow = false;
		}

		outputStreamStd.PutFrame(src);
	}
}

bool Vision::GetSeeYellow() {
	return Vision::seeYellow;
}

bool Vision::seeYellow = false;
