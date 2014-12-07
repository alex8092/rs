#ifndef RS_META_ISNUMBER_HPP
# define RS_META_ISNUMBER_HPP

# include "meta/type.hpp"
# include <cstdint>

namespace rs
{
	namespace meta
	{
		namespace _private
		{
			template <bool ptr, class T>
			struct _isNumber
			{
				static constexpr bool value = false;
			};

			template <> struct _isNumber<false, char> { static constexpr bool value = true; };
			template <> struct _isNumber<false, short> { static constexpr bool value = true; };
			template <> struct _isNumber<false, int> { static constexpr bool value = true; };
			template <> struct _isNumber<false, long> { static constexpr bool value = true; };
			template <> struct _isNumber<false, long long> { static constexpr bool value = true; };
			template <> struct _isNumber<false, unsigned char> { static constexpr bool value = true; };
			template <> struct _isNumber<false, unsigned short> { static constexpr bool value = true; };
			template <> struct _isNumber<false, unsigned int> { static constexpr bool value = true; };
			template <> struct _isNumber<false, unsigned long> { static constexpr bool value = true; };
			template <> struct _isNumber<false, unsigned long long> { static constexpr bool value = true; };
		}
		template <class T>
		struct isNumber
		{
			static constexpr bool value = _private::_isNumber<type<T>::is_pointer, typename type<T>::base_type>::value;
		};
	}
}


#endif