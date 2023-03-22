#include "pch.h"

//최대 입력 나무 수
const int MAX = 10;

//8방향 구조체
typedef struct
{
	int y, x;
}Dir;

Dir moveDir[8] = { {1,1,}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

int arr[MAX][MAX];
int nutrient[MAX][MAX];
vector<int> v[MAX][MAX];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			//양분 입력, 토지 초기화
			cin >> nutrient[i][j];
			arr[i][j] = 5;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int y, x, age;
		cin >> y >> x >> age;
		//나무 추가
		v[y - 1][x - 1].push_back(age);
	}

	//봄 여름
	//연수 반복
	for (int k = 0; k < K; ++k)
	{
		//땅 반복
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				//나무가 있다면
				if (v[y][x].size())
				{
					//죽은 나무 처리 변수
					int dead = 0;

					//생성 나무 저장 변수
					vector<int> temp;

					//나무 갯수 만큼 반복문을 돈다.
					for (int i = 0; i < v[y][x].size(); ++i)
					{
						//나이를 구하고
						int age = v[y][x][i];

						//토지 양분이 나무보다 크거나 같다면
						if (arr[y][x] >= age)
						{
							//새로우 나무 생성, 양분 차감
							arr[y][x] -= age;
							temp.push_back(age + 1);
						}
						else
						{
							//죽은 나무 처리
							dead += age / 2;
						}
					}

					//새로 생성된 나무 개수 만큼
					for (int i = 0; i < temp.size(); ++i)
					{
						//나무를 생성한다.
						v[y][x].push_back(temp[i]);
					}

					//땅에 양분을 업데이트
					arr[y][x] += dead;
				}
			}
		}

		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				if (v[y][x].size())
				{
					for (int i = 0; i < v[y][x].size(); ++i)
					{
						int age = v[y][x][i];

						if (age % 5 == 0)
						{
							for (int j = 0; j < 8; ++j)
							{
								int nextY = y + moveDir[j].y;
								int nextX = x + moveDir[j].x;

								if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
								{
									v[nextY][nextX].push_back(1);
								}
							}

						}
					}
				}
			}
		}

		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				arr[y][x] += nutrient[y][x];
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			result += v[i][j].size();
		}
	}

	cout << result << '\n';
	return 0;
}