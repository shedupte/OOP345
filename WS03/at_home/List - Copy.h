#ifndef SICT_LIST_H
#define SICT_LIST_H

namespace sict {

	template <typename T, int N>
	class List {
		T m_list[N];
		size_t m_num = {0u};

	public:

		size_t size() const { return m_num; }

		const T& operator[](size_t i) const { return m_list[i]; }// double check reference 

		void operator+=(const T& t) { 
			if (m_num < N) {
				m_list[m_num] = t;
				m_num++;
			}
		}
	};
}

#endif // !SICT_LIST_H
#pragma once
