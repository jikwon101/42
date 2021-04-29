	template <typename _Iters>
	vector_iterator<_Iters>::vector_iterator() : _ptr(0) { }
	
	template <typename _Iters>
	vector_iterator<_Iters>::~vector_iterator(){}

	template <typename _Iters>
	vector_iterator<_Iters>::vector_iterator(iterator_type const src) 
	{
		_ptr = src; 
	}

	template <typename _Iters>
	vector_iterator<_Iters>::vector_iterator(vector_iterator const& rhs) 
	{
		_ptr = rhs.base();
	}
			
	template <typename _Iters>
	template <typename U> 
	vector_iterator<_Iters>::vector_iterator(vector_iterator<U> const& rhs, typename ft::enable_if<!ft::is_const<U>::value, U>::type) 
	{
		_ptr = rhs.base();
	}

	template <typename _Iters>
	typename vector_iterator<_Iters>::reference	vector_iterator<_Iters>::operator*() const 
	{
		return (*_ptr); 
	}
		
	template <typename _Iters>
	vector_iterator<_Iters>&	vector_iterator<_Iters>::operator=(vector_iterator const& rhs)
	{
			this->_ptr = rhs.base();
			return (*this);
	}

	template <typename _Iters>
	typename vector_iterator<_Iters>::iterator_type	vector_iterator<_Iters>::base() const 
	{
		return (_ptr);
	}	

	template <typename _Iters>
	vector_iterator<_Iters>&	vector_iterator<_Iters>::operator++()
	{
		++_ptr; 
		return (*this);
	}

	template <typename _Iters>
	vector_iterator<_Iters>		vector_iterator<_Iters>::operator++(int) 
	{
		vector_iterator ret(*this);
		++ret; 
		return (*this);
	}

	template <typename _Iters>
	vector_iterator<_Iters>&	vector_iterator<_Iters>::operator--() 
	{
		--_ptr; 
		return (*this);
	}

	template <typename _Iters>
	vector_iterator<_Iters>		vector_iterator<_Iters>::operator--(int) 
	{
		vector_iterator ret = *this; 
		--ret; return (*this);
	}

	template <typename _Iters>
	typename vector_iterator<_Iters>::pointer	vector_iterator<_Iters>::operator->()	
	{
		return (_ptr); 
	}

	template <typename _Iters>
	template <typename U>
	bool	vector_iterator<_Iters>::operator==(vector_iterator<U> const& rhs) const 
	{
		return (this->_ptr == rhs.base());
	}
			
	template <typename _Iters>
	template <typename U>
	bool 	vector_iterator<_Iters>::operator!=(vector_iterator<U> const &rhs) const 
	{
		return (this->_ptr != rhs.base());
	}

	template <typename _Iters>
	vector_iterator<_Iters>&	vector_iterator<_Iters>::operator+=(difference_type n) 
	{
		this->_ptr += n;
		return (*this);
	}

	template <typename _Iters>
	vector_iterator<_Iters>&	vector_iterator<_Iters>::operator-=(difference_type n)
	{
		this->_ptr -= n;
		return (*this);
	}

	template <typename _Iters>
	typename vector_iterator<_Iters>::reference		vector_iterator<_Iters>::operator[](int n) const
	{ 
		return (*(_ptr += n)); 
	}

	template <typename _Iters>
	template <typename U>
	bool 	vector_iterator<_Iters>::operator>(vector_iterator<U> const& other) const 
	{
		return (this->_ptr > other.base()); 

	}
	
	template <typename _Iters>
	template <typename U>
	bool	vector_iterator<_Iters>::operator<(vector_iterator<U> const& other) const 
	{
		return (this->_ptr < other.base()); 
	}

	template <typename _Iters>
	template <typename U>
	bool 	vector_iterator<_Iters>::operator<=(vector_iterator<U> const& other) const 
	{
		return (this->_ptr <= other.base()); 
	}

	template <typename _Iters>
	template <typename U>
	bool 	vector_iterator<_Iters>::operator>=(vector_iterator<U> const& other) const 
	{
		return (this->_ptr >= other.base()); 
	}

	template <typename _Iters>
	vector_iterator<_Iters> 	vector_iterator<_Iters>::operator+(difference_type n) 
	{
		return (this->_ptr + n); 
	}

	template <typename _Iters>
	vector_iterator<_Iters>		vector_iterator<_Iters>::operator-(difference_type n) 
	{
		return (this->_ptr - n); 
	}
