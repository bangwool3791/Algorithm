#include "pch.h"

/*
* 
push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. 
���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/
class CStack
{
private:
	long long data[10000];
	int index = 0;
public:
	void push(long long _data)
	{
		data[index++] = _data;
	}

	long long pop()
	{
		if (index == 0)
			return -1;
		else
		{
			long long _data = data[index - 1];
			--index;
			return _data;
		}
	}

	int size()
	{
		return index;
	}

	bool empty()
	{
		return index == 0;
	}

	long long top()
	{
		if (index == 0)
			return -1;
		else
		{
			return data[index - 1];
		}
	}
};

int main()
{
	CStack* _stack = new CStack;

	int n;

	cin >> n;

	for (int i = 0; i < n; ++n)
	{
		char ch[7];
		cin >> ch;

		if (!strcmp("push", ch))
		{
			cin >> ch;
			int value = stoi(ch);
			_stack->push(value);
		}
		else if (!strcmp("pop", ch))
		{
			cout << _stack->pop() << '\n';

		}
		else if (!strcmp("size", ch))
		{
			cout << _stack->size() <<  '\n';
		}
		else if (!strcmp("empty", ch))
		{
			cout << _stack->empty() <<  '\n';
		}
		else if (!strcmp("top", ch))
		{
			cout << _stack->top() <<  '\n';
		}
	}
	delete _stack;
	return 0;
}