template <typename T>
node<T>::node() 
		: _prev(NULL), _next(NULL)
{}

template <typename T>
node<T>::node(const T& val) 
		: _prev(NULL), _next(NULL), _val(val)
{}
/*
template <typename T, typename U>
node<T, U>::node() 
		: _prev(NULL), _next(NULL)
{}

template <typename T, typename U>
node<T, U>::node(const T& val) 
		: _prev(NULL), _next(NULL), _val(val)
{}
*/
/*
template <typename T>
typename node<T>::pointer	node<T>::head()
{
	pointer pos = NULL;

	while (pos->_prev != NULL)
		pos = pos->_prev;
	return (pos);
}

template <typename T>
typename node<T>::pointer	node<T>::tail()
{
	pointer pos = NULL;

	while (pos->_next != NULL)
		pos = pos->_next;
	return (pos);
}
*/
