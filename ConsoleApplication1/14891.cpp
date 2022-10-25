#include "pch.h"

/*
* 이차원 배열
* 재귀
* 토륵
*/
int arr[4][8];
bool bChecked[4] = { false,false,false,false };

void foword(int index)
{
	int last = arr[index][7];

	for (int i{ 7 }; i > 0; --i)
	{
		arr[index][i] = arr[index][i-1];
	}

	arr[index][0] = last;
}

void inverse(int index)
{
	int start = arr[index][0];

	for (int i{ 1 }; i < 8; ++i)
	{
		arr[index][i - 1] = arr[index][i];
	}

	arr[index][7] = start;
}

/*
* 오른쪽으로 움직이는 함수
*/
void aaa(size_t index, int dir)
{
	if (bChecked[index])
		return;

	bChecked[index] = true;

	if (index < 0 || index > 3)
		return;

	//cout << "인덱스 " << index << endl;

	if (arr[index][2] != arr[index + 1][6])
	{
		//cout << "양의 방향 일치 " << endl;
		aaa(index + 1, dir * -1);
	}
	

	if (arr[index][6] != arr[index - 1][2])
	{
		//cout << "음의 방향 일치 " << endl;
		aaa(index - 1, dir * -1);
	}

	if (dir == 1)
	{
		foword(index);
	}
	else
	{
		inverse(index);
	}

	return;
}

int main()
{
	for (size_t i{ 0 }; i < 4; ++i)
	{
		string str;

		cin >> str;
		for (size_t j{ 0 }; j < str.size(); ++j)
		{
			arr[i][j] = str[j] - '0';
		}
	}
	int N;

	cin >> N;


	for (int i{ 0 }; i < N; ++i)
	{
		int index;
		int dir;

		cin >> index >> dir;

		aaa(index - 1, dir);

		for (int i = 0; i < 4; ++i)
		{
			bChecked[i] = false;
		}
	}

	int cnt{ 0 };

	for (int i{ 0 }; i < 4; ++i)
	{
		if (arr[i][0] == 1)
		{
			switch (i)
			{
			case 0:
				cnt += 1;
				break;
			case 1:
				cnt += 2;
				break;
			case 2:
				cnt += 4;
				break;
			case 3:
				cnt += 8;
				break;
			}
		}
	}
	cout << cnt;
	return 0;

}