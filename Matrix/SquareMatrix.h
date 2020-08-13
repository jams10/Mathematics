#include <iostream>

class SquareMatrix
{
public:
	SquareMatrix(const int& size_in);
	~SquareMatrix();
	void SetMatrix(const int* arr);
	void ShowMatrix() const;
	int GetDet(const SquareMatrix& m, int& size, int& row, int& column) const;
private:
	int size;
	int* pArr;
};