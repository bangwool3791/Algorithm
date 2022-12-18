#include "pch.h"

/*
* 
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 
만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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