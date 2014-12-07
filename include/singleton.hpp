#ifndef RS_SINGLETON_HPP
# define RS_SINGLETON_HPP

# include "singleton_ptr.hpp"

namespace rs
{
	template <class T>
	class Singleton
	{
	public:
		static singleton_ptr<T>	singleton;
	};

	template <class T>
	singleton_ptr<T> Singleton<T>::singleton;
}

#endif