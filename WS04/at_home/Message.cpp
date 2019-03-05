/*
Tenzin Shedup
tshedup@myseneca.ca
120664180
*/

#include "Message.h"
#include <string>
#include <iostream>

using namespace std;
namespace sict{
	Message::Message()
	{
		m_Message = '\0';
		m_User = '\0';
		m_Reply = '\0';
		size_t reply_start = 0;
		size_t space = 0;
	}
	Message::Message(const string & str)
	{
		size_t space = 0;
		m_FullMessage = str;
		space_pos = str.find(' ');
		m_User = str.substr(space,space_pos);
		
		if (m_User.size() > 0 && m_User.size() != str.size()) {

			if (str.find('@')!= string::npos) {      // this section for reply only

				space = space_pos;
				reply_start = str.find('@', space+1);// finds the @ and then the next space
				space_pos = str.find(' ', space+1);
				m_Reply = str.substr(reply_start + 1, space_pos - reply_start); // the reciever's name

			}
			space = space_pos;
			m_Message = str.substr(space + 1, str.size());// size of message
		}

		else {
			*this = Message(); // safe state
		}
	}
	bool Message::empty() const
	{

		return (m_Message.size() < 1) ? true : false;
	}
	void Message::display(std::ostream & os) const
	{
		if (m_FullMessage.size()) {// checks if there is a msg
			os << ">User : "<< m_User << endl;
			if (m_Reply.size() > 0){                  // if there is a reply
				os << "Reply : " << m_Reply << endl;
			}
			os << "Tweet : " << m_Message << endl;
		}

	}
}

