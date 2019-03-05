#ifndef SICT_MESSAGEPACK_
#define SICT_MESSAGEPACK_
#include "Message.h"
#include <iostream>

namespace sict {
	class MessagePack {
		Message * m_message;
		int m_numPack;
	public:
		MessagePack();
		MessagePack(const Message **, size_t);
		MessagePack(const MessagePack&);
		MessagePack& operator= (const MessagePack&);
		MessagePack& operator=(MessagePack&&);
		MessagePack(MessagePack&&);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;
		

	};
	std::ostream& operator<<(std::ostream&, const MessagePack&);
}
#endif // !SICT_MESSAGEPACK_
