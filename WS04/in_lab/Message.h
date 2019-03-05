/*
Tenzin Shedup
tshedup@myseneca.ca
120664180
*/


#ifndef SICT_MESSAGE_H_
#define SICT_MESSAGE_H_
#include <string>


using namespace std;

namespace sict {
	class Message {
		string m_FullMessage;
		string m_Message;
		string m_User;
		string m_Reply;
		size_t reply_start;
		size_t reply_end;
		size_t space_pos;

	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}
#endif // !SICT_MESSAGE_H
