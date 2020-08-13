#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(const int& size_in)
	:
	size(size_in)
{
	// 사이즈 만큼 동적배열 할당.
	pArr = new int[size * size];
	// 0으로 메모리 초기화
	memset(pArr, 0, size * size * sizeof(int));
}

SquareMatrix::~SquareMatrix()
{
	delete[] pArr;
}

void SquareMatrix::SetMatrix(const int* arr)
{
	for (int i = 0; i < size * size; i++)
	{
		pArr[i] = arr[i];
	}
}

void SquareMatrix::ShowMatrix() const
{
	for (int i = 0; i < size * size; i++)
	{
		if (i % size == 0)
		{
			std::cout << std::endl;
		}
		std::cout << pArr[i % size];
	}
}

int SquareMatrix::GetDet(const SquareMatrix& m, int& size, int& row, int& column) const
{
	int det = 0;

	// size 가 2 일 경우, 2*2 행렬. -> recursive 함수 탈출 할 수 있도록 det 값 리턴.

	// for(int i = 0; i < size; i++) return (i 번째 요소) * GetDet(m, --size, 
}
