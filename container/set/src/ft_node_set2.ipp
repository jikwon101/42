template <typename T>
node_set<T>::node_set() 
	:  Lchild(NULL), Rchild(NULL), Parent(NULL), color(RED)
{}

template <typename T>
node_set<T>::node_set(value_type const& src) 
	: Lchild(NULL), Rchild(NULL), Parent(NULL), data(src), color(RED)
{}

template <typename T>
node_set<T>::node_set(node_set const& src) 
	: color(src.color), data(src.data)
{
	Lchild = src.Lchild;
	Rchild = src.Rchild;
	Parent = src.Parent;
}

template <typename T>
node_set<T>&	node_set<T>::operator=(node_set const& src)
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
node_set<T>::~node_set()
{}
