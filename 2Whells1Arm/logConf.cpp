#include "logConf.h"

LogConf::LogConf()
{
}

LogConf::~LogConf()
{
}

int	LogConf::getMaxGene() const
{
	return this->maxGene;
}

int	LogConf::getSizeGene() const
{
	return this->sizeGene;
}

int	LogConf::getNbAction() const
{
	return this->nbAction;
}

void LogConf::setMaxGene(const int newMax)
{
	this->maxGene = newMax;
}

void LogConf::setSizeGene(const int newSize)
{
	this->sizeGene = newSize;
}

void LogConf::setNbAction(const int newNb)
{
	this->nbAction = newNb;
}


//std::ostream& LogConf::operator<<(std::ostream& os, const LogConf& obj)
//{
//	os << obj.getMaxGene() << std::endl
//		<< obj.getSizeGene() << std::endl
//		<< obj.getNbAction() << std::endl;
//	return os;
//}

//std::istream& LogConf::operator>>(std::istream& is, LogConf& obj)
//{
//	// read obj from stream
//	if ( /* T could not be constructed */)
//		is.setstate(std::ios::failbit);
//	return is;
//}