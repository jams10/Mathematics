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
		std::cout << '\t'<< pArr[i];
	}
}
// 행렬식(Determinant) 구하는 함수.
// 첫 행의 요소들을 기준으로 계산함.
int SquareMatrix::GetDet(const SquareMatrix& m, int& size)
{
	int det = 0;

	if (size == 2)
	{
		return (m.pArr[0] * m.pArr[3]) - (m.pArr[1] * m.pArr[2]);
	}

	for (int i = 0; i < size; i++)
	{
		SquareMatrix smaller(size - 1);
		int* tmpArr = new int[(size - 1) * (size - 1)];
		memset(tmpArr, 0, (size - 1) * (size - 1));

		int idx = 0;
		for (int j = size; j < size * size; j++) // 두번째 행 부터 시작.
		{
			if (j % size != i) // 자신의 열 번호에 해당하지 않는 원소들을 배열에 넣음.
			{
				tmpArr[idx] = m.pArr[j];
				idx++;
			}
		}

		smaller.SetMatrix(tmpArr);

		/* <Check smaller matrix elements>
		for (int k = 0; k < smaller.size * smaller.size; k++)
		{
			if (k % smaller.size == 0)
			{
				std::cout << std::endl;
			}
			std::cout << smaller.pArr[k];
		}
		std::cout << std::endl;
		*/

		delete[] tmpArr;

		if ((i + 1) % 2 == 0) // 홀수번째 : +, 짝수번째 : -
		{
			det += (m.pArr[i] * GetDet(smaller, smaller.size)) * -1;
			//std::cout << "i : " << i << std::endl << "det : " << det << std::endl;
		}
		else
		{
			det += (m.pArr[i] * GetDet(smaller, smaller.size));
			//std::cout << "i : " << i << std::endl << "det : " << det << std::endl;
		}
	}
	
	return det;
}

