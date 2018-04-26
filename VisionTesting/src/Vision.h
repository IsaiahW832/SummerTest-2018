#ifndef SRC_VISION_H_
#define SRC_VISION_H_

#include <CameraServer.h>
#include <cscore.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "PIDNumSource.h"
#include "PIDNumOutput.h"
#include <PIDController.h>


class Vision {
private:
	static bool seeYellow;

	//PID Pointers
	static PIDNumSource* visionSource;
	static PIDNumOutput* visionOutput;
	static frc::PIDController* visionControl;
public:
	Vision();
	static void VisionThread();
	static bool GetSeeYellow();
	static double GetOffset();
	static void TogglePIDLoop(bool PIDstate);
};

#endif /* SRC_VISION_H_ */
