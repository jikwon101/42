#ifndef FT_QUEUE_HPP
# define FT_QUEUE_HPP

#include "../list/ft_list.hpp"

namespace ft
{
	template <typename T, typename Container = ft::list<T> >
	class queue
	{
		template <typename U, typename CNTR>
		friend bool operator==(const queue<U, CNTR>& lhs, const queue<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator!=(const queue<U, CNTR>& lhs, const queue<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator<(const queue<U, CNTR>& lhs, const queue<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator<=(const queue<U, CNTR>& lhs, const queue<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator>(const queue<U, CNTR>& lhs, const queue<U, CNTR>& rhs);
		template <typename U, typename CNTR>
		friend bool operator>=(const queue<U, CNTR>& lhs, const queue<U, CNTR>& rhs);
		public:
			typedef Container	container_type;
			typedef typename container_type::value_type		value_type;
			typedef typename container_type::size_type		size_type;
			typedef typename container_type::reference		reference;
			typedef typename container_type::const_reference	const_reference;
			
		protected:
			container_type	c;
		public:
			explicit queue(const container_type& cntr = container_type());
			~queue();
			queue&				operator=(const queue& other);
			bool				empty() const;
			size_type			size() const;
			value_type&			front();
			const value_type&	front() const;
			value_type&			back();
			const value_type&	back() const;
			void				push(const value_type& val);
			void				pop();

	};
	template <typename T, typename Container>
	bool	operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <typename T, typename Container>
	bool	operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	#include "./src/ft_queue2.ipp"
}
#endif
