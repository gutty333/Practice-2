/*
The Surgery class will have stored within it the charges for at least five types of
surgery.It can update the charges variable of the PatientAccount class.
*/

#ifndef SURGERY_H
#define SURGERY_H


class Surgery
{
	private:
		double arm, leg, hip, knee, neck;

	public:
		Surgery();
		double getArm();
		double getLeg();
		double getHip();
		double getKnee();
		double getNeck();
};


#endif