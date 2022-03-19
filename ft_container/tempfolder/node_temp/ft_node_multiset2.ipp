template <typename T>
node_multiset<T>::node_multiset() 
	:  Lchild(NULL), Rchild(NULL), Parent(NULL), color(RED)
{}

template <typename T>
node_multiset<T>::node_multiset(value_type const& src) 
	: Lchild(NULL), Rchild(NULL), Parent(NULL), data(src), color(RED)
{}

template <typename T>
node_multiset<T>::node_multiset(node_multiset const& src) 
	: color(src.color), data(src.data)
{
	Lchild = src.Lchild;
	Rchild = src.Rchild;
	Parent = src.Parent;
}

template <typename T>
node_multiset<T>&	node_multiset<T>::operator=(node_multiset const& src)
{
	if (this != &src)
	{
		color = src.color;
		Lchild = src.Lchild;
		Rchild = src.Rchild;
		Parent = src.Parent;
		data = src.data;
	}
	return (*this);
}

template <typename T>
node_multiset<T>::~node_multiset()
{}
