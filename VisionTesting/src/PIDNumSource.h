#ifndef SRC_PIDNUMSOURCE_H_
#define SRC_PIDNUMSOURCE_H_

#include <PIDSource.h>

class PIDNumSource : public frc::PIDSource {
public:
	PIDNumSource(double number);

	void SetInput(double number);
	double PIDGet();

private:
	double value;
};

#endif /* SRC_PIDNUMSOURCE_H_ */
