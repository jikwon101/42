template <typename T1, typename T2>
Pair<T1, T2>::Pair() {}

template <typename T1, typename T2>
template <typename U1, typename U2>
Pair<T1, T2>::Pair(Pair<U1, U2> const& src) : first(src.first), second(src.second)
{}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 const& v1, T2 const& v2) : first(v1), second(v2)
{}

template <typename T1, typename T2>
template <typename U1, typename U2>
Pair<T1, T2>::Pair(U1 const& v1, U2 const& v2) : first(v1), second(v2)
{}

template <typename T1, typename T2>
Pair<T1, T2>::~Pair() {}

template <typename T1, typename T2>
Pair<T1, T2>&		Pair<T1, T2>::operator=(const Pair& src)
{
	if (this != &src)
	{
		this->first = src.first;
		this->second = src.second;
	}
	return (*this);
}
