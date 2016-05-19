#pragma once
#include <string>
class Printable
{
	 std::string virtual print() const = 0;
};
class Named : public Printable
{
public:
	std::string virtual print() const
	{
		return name;
	}
	Named(std::string s) :name(s) {};
	virtual ~Named() {};
private:
	std::string name;
};