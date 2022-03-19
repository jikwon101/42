#ifndef FT_MULTISET_HPP
# define FT_MULTISET_HPP

#include <memory>
#include "../utils/traits.hpp"
#include "./ft_multiset_base.hpp"
#include "./ft_multiset_iterator.hpp"
#include "./ft_multiset_const_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft
{
	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class multiset : private multiset_base<T, Compare, Alloc>
	{
		private:
			typedef ft::multiset_base<T, Compare, Alloc>	base;
			typedef typename base::node						node;
			typedef typename base::node_pointer				node_pointer;
		public:
			typedef T			key_type;
			typedef T			value_type;
			typedef Compare		key_compare;
			typedef Compare		value_compare;
			typedef Alloc		allocator_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::multiset_iterator<value_type>			iterator;
			typedef ft::multiset_const_iterator<value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef typename iterator::difference_type		difference_type;
			
			multiset(const key_compare& comp = key_compare(),const allocator_type& = allocator_type());
			template <typename InputIt>
			multiset(InputIt first, InputIt last, const key_compare& com = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);
			multiset(const multiset& x);
			~multiset();
			multiset&			operator= (const multiset& x);
			allocator_type			get_allocator() const;
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			bool					empty() const;
			size_type				size() const;
			size_type				max_size() const;
			iterator	insert (const value_type& val);
			iterator	insert(iterator position, const value_type& val);
			template <typename InputIt>
			void		insert(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
			void		erase(iterator position);
			size_type	erase(const key_type& k);
			void		erase(iterator first, iterator last);
			void		swap(multiset& x);
			void		clear();
			key_compare					key_comp() const;
			value_compare				value_comp() const;
			iterator					find(const key_type &k);
			const_iterator				find(const key_type& k) const;
			size_type					count(const key_type& k) const;
			iterator					lower_bound(const key_type& k);
			const_iterator				lower_bound(const key_type& k) const;
			iterator					upper_bound(const key_type& k);
			const_iterator				upper_bound(const key_type& k) const;
			ft::pair<iterator, iterator>				equal_range(const key_type& k);
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const;
	};
	template <typename T, typename Compare, typename Alloc>
	bool	operator==(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs);
	template <typename T, typename Compare, typename Alloc>
	bool	operator!=(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs);
	template <typename T, typename Compare, typename Alloc>
	bool	operator<(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs);
	template <typename T, typename Compare, typename Alloc>
	bool	operator<=(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs);
	template <typename T, typename Compare, typename Alloc>
	bool	operator>(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs);
	template <typename T, typename Compare, typename Alloc>
	bool	operator>=(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs);
	#include "./src/ft_multiset2.ipp"
}
#endif
