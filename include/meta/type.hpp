#ifndef RS_META_TYPE_HPP
# define RS_META_TYPE_HPP

namespace rs
{
	namespace meta
	{
		template <class T, bool isConst = false, bool isPointer = false, bool isRef = false, bool isRRef = false>
		struct type
		{
			typedef T base_type;
			typedef T * ptr_type;
			typedef T & ref_type;
			typedef T && rref_type;
			typedef const T const_base_type;
			typedef const T * const_ptr_type;
			typedef const T & const_ref_type;
			static constexpr bool	is_const = isConst;
			static constexpr bool	is_pointer = isPointer;
			static constexpr bool	is_ref = isRef;
			static constexpr bool	is_rref = isRRef;
		};

		template <class T>
		struct type<const T> : public type<T, true> {};

		template <class T>
		struct type<T*> : public type<T, false, true> {};
		template <class T>
		struct type<const T*> : public type<T, true, true> {};
		
		template <class T>
		struct type<T&> : public type<T, false, false, true> {};
		template <class T>
		struct type<const T&> : public type<T, true, false, true> {};

		template <class T>
		struct type<T&&> : public type<T, false, false, false, true> {};
		template <class T>
		struct type<const T&&> : public type<T, true, false, false, true> {};
	}
}

#endif