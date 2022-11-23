#include "Angle.h"

Angle::Angle()
{
	degree = new double;
	minutes = new double;
	*degree = 0;
	*minutes = 0;
}
Angle::Angle(double d, double m) 
{
	degree = new double;
	minutes = new double;
	*degree = d; *minutes = m;
}

double Angle::getd() { return *degree; }
double Angle::getm() { return *minutes; }
double Angle::getANG() { return *degree + *minutes / 60; }
void Angle::setd(int d) { degree = new double; *degree = d; }
void Angle::setm(int m) { minutes = new double; *minutes = m; }

double Angle::ConversionToRadians() { double result = 0; result = ((*degree + *minutes / 60) * M_PI) / 180; return result; }

double Angle::Sin() { return sin(ConversionToRadians()); } 

Angle Angle::range0360() {

	bool end = true;
	Angle rs;
	*rs.degree = *degree; *rs.minutes = *minutes;
	while (end){
		if (*rs.degree > 360) {
			*rs.degree = *rs.degree - 360;
		}
		if (*rs.minutes > 60) {
			*rs.minutes = *rs.minutes - 60;
		}
		if ((*rs.minutes > 0 && *rs.minutes < 60)&&(*rs.degree > 0 && *rs.degree < 360)) { end = false; }
	}
	return rs;
}
void Angle::operetorsrv(const Angle& ang) {
	double ANG2 = *ang.degree + *ang.minutes / 60;
	double ANG1 = *degree + *minutes / 60;
	if (ANG1 == ANG2) { std::cout << " angles are equal \n"; }
	else if (ANG1 > ANG2) { std::cout << " ANG1>ANG2 \n"; }
	else if (ANG1 < ANG2) { std::cout << " ANG1<ANG2 \n"; }
}
Angle Angle::operator-(const Angle& ang) {
	Angle result;
	*result.degree = *degree - *ang.degree;
	*result.minutes = *minutes - *ang.minutes;
	if (*result.minutes < 0) { *result.degree -= 1; *result.minutes = 60 + *result.minutes; }
	return result;
}
Angle Angle::operator+(const Angle& ang) {
	Angle result;
	*result.degree = *degree + *ang.degree;
	*result.minutes = *minutes + *ang.minutes;
	if (*result.minutes > 60) { *result.degree += 1; *result.minutes = *result.minutes - 60; }
	return result;

}
std::ostream& operator<<(std::ostream& out, Angle& ang)
{
	out << "ANGLE : " << "{ " << *ang.degree << ' ' << *ang.minutes << '`' << " }" << std::endl;
	return out;

}
std::istream& operator>>(std::istream& in, Angle& ang)
{
	in >> *ang.degree;
	std::cin.ignore();
	in >> *ang.minutes;
	std::cin.ignore();
	return in;
}
std::string Angle::toString() {
	return("ANGLE : { " + std::to_string(getd()) + ' ' + std::to_string(getm()) + '`' + " }");
}
Angle& Angle::operator=(const Angle& ang)
{
	if (&ang != this)
	{
		*degree = *ang.degree;
		*minutes = *ang.minutes;
	}
	else
		return *this;
}
Angle::~Angle() {
	delete degree;
	delete minutes;

}