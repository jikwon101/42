template <typename T>
node_multimap<T>::node_multimap() 
	:  Lchild(NULL), Rchild(NULL), Parent(NULL), color(RED)
{}

template <typename T>
node_multimap<T>::node_multimap(value_type const& src) 
	: Lchild(NULL), Rchild(NULL), Parent(NULL), data(src), color(RED)
{}

template <typename T>
node_multimap<T>::node_multimap(node_multimap const& src) 
	: color(src.color), data(src.data)
{
	Lchild = src.Lchild;
	Rchild = src.Rchild;
	Parent = src.Parent;
}

template <typename T>
node_multimap<T>&	node_multimap<T>::operator=(node_multimap const& src)
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
node_multimap<T>::~node_multimap()
{}
