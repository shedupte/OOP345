#ifndef _SICT_KVLIST_H
#define _SICT_KVLIST_H

namespace sict {
	template<class T>
	class KVList {
		T* m_list;
		int m_numList;
		int m_storedNumList;
	public:
		KVList()
			:m_list{ nullptr }, m_numList{ 0 }, m_storedNumList{ 0 }
		{
		}

		KVList(int n) {
			if (n > 0) {
				m_numList = { n };
				m_storedNumList = { 0 };
				m_list = new T[n];
			}
			else {
				m_list = {};
				m_numList = {};
				m_storedNumList = {};
				throw "Error: The number of elements received in the constructor is not positive-vlaued";
			}
		}

		KVList(KVList&& other) {
			if (this != &other) {
				m_list = other.m_list;
				m_numList = other.m_numList;
				m_storedNumList = other.m_storedNumList;

				other.m_list = { nullptr };
				other.m_numList = { 0 };
				other.m_storedNumList;
			}
		}
		~KVList() {
			delete[] m_list;
			m_list = { nullptr };
		}

		const T& operator[](size_t i) const {
			if (i > m_numList)
				throw "Error: The index passed to the subscripting operator is out-of-bounds";
			return m_list[i];
		}

		template<typename F>
		void display(std::ostream& os, F f) const {
			for (int i = 0; i < m_numList; i++)
				m_list[i].display(os, f);
		}

		void push_back(const T& t) {
			if (m_storedNumList + 1 <= m_numList) {
				m_list[m_storedNumList] = t;

				++m_storedNumList;
			}
		}

		KVList(const KVList&) = delete;
		KVList& operator=(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
	};
}

#endif // !_SICT_KVLIST_H
#pragma once
