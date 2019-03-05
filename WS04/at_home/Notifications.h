#ifndef SICT_NOTIFICATIONS_
#define SICT_NOTIFICATIONS_
#include <iostream>
#include "Message.h"

namespace sict {
	class Notifications {
		const Message** m_address;
		int m_maxAddress;
		int m_storedAddress;
	public:
		Notifications();
		Notifications(int);
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications& operator=(Notifications&&);
		Notifications(Notifications&&);
		Notifications& operator+=(const Message&);
		Notifications& operator-=(const Message&);
		~Notifications();
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, Notifications&);

}

#endif // !SICT_MESSAGEPACK_

