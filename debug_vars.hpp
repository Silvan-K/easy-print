#pragma once

#include <type_traits>
#include <iostream>
#include <vector>

// Use SFINAE to build a template that determines wheter a type is
// iterable or not. We consider everything iterable that can be called
// std::begin on.
template <typename T, typename = void>
struct is_iterable : std::false_type {};

template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
				  decltype(std::end  (std::declval<T>()))>>
  : std::true_type {};

template <typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;

template<typename T, bool = is_iterable_v<T> >
class _STREPR_;

template<typename T>
struct _STREPR_<T, false>{
  _STREPR_(std::ostream& strm, const T& arg) {
    strm << arg;
  }
};

template<typename T>
struct _STREPR_<T, true>{
  _STREPR_(std::ostream& strm, const T& arg) {
    strm << "[";
    if(!arg.empty()) {
      for(size_t i(0); i<arg.size()-1; i++) {
	_STREPR_<decltype(arg[i])>(strm, arg[i]);
	strm << ", ";
      }
      _STREPR_<decltype(arg.back())>(strm, arg.back());
    }
    strm << "]";
  }
};

void _DEBUG_VARS_(std::ostream& strm) {
  strm << std::endl;
}

template <typename T,
	  typename... Types>
void _DEBUG_VARS_(std::ostream& strm,
		  const T& arg,
		  const Types&... args) {
  _STREPR_<T, is_iterable_v<T>>(strm, arg);
  _STREPR_<std::string, false>(strm, " ");
  _DEBUG_VARS_(strm, args...);
}  

template <typename... Types>
void DEBUG_VARS(const Types&... args) {
  _DEBUG_VARS_(std::cout, args...);
}  
