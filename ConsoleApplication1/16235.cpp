#include "pch.h"

//�ִ� �Է� ���� ��
const int MAX = 10;

//8���� ����ü
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
			//��� �Է�, ���� �ʱ�ȭ
			cin >> nutrient[i][j];
			arr[i][j] = 5;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int y, x, age;
		cin >> y >> x >> age;
		//���� �߰�
		v[y - 1][x - 1].push_back(age);
	}

	//�� ����
	//���� �ݺ�
	for (int k = 0; k < K; ++k)
	{
		//�� �ݺ�
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				//������ �ִٸ�
				if (v[y][x].size())
				{
					//���� ���� ó�� ����
					int dead = 0;

					//���� ���� ���� ����
					vector<int> temp;

					//���� ���� ��ŭ �ݺ����� ����.
					for (int i = 0; i < v[y][x].size(); ++i)
					{
						//���̸� ���ϰ�
						int age = v[y][x][i];

						//���� ����� �������� ũ�ų� ���ٸ�
						if (arr[y][x] >= age)
						{
							//���ο� ���� ����, ��� ����
							arr[y][x] -= age;
							temp.push_back(age + 1);
						}
						else
						{
							//���� ���� ó��
							dead += age / 2;
						}
					}

					//���� ������ ���� ���� ��ŭ
					for (int i = 0; i < temp.size(); ++i)
					{
						//������ �����Ѵ�.
						v[y][x].push_back(temp[i]);
					}

					//���� ����� ������Ʈ
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