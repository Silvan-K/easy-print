#pragma once

#include <type_traits>
#include <iostream>

//////////////////////////////////////////////////////////////////////
// Instantiating these templates with some type T will automatically
// pick up the one with the correct partial template specialization
// via SFINAE. I.e. is_iterable<T>::value == true if T is iterable and
// ids_iterable<T>::value == false if T is not iterable. We consider T
// iterable if we can call std::begin/end on it.
//////////////////////////////////////////////////////////////////////

template <typename T, typename = void>
struct is_iterable : std::false_type {};

template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
				  decltype(std::end  (std::declval<T>()))>>
  : std::true_type {};

////////////////////////////////////////////////////////////////////
// Ideally we want two different plain print functions with partial
// template specialization. One for 'iterable=true' and one for
// 'iterable=false'. Since partial template specialization is not
// allowed for functions, use structs instead.
///////////////////////////////////////////////////////////////////

// Class template definition
template<typename T, bool = is_iterable<T>::value >
struct _STREPR_;

// Partial specialization for iterable=false
template<typename T>
struct _STREPR_<T, false>{
  _STREPR_(std::ostream& strm, const T& arg) {
    strm << arg;
  }
};

// Partial specialization for iterable=true
template<typename T>
struct _STREPR_<T, true>{
  _STREPR_(std::ostream& strm, const T& arg) {
    _STREPR_<std::string, false>(strm, "[");
    if(std::begin(arg) !=std::end(arg)){
      for(auto it=std::begin(arg); it!=--std::end(arg); ++it) {
	_STREPR_<decltype(*it)>(strm, *it);
	_STREPR_<std::string, false>(strm, ", ");
      }
      _STREPR_<decltype(*std::end(arg))>(strm, *(--std::end(arg)));
    }
    _STREPR_<std::string, false>(strm, "]");
  }
};

//////////////////////////////////////////////////////////////////////
// Now define a variadic template that allows an arbitrary number of
// arguments as the high-level user facing function.
//////////////////////////////////////////////////////////////////////

// End of recursion: end the line
void _DEBUG_VARS_(std::ostream& strm) {
  strm << std::endl;
}

// Recursive expansion of parameter packs
template <typename T,
	  typename... Types>
void _DEBUG_VARS_(std::ostream& strm,
		  const T& arg,
		  const Types&... args) {
  _STREPR_<T, is_iterable<T>::value>(strm, arg);
  _STREPR_<std::string, false>(strm, " ");
  _DEBUG_VARS_(strm, args...);
}  

// Finally the user-facing function
template <typename... Types>
void DEBUG_VARS(const Types&... args) {
  _DEBUG_VARS_(std::cout, args...);
}  
