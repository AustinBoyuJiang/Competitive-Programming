#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	template<typename V_forward>
	interval_map(V_forward&& val)
	: m_valBegin(std::forward<V_forward>(val))
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	template<typename V_forward>
	void assign( K const& keyBegin, K const& keyEnd, V_forward&& val )
//		requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
	{
		if(!(keyBegin<keyEnd)) return;
		auto it=m_map.lower_bound(keyBegin);
		V old_val=m_valBegin;
		if(it!=m_map.begin()){
			old_val=std::prev(it)->second;
		}
		if(val!=old_val){
			if(it!=m_map.end()&&!(keyBegin<(it->first))){
				old_val=it->second;
				it->second=std::forward<V_forward>(val);
				it++;
			}
			else{
				m_map.insert(it,{keyBegin,std::forward<V_forward>(val)});
			}
		}
		while(it!=m_map.end()&&!(keyEnd<(it->first))){
			old_val=it->second;
			it=m_map.erase(it);
		}
		if(val!=old_val){
			m_map.insert(it,{keyEnd,old_val});
		}

	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
