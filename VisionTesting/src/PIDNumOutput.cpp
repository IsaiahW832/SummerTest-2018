#include <PIDNumOutput.h>

PIDNumOutput::PIDNumOutput() {
	value = 0.0;
}

void PIDNumOutput::PIDWrite(double output) {
	value = output;
}

double PIDNumOutput::GetValue() {
	return value;
}
