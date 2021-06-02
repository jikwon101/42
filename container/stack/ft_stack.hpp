#ifndef FT_STACK_HPP
# define FT_STACK_HPP

#include "../list/ft_list.hpp"
#include "../vector/ft_vector.hpp"

namespace ft
{
	template <typename T, typename Container = ft::list<T> >
	class stack
	{
		template <typename U, typename CNTR>
		friend bool operator==(const stack<U, CNTR>& lhs, const stack<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator!=(const stack<U, CNTR>& lhs, const stack<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator<(const stack<U, CNTR>& lhs, const stack<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator<=(const stack<U, CNTR>& lhs, const stack<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator>(const stack<U, CNTR>& lhs, const stack<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator>=(const stack<U, CNTR>& lhs, const stack<U, CNTR>& rhs);
		public:
			typedef Container	container_type;
			typedef typename container_type::value_type		value_type;
			typedef typename container_type::size_type		size_type;
			typedef typename container_type::reference		reference;
			typedef typename container_type::const_reference	const_reference;
			
		protected:
			container_type	c;
		public:
			explicit stack(const container_type& cntr = container_type());
			~stack();
			stack&				operator=(const stack& other);
			bool				empty() const;
			size_type			size() const;
			value_type&			top();
			const value_type&	top() const;
			void				push(const value_type& val);
			void				pop();

	};
	template <typename T, typename Container>
	bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	#include "./src/ft_stack2.ipp"
}
#endif
