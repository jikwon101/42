#ifndef ITER_CATEGORY_HPP
# define ITER_CATEGORY_HPP


namespace ft
{

/*
   Empty class to identify the category of an iterator
*/

struct forward_iterator_tag {};

struct bidirectional_iterator_tag : public forward_iterator_tag {};

struct random_access_iterator_tag : public bidirectional_iterator_tag {};

}
#endif
