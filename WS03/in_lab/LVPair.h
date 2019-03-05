#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>

using namespace std;
namespace sict {
	
	template <typename L, typename V>
	class LVPair {

		L m_label;
		V m_value;

	public:
		LVPair()
			: m_label{}, m_value{}
		{

		}

		LVPair(const L& label, const V& value)
			: m_label(label)
			, m_value(value)
		{
		
		}

		void display(ostream& os) const {
			os << m_label << " : " << m_value << endl;
		}
	};

	template <typename L, typename V>
	ostream& operator<<(ostream&os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}



}
#endif // !SICT_LVPAIR_H
#pragma once
