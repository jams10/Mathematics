#include <iostream>
#include "SquareMatrix.h"

int main()
{
	int size = 0;
	int* pArr;

	std::cout << "Enter the size of the square matrix : ";
	std::cin >> size;
	
	// size*size 만큼의 행렬 생성
	SquareMatrix m(size);

	pArr = new int[size * size];

	// 행렬 요소 값 채우기
	for (int i = 0; i < size * size; i++)
	{
		std::cout << "Enter the number : ";
		std::cin >> pArr[i];
	}

	m.SetMatrix(pArr);
	
	// 행렬 출력
	for (int i = 0; i < size * 4 + 1; i++)
	{
		std::cout << ' ';
	}
	std::cout << "<Matrix>" << std::endl;
	m.ShowMatrix();
	std::cout << std::endl << std::endl;

	// 행렬식 구하기
	std::cout << "det(m) : " << m.GetDet(m, size) << std::endl;

	delete[] pArr;
}