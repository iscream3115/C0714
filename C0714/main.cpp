#include <iostream>
#include <time.h>
using namespace std;
int arr[10000][10000];

int main()
{
	clock_t st;
	clock_t end;

	st = clock();

	//arr[j][i](1449ms) 와 arr[i][j](455ms)의 속도가 서로 다른 이유
	//2차원 배열에 메모리를 넣을 때 배열은 각 행마다 열이 연결되어 있는 형태라 i,j로 넣으면 캐시히트가
	//적지만, j,i로 넣을 경우 연결되지 않는 행의 기준으로 넣어주기 떄문에 캐시히트가 크다.
	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 10000; j++)
		{
			arr[i][j] = i;
		}
	}

	end = clock();

	cout << "time: " << end - st <<"ms" << endl;


	return 0;
}