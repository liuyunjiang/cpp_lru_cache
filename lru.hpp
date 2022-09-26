#include <list>
#include <map>
#include <iostream>

template <typename K, typename V>
class LRUCache
{
	public:
		LRUCache(int max_size = 3)
			:m_max_size(max_size)
		{
		}

	public:
		int Put(const K& key, const V& value)
		{
			auto ret = 0;

			if(m_cache.size() >= m_max_size)
			{
				auto k = m_queue.back();
				m_cache.erase(k);
				m_queue.pop_back();

				ret = 1;
			}

			m_cache.insert(std::make_pair(key, value));
			m_queue.push_front(key);

			return ret;
		}

		int Get(const K& key, V& value)
		{
			auto it = m_cache.find(key);
			if(it == m_cache.end())
			{
				return -1;
			}
			value = it->second;

			m_queue.remove(key);	//slow here
			m_queue.push_front(key);

			return 0;
		}

		void Print()
		{
			for(auto k: m_queue)
			{
				std::cout << k << "\t";
			}
			std::cout << std::endl;
		}

	private:
		std::map<K, V>	m_cache;
		std::list<K>	m_queue;

		int				m_max_size;
};