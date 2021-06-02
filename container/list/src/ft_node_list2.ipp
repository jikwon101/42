template <typename T>
node_list<T>::node_list() 
	: _prev(NULL), _next(NULL)
{}

template <typename T>
node_list<T>::node_list(value_type const& val) 
	: _prev(NULL), _next(NULL), _val(val)
{}


template <typename T>
node_list<T>::node_list(node_list const& src)
	: _prev(src._prev), _next(src._next), _val(src._val) 
{}

template <typename T>
node_list<T>::~node_list()
{
	_prev = _next = NULL;
}

template <typename T>
node_list<T>&	node_list<T>::operator=(node_list const& src)
{
	if (this != &src)
	{
		_prev = src._prev;
		_next = src._next;
		_val = src._val;
	}
	return (*this);
}
