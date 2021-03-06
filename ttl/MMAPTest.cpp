#include <gtest/gtest.h>

#include "include/ttl/mmap.h"

using namespace ttl;

TEST(MMAPTest, MapFile) {
	const std::string data = "Hello World, how are you ?";

	ttl::mmap map;

	ASSERT_EQ(nullptr, map.data());
	ASSERT_FALSE(map.is_valid());
	ASSERT_TRUE(map.open("test_data/mmap_test.txt"));
	ASSERT_TRUE(map.is_valid());
	ASSERT_NE(nullptr, map.data());
	ASSERT_EQ(map.data(), &map[0]);
	ASSERT_EQ(map.data(), &map.at(0));
	ASSERT_EQ(data.size(), map.size());
	ASSERT_TRUE(memcmp(data.data(), map.data(), map.size()) == 0);
}

TEST(MMAPTest, MapFileFailed) {
	ttl::mmap map;

	ASSERT_EQ(nullptr, map.data());
	ASSERT_FALSE(map.is_valid());
	ASSERT_FALSE(map.open("test_data/mmap_test_not_existent.txt"));
	ASSERT_FALSE(map.is_valid());
	ASSERT_EQ(nullptr, map.data());
}

TEST(MMAPTest, MapFileConstructor) {
	const std::string data = "Hello World, how are you ?";

	ASSERT_THROW([]() {
		ttl::mmap map("test_data/mmap_test_not_existent.txt");
	}(), std::runtime_error);

	ttl::mmap map("test_data/mmap_test.txt");
	ASSERT_TRUE(map.is_valid());
	ASSERT_NE(nullptr, map.data());
	ASSERT_EQ(map.data(), &map[0]);
	ASSERT_EQ(map.data(), &map.at(0));
	ASSERT_EQ(data.size(), map.size());
	ASSERT_TRUE(memcmp(data.data(), map.data(), map.size()) == 0);
}