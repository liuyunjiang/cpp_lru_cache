#include <string>
#include "lru.hpp"

int main()
{
	LRUCache<int, std::string> cache(4);
	cache.Put(1, "one");
	cache.Put(2, "two");
	cache.Put(3, "three");
	cache.Print();

	std::string v;
	auto ret = cache.Get(2, v);
	cache.Print();

	cache.Put(4, "four");
	cache.Print();

	ret = cache.Get(1, v);
	cache.Print();

	cache.Put(5, "five");
	cache.Print();

	return 0;
}