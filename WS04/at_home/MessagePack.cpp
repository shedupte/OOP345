#include "MessagePack.h"

namespace sict {
	MessagePack::MessagePack()
		:m_message{ nullptr }, m_numPack{ 0 }{
	}
	MessagePack::MessagePack(const Message **message, size_t numElemArray)
	{
		if (numElemArray > 0 && message != nullptr) {// add two for loops for adding objects and taking away empties
			m_numPack = { 0 };
			m_message = new Message[numElemArray];

			for (int i = 0; i < numElemArray; ++i) {
				if (!(*message[i]).empty())
					m_message[i] = *message[i];
				else
					m_message[i] = Message();
				m_numPack++;
			}

			for (int i = 0; i < m_numPack; ++i) {
				if (m_message[i].empty())
				{
					for (int x = i; x < m_numPack - 1; ++x)
						m_message[x] = m_message[x + 1];
					m_message[m_numPack - 1] = Message();
				}
			}
			m_numPack--;
		}
	}
	MessagePack::MessagePack(const MessagePack & messagePack)
	{
		*this = messagePack;
	}
	MessagePack & MessagePack::operator=(const MessagePack & messagePack)
	{
		if (this != &messagePack) {
			delete[] m_message;
			m_numPack = messagePack.m_numPack;

			for (int i = 0; i < m_numPack; i++)
				m_message[i] = messagePack.m_message[i];
		}
		// TODO: insert return statement here

		return *this;
	}
	MessagePack & MessagePack::operator=(MessagePack && messagePack)
	{
		if (this != &messagePack) {
			m_message = messagePack.m_message;
			m_numPack = messagePack.m_numPack;

			messagePack.m_message = { nullptr };
			messagePack.m_numPack = { 0 };
		}
		// TODO: insert return statement here
		return *this;
	}
	MessagePack::MessagePack(MessagePack&& messagePack)
	{
		*this = std::move(messagePack);
	}

	MessagePack::~MessagePack()
	{
		delete[] m_message; // deallocating memory
		m_message = nullptr;
	}

	void MessagePack::display(std::ostream & os) const
	{
		for (int i = 0; i < m_numPack; i++) {
			if (!m_message[i].empty()) {
				m_message[i].display(os);
			}
		}
	}

	size_t MessagePack::size() const
	{
		return size_t(m_numPack);
	}

	std::ostream& operator<<(std::ostream& os, const MessagePack& messagePack)
	{
		messagePack.display(os);
		return os;
	}

}

