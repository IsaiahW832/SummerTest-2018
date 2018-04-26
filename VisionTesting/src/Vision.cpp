#include <Vision.h>

Vision::Vision() {
	//Set up PID loop input range
    visionControl->SetInputRange(-0.3,0.3);
}

void Vision::VisionThread() {
	//Create Camera object
	cs::UsbCamera camera = cs::UsbCamera();

	//Set brightness and exposure
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
		//cv::inRange(hsv, cv::Scalar(20, 100, 100), cv::Scalar(30, 255, 255), threshOutput);
		cv::inRange(hsv, cv::Scalar(20, 100, 100), cv::Scalar(30, 255, 255), threshOutput);

		//group pixels into contours
		cv::findContours(threshOutput, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

		//Create some lists for circles and stuff
		std::vector<std::vector<cv::Point>> contours_poly (contours.size());
		std::vector<cv::Point2f> center(contours.size());
		std::vector<float> radius(contours.size());

		std::vector<cv::Point2f> centerLarge;
		std::vector<float> radiusLarge;

		//Variables for Circle Y coordinates and index in array
		int circleIndex = -1;
		//int circleY = src.cols;

		//create circles around contours
		for(unsigned int i = 0; i < contours.size(); i++) {

			//if the contour is too small, it will skip to the next iteration of the loop
			float contourArea = cv::contourArea(contours[i]);
			if(contourArea < 30){continue;}

			cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
			minEnclosingCircle((cv::Mat)contours_poly[i], center[i], radius[i]);

			//if the radius of the circle is too small, it will not be drawn
			if(radius[i] > 15 /*&& center[i].y < circleY*/){
				circleIndex = i;
				//circleY = center[i].y;
			}

			cv::drawContours(src, contours_poly, i, cv::Scalar(255, 0, 255), 1, 8, hierarchy, 0, cv::Point() );
		}

		//draw a line down the middle.
		cv::line(src, cv::Point(src.cols/2,0), cv::Point(src.cols/2,src.rows), cv::Scalar(0,0,255), 1);

        //Find the average of the x coordinates of the circle.
        cv::Mat mean;
        int width = src.cols;
        int pixelCenter = width / 2;

        //Only process if circle found
        if(circleIndex > -1){
        	//TODO: look into what this does
        	centerLarge.push_back(center[circleIndex]);

        	//draw circle
        	 cv::circle(src, center[circleIndex], (int)radius[circleIndex], cv::Scalar(255, 0, 255), 2, 8, 0);

        	 //Find the average of the x coordinates?
        	 cv::reduce(centerLarge, mean, 1, cv::ReduceTypes::REDUCE_AVG);

        	 //This creates and converts the matrix to a point, and draws a dot.
        	 cv::Point2f meanPoint(mean.at<float>(0,0), mean.at<float>(0,1));
        	 cv::circle(src, meanPoint, 3, cv::Scalar(0, 0, 255), -1, 8, 0);

        	 //start grabber
        	 Vision::seeYellow = true;

        	 //Set PID input to current offset
        	 Vision::visionSource->SetInput((double)meanPoint.x - (double)pixelCenter);
        }
        else{
        	Vision::seeYellow = false;
        	Vision::visionSource->SetInput(0.0);
        }

		outputStreamStd.PutFrame(src);
	}
}

bool Vision::GetSeeYellow() {
	return Vision::seeYellow;
}

double Vision::GetOffset(){
	return Vision::visionOutput->GetValue();
}

void Vision::TogglePIDLoop(bool PIDstate) {
	if(PIDstate == true){
		Vision::visionControl->Enable();
	}
	else{
		Vision::visionControl->Disable();
	}
}


bool Vision::seeYellow = false;
PIDNumSource* Vision::visionSource = new PIDNumSource(0.0);
PIDNumOutput* Vision::visionOutput = new PIDNumOutput();
frc::PIDController* Vision::visionControl = new frc::PIDController(-0.04, -0.005, 0.0, Vision::visionSource, Vision::visionOutput);
//TODO find what the PID values in the controller mean
