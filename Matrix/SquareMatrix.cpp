#include "SquareMatrix.h"

SquareMatrix::SquareMatrix()
{
	std::cout << "디폴트 생성자 호출" << std::endl;
	// 사이즈 만큼 동적배열 할당.
	pArr = new int[size * size];
	// 0으로 메모리 초기화
	memset(pArr, 0, size * size * sizeof(int));
}

SquareMatrix::SquareMatrix(const int& size_in)
	:
	size(size_in)
{
	std::cout << this << " 매개변수 생성자 호출" << std::endl;
	// 사이즈 만큼 동적배열 할당.
	pArr = new int[size * size];
	// 0으로 메모리 초기화
	memset(pArr, 0, size * size * sizeof(int));
}

SquareMatrix::SquareMatrix(const int& size_in, const int& name_in)
	:
	size(size_in),
	name(name_in)
{
	std::cout << this << " 매개변수 생성자 호출" << std::endl;
	// 사이즈 만큼 동적배열 할당.
	pArr = new int[size * size];
	// 0으로 메모리 초기화
	memset(pArr, 0, size * size * sizeof(int));
}

SquareMatrix::SquareMatrix(const int& size_in, const int* arr, const int& name)
	:
	SquareMatrix(size_in)
{
	this->name = -1;
	this->SetMatrix(arr);
}

SquareMatrix::~SquareMatrix()
{
	std::cout << this << " 소멸자 호출" << std::endl;
	//delete[] pArr;
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

SquareMatrix SquareMatrix::operator+(SquareMatrix& rhs)
{
	if (size != rhs.size)
	{
		fprintf(stderr, "The size of matrices is different!\n");
		exit(1);
	}

	SquareMatrix result(size,-1);

	for (int i = 0; i < rhs.size * rhs.size; i++)
	{
		result.pArr[i] = pArr[i] + rhs.pArr[i];
	}

	return result;
}

SquareMatrix SquareMatrix::operator-(SquareMatrix& rhs)
{
	if (size != rhs.size)
	{
		fprintf(stderr, "The size of matrices is different!\n");
		exit(1);
	}

	SquareMatrix result(size);

	for (int i = 0; i < rhs.size * rhs.size; i++)
	{
		result.pArr[i] = pArr[i] - rhs.pArr[i];
	}

	return result;
}

SquareMatrix SquareMatrix::operator*(SquareMatrix& rhs)
{
	if (size != rhs.size)
	{
		fprintf(stderr, "The size of matrices is different!\n");
		exit(1);
	}

	SquareMatrix result(size);
	int element = 0;

	for (int i = 0; i < rhs.size * rhs.size; i++)
	{
		element = pArr[i] + rhs.pArr[i * size];
		result.pArr[i] = element;
	}

	return result;
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& rhs)
{
	// rhs가 this와 다를 때만 할당
	if (this != &rhs)
	{
		delete[] pArr;
		this->SetMatrix(rhs.pArr);
		this->size = rhs.size;
	}

	return *this;
}
/*
<대입 연산자 오버로딩 시 자기 할당 확인>

https://edykim.com/ko/post/c-operator-overloading-guidelines/

https://musket-ade.tistory.com/entry/C-%EB%8C%80%EC%9E%85-%EC%97%B0%EC%82%B0%EC%9E%90-%EC%98%A4%EB%B2%84%EB%A1%9C%EB%94%A9
*/


/*
<연산자 오버로딩시 발생하는 오류>
 
 _CrtIsValidHeapPointer(block)

 https://hashcode.co.kr/questions/2996/c-%EB%A9%94%EB%AA%A8%EB%A6%AC%ED%95%B4%EC%A0%9C-debug-assertion

 http://blog.naver.com/PostView.nhn?blogId=mk002060&logNo=221368552004
*/

