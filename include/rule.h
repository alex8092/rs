#ifndef RS_RULE_H
# define RS_RULE_H

# include "meta/type.hpp"

namespace rs
{
	template <class Parent, typename ... Args>
	struct Rule
	{
		static inline bool check(Args... argv) {
			return (Parent::check(argv...));
		}
	};

}

#endif