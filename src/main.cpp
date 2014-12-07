#include <iostream>
#include "rs.h"

using namespace std;

template <class T>
void	dis_infos(const std::string& name)
{
	cout << name << endl;
	cout << "\tconst: " << (rs::meta::type<T>::is_const ? "true":"false") << endl;
	cout << "\tptr: " << (rs::meta::type<T>::is_pointer ? "true":"false") << endl;
	cout << "\tref: " << (rs::meta::type<T>::is_ref ? "true":"false") << endl;
	cout << "\trref: " << (rs::meta::type<T>::is_rref ? "true":"false") << endl;
	cout << endl;
}

template <class T>
void	display(T value)
{
	cout << "number: " << ((rs::meta::isNumber<T>::value) ? "true":"false") << endl;
}

class test : public rs::Singleton<test>
{
private:
	friend class rs::singleton_ptr<test>;
	test() {
		cout << "create test object" << endl;
	}
public:
	~test() {
		cout << "delete test object" << endl;
	}
	void t() {
		static int i = 0;
		cout << "Bonjour: " << i << endl;
		++i;
	}
};

int		main(void)
{
	test::singleton->t();
	dis_infos<char>("char");
	dis_infos<const char>("const char");
	dis_infos<char *>("char *");
	dis_infos<const char *>("const char *");
	dis_infos<char&>("char &");
	dis_infos<const char &>("const char &");
	dis_infos<char&&>("char &&");
	dis_infos<const char &&>("const char &&");
	display<uint16_t>(14);
	display("bonjour");
	rs::singleton_ptr<test> ptr2;
	ptr2->t();
	return (0);
}



