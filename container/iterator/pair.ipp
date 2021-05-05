template <typename T, typename U>
Pair<T, U>::Pair() : _m1(NULL) {}

template <typename T, typename U>
Pair<T, U>::Pair(const Pair& src) : _m1(src.m1), _m2(src.m2)
{}

template <typename T, typename U>
Pair<T, U>::Pair(T v1, U v2)
{
	this->_m1 = v1;
	this->_m2 = v2;
}

template <typename T, typename U>
Pair<T, U>::~Pair() {}

template <typename T, typename U>
Pair<T, U>&		Pair<T, U>::operator=(const Pair& src)
{
	if (this != &src)
	{
		this->_m1 = src._m1;
		this->_m2 = src._m2;
	}
	return (*this);
}

template <typename T, typename U>
T&		Pair<T, U>::first()
{
	return (_m1);
}

template <typename T, typename U>
const T&		Pair<T, U>::first() const
{
	return (_m1);
}

template <typename T, typename U>
U&		Pair<T, U>::second()
{
	return (_m2);
}

template <typename T, typename U>
const U&		Pair<T, U>::second() const
{
	return (_m2);
}
