template <typename T>
node_map<T>::node_map() 
	:  Lchild(NULL), Rchild(NULL), Parent(NULL), color(RED)
{}

template <typename T>
node_map<T>::node_map(value_type const& src) 
	: Lchild(NULL), Rchild(NULL), Parent(NULL), data(src), color(RED)
{}

template <typename T>
node_map<T>::node_map(node_map const& src) 
	: color(src.color), data(src.data)
{
	Lchild = src.Lchild;
	Rchild = src.Rchild;
	Parent = src.Parent;
}

template <typename T>
node_map<T>&	node_map<T>::operator=(node_map const& src)
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
node_map<T>::~node_map()
{}
