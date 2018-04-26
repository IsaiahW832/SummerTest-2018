#include <PIDNumSource.h>

PIDNumSource::PIDNumSource(double number) {
	value = number;
}

void PIDNumSource::SetInput(double number){
	value = number;
}

double PIDNumSource::PIDGet(){
	return value;
}
