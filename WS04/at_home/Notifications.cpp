#include "Notifications.h"
#include <iostream>

namespace sict {
	Notifications::Notifications()
		:m_address{ nullptr }, m_maxAddress{ 0 }, m_storedAddress{ 0 }
	{
	}

	Notifications::Notifications(int maxNumAgg)
	{
		if (maxNumAgg > 0) {
			m_address = new const Message*[maxNumAgg];
			m_maxAddress = maxNumAgg;
			m_storedAddress = { 0 };
		}
	}

	Notifications::Notifications(const Notifications& notifications)
	{
		*this = notifications;
	}

	Notifications& Notifications::operator=(const Notifications& notifications)
	{
		if (this != &notifications) {
			delete[] m_address; 

			m_maxAddress = notifications.m_maxAddress;
			m_storedAddress = notifications.m_storedAddress;

			for (int i = 0; i < notifications.m_storedAddress; i++) {
				m_address[i] = notifications.m_address[i];
			}
		}
		// TODO: insert return statement here
		return *this;
	}

	Notifications& Notifications::operator=(Notifications&& notifications)
	{
		if (this != &notifications) {
			m_address = notifications.m_address;
			m_maxAddress = notifications.m_maxAddress;
			m_storedAddress = notifications.m_storedAddress;


			notifications.m_address = { nullptr };
			notifications.m_maxAddress = { 0 };
			notifications.m_storedAddress = { 0 };
		}
		// TODO: insert return statement here
		return *this;
	}

	Notifications::Notifications(Notifications&& notifications)
	{
		*this = std::move(notifications);
	}

	Notifications& Notifications::operator+=(const Message& message)
	{
		bool space = m_storedAddress < m_maxAddress;

		if (!message.empty() && space) {
			m_address[m_storedAddress] = &message;
			++m_storedAddress;
		}
		// TODO: insert return statement here
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& message)
	{
		for (int i = 0; i < m_storedAddress; i++) {
			bool space_have = m_address[i] == &message;

			if (space_have) {
				m_address[i] = { nullptr };

				for (int x = i; x < m_storedAddress - 1; ++x) {
					m_address[x] = m_address[x + 1];
				}

				m_address[m_storedAddress - 1] = { nullptr };
			}
		}
		m_storedAddress--;
		// TODO: insert return statement here
		return *this;
	}


	Notifications::~Notifications()
	{
		delete[] m_address;
		m_address = { nullptr };
	}

	void Notifications::display(std::ostream & os) const
	{
		for (int i = 0; i < m_storedAddress; i++)
			(*m_address[i]).display(os);
	}

	size_t Notifications::size() const
	{
		return m_storedAddress;
	}

	std::ostream& operator<<(std::ostream& os, Notifications& notifications)
	{
		notifications.display(os);
		// TODO: insert return statement here
		return os;
	}

}