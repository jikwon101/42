template <typename T>
RBTNode<T>::RBTNode() 
	:  Lchild(NULL), Rchild(NULL), Parent(NULL), color(RED)
{}

template <typename T>
RBTNode<T>::RBTNode(value_type const& src) 
	: Lchild(NULL), Rchild(NULL), Parent(NULL), data(src), color(RED)
{}

template <typename T>
RBTNode<T>::RBTNode(RBTNode const& src) 
	: color(src.color), data(src.data)
{
	Lchild = src.Lchild;
	Rchild = src.Rchild;
	Parent = src.Parent;
}

template <typename T>
RBTNode<T>&	RBTNode<T>::operator=(RBTNode const& src)
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
RBTNode<T>::~RBTNode()
{}
