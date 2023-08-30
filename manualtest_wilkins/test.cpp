#include "pch.h"
#include "class.h"

TEST(GetDataNumTest, DataIsConst) {
#if TT_TEST_GET_DATA_NUM_WHEN_CONST;
	const DoublyLinkedList list;
	EXPECT_EQ(0, list.getSize());
#endif TT_TEST_GET_DATA_NUM_WHEN_CONST;
	SUCCEED();
}
TEST(DataInsertion, DataIsNonConst) {
#if defined TT_TEST_GET_DATA_NUM_WHEN_NOT_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.begin();
	list.insert(it, 1, "name1");
#endif TT_TEST_GET_DATA_NUM_WHEN_NOT_CONST
	SUCCEED();
}