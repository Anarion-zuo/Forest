#pragma once
template <class T> class Number
{
protected:
	void* p = nullptr;
public:

	Number(void* pp) : p(pp) {}
	virtual ~Number() { if (p)  delete p; }

	//virtual inline T val() = 0;

	virtual void operator = (const Number<T>* num) = 0;
	virtual Number<T>* operator-() = 0;
	virtual Number<T>* operator+(const Number<T>* num) const = 0;
	virtual Number<T>* operator-(const Number<T>* num) const = 0;
	virtual Number<T>* operator*(const Number<T>* num) const = 0;
	virtual Number<T>* operator/(const Number<T>* num) const = 0;
	virtual Number<T>* operator%(const Number<T>* num) const = 0;
	virtual bool operator<(const Number<T>* num) const = 0;
	virtual bool operator>(const Number<T>* num) const = 0;
	virtual bool operator==(const Number<T>* num) const = 0;
	virtual bool operator!=(const Number<T>* num) const = 0;
	virtual bool operator<=(const Number<T>* num) const = 0;
	virtual bool operator>=(const Number<T>* num) const = 0;
	virtual Number<T>* tenth(const Number<T>* num) = 0;
};

