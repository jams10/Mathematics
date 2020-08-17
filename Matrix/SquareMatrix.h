#pragma once

#include <iostream>
/*
	행렬 클래스.
	행렬식 함수는 2*2,3*3,4*4 행렬 까지 테스트 완료.
*/
class SquareMatrix
{
public:
	SquareMatrix();
	SquareMatrix(const SquareMatrix& ref); // 복사 생성자
	SquareMatrix(const int& size_in);
	~SquareMatrix();
	void SetMatrix(const int* arr);
	void ShowMatrix() const;
	int GetDet(const SquareMatrix& m, int& size);
	SquareMatrix operator+(SquareMatrix& m);
	SquareMatrix operator-(SquareMatrix& m);
	SquareMatrix operator*(SquareMatrix& m);
	SquareMatrix& operator=(const SquareMatrix& m);
private:
	int size;
	int* pArr;
};