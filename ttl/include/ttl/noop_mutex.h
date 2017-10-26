#pragma once

namespace thalhammer {
	// A type that complies to Lockable concept but does nothing (i.e. no overhead if no synchronization is needed)
	// http://www.cplusplus.com/reference/concept/Lockable/
	class noop_mutex {
	public:
		void lock() {}
		void unlock() {}
		bool try_lock() { return true; }
	};
}
