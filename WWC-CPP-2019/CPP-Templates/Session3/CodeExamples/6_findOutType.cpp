template <typename T>
class TD;

template <typename T>
void f(T& param)
{
	
	TD<T> ttype;
	TD<decltype(param)> paramType;
}

int main()
{
	int x = 22;
	const int& rx = x;
	f(rx);
}