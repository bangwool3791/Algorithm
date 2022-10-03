#include "pch.h"

class CPerson
{
public :
	int Sex{ 0 };
	int Index{ 0 };
};

void recursive(int a, int b, int max, vector<int>& _v)
{
	if (a <= 0)
		return;

	 if (b > max)
		return;

	if (_v[a -1] == _v[b-1])
	{
		_v[a - 1] = !_v[a - 1];
		_v[b - 1] = !_v[b - 1];
		recursive(a - 1, b + 1, max, _v);
		return;
	}

	return;
}

int main()
{
	int c{ 0 }, index{ 0 };
	cin >> c;
	vector<int> v;
	back_insert_iterator iter{ v };
	index = c;
	while (c > 0)
	{
		int a{ 0 };
		cin >> a;
		*iter = a;
		--c;
	}

	int p{ 0 };

	cin >> p;
	vector<CPerson> vecp;
	back_insert_iterator iterp{ vecp };
	while (p > 0)
	{
		CPerson st;
		cin >> st.Sex;
		cin >> st.Index;
		*iterp = st;
		--p;
	}

	auto f1{ [&v, index, c](auto begin, auto end)
	{
		int k = 0;

		for (auto elem{begin}; elem != end; ++elem)
		{
			if (elem->Index <= 0 || elem->Index > index)
				continue;

			k = elem->Index;
			switch (elem->Sex)
			{
			case 1:
				while ((elem->Index) <= index)
				{
					v[elem->Index -1] = !v[elem->Index -1];
					elem->Index += k;
				}
				break;
			case 2:
				recursive(elem->Index - 1, elem->Index + 1, index, v);
				v[elem->Index - 1] = !v[elem->Index - 1];
				break;
			}
		}
	}};

	f1(begin(vecp), end(vecp));

	for (size_t i{ 0 }; i < v.size(); ++i)
	{
		cout << v[i] << ' ';
		if ((i +1) % 20 == 0)
			cout << '\n';
	}

	return 0;
}