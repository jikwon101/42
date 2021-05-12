#ifndef FT_MAP_HPP
# define FT_MAP_HPP

#include <memory>
#include "../utils/function.hpp"
#include "../utils/pair.hpp"
#include "../utils/traits.hpp"
#include "./node_map.hpp"
#include "./ft_map_base.hpp"
namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::Pair<const Key, T> > >
	class map : private map_base<Key, T, Compare, Alloc>
	{
		/*
		public:
			class value_compare
			{
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type	first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y)
					{
						return (comp(x.first, y.first));
					}
			};
		*/
		public:
			typedef Key		key_type;
			typedef T		mapped_type;
			typedef Compare	key_compare;
			typedef ft::Pair<const key_type, mapped_type> value_type;
			typedef Alloc	allocator_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;	//iterator::difference
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;


		private:
			typedef ft::map_base<Key, T, Compare, Alloc> base;
			typedef typename base::node			node;
			typedef typename base::node_pointer	node_pointer;
			
		public:
			map(const key_compare& comp = key_compare(),const allocator_type& = allocator_type());
			mapped_type& operator[] (const key_type& k);
			/* capacity */
			bool	empty() const;
			size_type	size() const;
			size_type	max_size() const;
			/* modify */
			//ft::pair<iterator, bool> insert (Const value_type& val);
			void	insert (const value_type& val); //temp

			/*observers */
			//key_compare	key_comp() const;
			//value_compare	value_comp() const;
			/* operation */
			//iterator	find(const key_type &k);
			//const_iterator	find(const key_type& k) const;
			//size_type		count(const key_type& k) const;
			//iterator		lower_bound(const key_type& k);
			//const_iterator		lower_bound(const key_type& k) const;
			//iterator		upper_bound(const key_type& k);
			//const_iterator		upper_bound(const key_type& k) const;
			//pair<iterator, iterator>	equal_range(const key_type& k);
			//pair<const_iterator, const_iterator>	equal_range(const key_type& k) const;


	};
	#include "ft_map2.ipp"
}
#endif
