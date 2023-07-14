#include <iostream>
#include <time.h>
using namespace std;
int arr[10000][10000];

int main()
{
	clock_t st;
	clock_t end;

	st = clock();

	//arr[j][i](1449ms) �� arr[i][j](455ms)�� �ӵ��� ���� �ٸ� ����
	//2���� �迭�� �޸𸮸� ���� �� �迭�� �� �ึ�� ���� ����Ǿ� �ִ� ���¶� i,j�� ������ ĳ����Ʈ��
	//������, j,i�� ���� ��� ������� �ʴ� ���� �������� �־��ֱ� ������ ĳ����Ʈ�� ũ��.
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