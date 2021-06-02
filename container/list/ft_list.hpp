#ifndef LIST_HPP
# define LIST_HPP

#include "./ft_list_base.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class list : private list_base<T, Alloc>
	{
		private:
			typedef list_base<T, Alloc>				base;
			typedef typename base::node				node;
			typedef typename base::node_pointer		node_pointer;
		public:
			typedef Alloc							alloc_type;
			typedef typename base::value_type		value_type;
			typedef typename base::reference		reference;
			typedef typename base::const_reference	const_reference;
			typedef typename base::pointer			pointer;
			typedef typename base::const_pointer	coonst_pointer;
			typedef typename base::size_type		size_type;
			typedef typename base::difference_type	difference_type;
			typedef ft::list_iterator<T>			iterator;
			typedef ft::list_const_iterator<T>		const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		public:
			explicit list(const alloc_type& alloc = alloc_type());
			explicit list(size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type());
			list(const list& src);
			template <typename InputIt>
			list(InputIt first, InputIt last, const alloc_type& alloc = alloc_type(), typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
			~list();
			list& operator=(const list& src);
			alloc_type		get_allocator() const;
			/* iterator */
			iterator				begin();
			const_iterator			begin() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			/* access element */
			reference				front();
			const_reference 		front() const;
			reference				back();
			const_reference 		back() const;
			/* capacity */
			bool			empty() const;
			size_type		size() const;
			size_type		max_size() const;
			/* modify */
			void		assign(size_type n, const value_type& val);
			template <typename InputIt>
			void		assign(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
			void		clear();
			iterator	erase(iterator position);
			iterator	erase(iterator first, iterator last);
			void		push_front(const value_type& val);
			void		push_back(const value_type& val);
			void		pop_front();
			void		pop_back();
			void		swap(list& x);
			void		resize(size_type n, value_type val = value_type());
			iterator	insert(iterator position, const value_type& val);
			void		insert(iterator position, size_type n, const value_type& val);
			template <typename InputIt>
			void		insert(iterator position, InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
			/* operation */
			void		reverse();
			void		splice(iterator position, list& x);
			void		splice(iterator position, list& x, iterator i);
			void		splice(iterator position, list& x, iterator first, iterator second);
			void		remove(const value_type& val);
			template <typename Predicate>
			void		remove_if(Predicate pred);
			void		unique();
			template <typename BinaryPredicate>
			void		unique(BinaryPredicate binary_pred);
			void		merge(list& x);
			template <typename Compare>
			void		merge(list& x, Compare comp);
			void		sort();
			template <typename Compare>
			void		sort(Compare comp);
	};
	template <typename T, typename Alloc>
	void	swap(list<T, Alloc> &x, list<T, Alloc> &y);
	template <typename T, typename Alloc>
	void	swap(list<T, Alloc> &x, list<T, Alloc> &y);
	template <typename T, typename Alloc>
	bool	operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);

	#include "./src/ft_list2.ipp"
}

#endif
