class longLong
{
public:
	longLong() {};
	LongLong(const long highest, const unsigned long lower){};
	longLong(const longLong& other) {};
	~longLong();


	long GetHighest() const {};

	unsigned long GetLower() const {};

	long GetAddition() const {};

	long GetMultiplication() const {};

	long GetDivision() const {};

	long GetDivisionWithRemaider() const {};


private: 

	long highest;

	unsigned long lower;

};