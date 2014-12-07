#ifndef RS_SINGLETON_PTR_HPP
# define RS_SINGLETON_PTR_HPP

# include "meta/type.hpp"
# include <iostream>

namespace rs
{
	template <class T>
	class singleton_ptr;

	template <class T>
	class guardian_singleton_ptr {
	public:
		typename rs::meta::type<T>::ptr_type _singleton = nullptr;
		inline guardian_singleton_ptr() noexcept = default;
		inline ~guardian_singleton_ptr() noexcept {
			if (this->_singleton != nullptr)
				delete this->_singleton;
			this->_singleton = nullptr;
		}
	};

	template <class T>
	class singleton_ptr
	{
	private:
		static guardian_singleton_ptr<T>	_guardian;
		singleton_ptr(const singleton_ptr&) = delete;
		singleton_ptr(singleton_ptr&&) = delete;
		singleton_ptr<T>& operator=(const singleton_ptr&) = delete;
		singleton_ptr<T>& operator=(singleton_ptr&&) = delete;

	public:
		inline singleton_ptr() noexcept {
			if(singleton_ptr<T>::_guardian._singleton == nullptr)
				singleton_ptr<T>::_guardian._singleton = new typename rs::meta::type<T>::base_type();
		}
		inline ~singleton_ptr() noexcept = default;
		inline typename rs::meta::type<T>::ptr_type operator->() noexcept { return (singleton_ptr<T>::_guardian._singleton); }
	};

	template <class T>
	guardian_singleton_ptr<T>	singleton_ptr<T>::_guardian;
}

#endif