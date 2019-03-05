#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>
#include <string>

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

		virtual void display(ostream& os) const {
			os << m_label << " : " << m_value << endl;
		}
	};

	template <typename L, typename V>
	ostream& operator<<(ostream&os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair < L, V> {

		static V m_intValue;
		static size_t m_minWidth;
	public:
		SummableLVPair() {};
		SummableLVPair(const L& label, const V& v)  // overloaded constructor calls the base class 2 arguments
			:LVPair<L, V> (label, v){
			if (m_minWidth < label.size()) {
				m_minWidth = label.size() + 1;
			}
		}

		const V& getInitialValue()
	};


}
#endif // !SICT_LVPAIR_H
#pragma once
