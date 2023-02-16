#include "pch.h"

int test = 0;
int idx = 0;
deque<int> Mydec{};
queue<char> que;
bool toggle = true;
bool error = false;
int main()
{
	cin >> test;

	while (0 < test)
	{
		string str;
		cin >> str;

		for (size_t i = 0; i < str.size(); ++i)
		{
			que.push(str[i]);
		}
		
		cin >> idx;
		int cnt = 1;
		int value = 0;

		cin >> str;

		Mydec.clear();
		toggle = true;
		error = false;
		string s{};
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (isdigit(str[i])) {
				s += str[i];

			}
			else {
				if (!s.empty()) {
					Mydec.push_back(stoi(s));
					s = "";
				}
			}
		}
			
		while (!que.empty())
		{
			char ch = que.front();
			que.pop();

			switch (ch)
			{
			case 'R':
				if (false == toggle)
				{
					toggle = true;
				}
				else
				{
					toggle = false;
				}
				break;
			case 'D':
			{
				if (Mydec.empty())
				{
					error = true;
				}
				else
				{
					if (toggle)
					{
						Mydec.pop_front();
					}
					else
					{
						Mydec.pop_back();
					}
				}
				
			}
				break;
			}
		}

		if (error)
			cout << "error" << endl;
		else
		{
			cout << "[";

			while (!Mydec.empty())
			{
				int value = 0;

				if (toggle)
				{
					value = Mydec.front();
					if(1 < Mydec.size())
						cout << value << ",";
					else
						cout << value;

					Mydec.pop_front();
				}
				else
				{
					value = Mydec.back();
					if (1 < Mydec.size())
						cout << value << ",";
					else
						cout << value;

					Mydec.pop_back();
				}
			}
			cout << "]" << endl;
		}

		--test;
	}

	return 0;
}