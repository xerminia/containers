#include <gtest/gtest.h>

#include <array>
#include <list>
#include <queue>
#include <stack>

#include "s21_containers.h"
#include "s21_containersplus.h"
#include "test_array.inc"
#include "test_btree.inc"
#include "test_list.inc"
#include "test_map.inc"
#include "test_multiset.inc"
#include "test_queue.inc"
#include "test_set.inc"
#include "test_stack.inc"
#include "test_vector.inc"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
