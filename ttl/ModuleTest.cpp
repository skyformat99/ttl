#include <gtest/gtest.h>

#include "include/ttl/module.h"

using ttl::module;

void testfn(){}

TEST(ModuleTest, GetModule) {
	module entry = module::entry_module();
	module calling = module::calling_module();
	module current = module::current_module();
	module fn = module::from_address((void*)&testfn);

	ASSERT_NE("", entry.get_filename());
	ASSERT_EQ(entry.get_filename(), calling.get_filename());
	ASSERT_EQ(current.get_filename(), calling.get_filename());
	ASSERT_EQ(fn.get_filename(), calling.get_filename());
}
