#ifndef SRC_VISION_H_
#define SRC_VISION_H_

#include <CameraServer.h>
#include <cscore.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class Vision {
private:
	static bool seeYellow;
public:
	Vision();
	static void VisionThread();
	static bool GetSeeYellow();
};

#endif /* SRC_VISION_H_ */
