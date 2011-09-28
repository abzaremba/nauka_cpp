#ifndef GUARD_Student_info
#define GUARD_Student_info


//#include <iostream>
//#include <string>
#include <vector>
#include <string>
////#include <list>
//
//


class Core {
	friend class Student_info;
public:
	Core(): midterm(0), final(0) { }
	Core(std::istream& is) { read(is); }

	std::string name() const { return n; };

	virtual std::istream& read(std::istream&);
	virtual double grade() const;
protected:
	virtual Core* clone() const { return new Core(*this); }
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;
private:
	std::string n;
};


class Grad: public Core {
public:
	Grad(): thesis(0) { }
	Grad(std::istream& is) { read (is); }

	double grade() const;
	std::istream& read(std::istream&);
protected:
	Grad* clone() const { return new Grad(*this); }
private:
	double thesis;
};

class Student_info {
public:
	//constructors and copy control
	Student_info(): spointer(0) { }
	Student_info(std::istream& is): spointer(0) { read(is); }
	Student_info(const Student_info&);
	Student_info& operator= (const Student_info&);
	~Student_info() { delete spointer; }

	//operations
	std::istream& read(std::istream&);

	std::string name() const {
		if (spointer) return spointer->name();
		else throw std::runtime_error("uninitialised Student");
	}
	double grade() const {
		if (spointer) return spointer->grade();
		else throw std::runtime_error("uninitialised student");
	}
	static bool compare (const Student_info& s1, const Student_info& s2) {
		return s1.name() < s2.name();
	}

private:
	Core* spointer;
};

bool compare (const Core&, const Core&);



std::istream& read_hw(std::istream&, std::vector<double>&);


#endif
