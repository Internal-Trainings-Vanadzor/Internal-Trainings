FUSED_GTEST_DIR = NN_gtest_lib
FUSED_GTEST_H = $(FUSED_GTEST_DIR)/gtest/gtest.h
FUSED_GTEST_ALL_CC = $(FUSED_GTEST_DIR)/gtest/gtest-all.cc

list: list.o
	@g++ $^ -o $@

test: list_unittest
		./list_unittest

$(FUSED_GTEST_H) :
	../fuse_gtest_files.py $(FUSED_GTEST_DIR)

$(FUSED_GTEST_ALL_CC) :
	../fuse_gtest_files.py $(FUSED_GTEST_DIR)

list.o: custom_list.cpp custom_list.h
	@g++ -c $< -o $@

list_unittest.o: custom_list_gtest.cpp custom_list.h
	@g++ -c $< -o $@

list_unittest : list.o list_unittest.o gtest-all.o gtest_main.o
	@g++ -c -I$(FUSED_GTEST_DIR) -DGTEST_HAS_PTHREAD=0 $^ -o $a

clean:
	rm *.o list
