#include "pch.h"

#include "../MdiInjector.h"


TEST(MsvInjectorTest, MSV_INJECTOR_1_Test)
{
	MSV_INJECTOR_1(TestInjector, int, m_int_1);

	TestInjector injector(1);
	EXPECT_EQ(injector.m_int_1, 1);
}

TEST(MsvInjectorTest, MSV_INJECTOR_2_Test)
{
	 MSV_INJECTOR_2(TestInjector, int, m_int_1, int, m_int_2);

	 TestInjector injector(1, 2);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
}

TEST(MsvInjectorTest, MSV_INJECTOR_3_Test)
{
	 MSV_INJECTOR_3(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3);

	 TestInjector injector(1, 2, 3);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
}

TEST(MsvInjectorTest, MSV_INJECTOR_4_Test)
{
	 MSV_INJECTOR_4(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4);

	 TestInjector injector(1, 2, 3, 4);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
}

TEST(MsvInjectorTest, MSV_INJECTOR_5_Test)
{
	 MSV_INJECTOR_5(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5);

	 TestInjector injector(1, 2, 3, 4, 5);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
}

TEST(MsvInjectorTest, MSV_INJECTOR_6_Test)
{
	 MSV_INJECTOR_6(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6);

	 TestInjector injector(1, 2, 3, 4, 5, 6);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
}

TEST(MsvInjectorTest, MSV_INJECTOR_7_Test)
{
	 MSV_INJECTOR_7(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7);

	 TestInjector injector(1, 2, 3, 4, 5, 6, 7);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
	 EXPECT_EQ(injector.m_int_7, 7);
}

TEST(MsvInjectorTest, MSV_INJECTOR_8_Test)
{
	 MSV_INJECTOR_8(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7, int, m_int_8);

	 TestInjector injector(1, 2, 3, 4, 5, 6, 7, 8);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
	 EXPECT_EQ(injector.m_int_7, 7);
	 EXPECT_EQ(injector.m_int_8, 8);
}

TEST(MsvInjectorTest, MSV_INJECTOR_9_Test)
{
	 MSV_INJECTOR_9(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7, int, m_int_8, int, m_int_9);

	 TestInjector injector(1, 2, 3, 4, 5, 6, 7, 8, 9);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
	 EXPECT_EQ(injector.m_int_7, 7);
	 EXPECT_EQ(injector.m_int_8, 8);
	 EXPECT_EQ(injector.m_int_9, 9);
}

TEST(MsvInjectorTest, MSV_INJECTOR_10_Test)
{
	 MSV_INJECTOR_10(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7, int, m_int_8, int, m_int_9, int, m_int_10);

	 TestInjector injector(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
	 EXPECT_EQ(injector.m_int_7, 7);
	 EXPECT_EQ(injector.m_int_8, 8);
	 EXPECT_EQ(injector.m_int_9, 9);
	 EXPECT_EQ(injector.m_int_10, 10);
}

TEST(MsvInjectorTest, MSV_INJECTOR_11_Test)
{
	 MSV_INJECTOR_11(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7, int, m_int_8, int, m_int_9, int, m_int_10, int, m_int_11);

	 TestInjector injector(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
	 EXPECT_EQ(injector.m_int_7, 7);
	 EXPECT_EQ(injector.m_int_8, 8);
	 EXPECT_EQ(injector.m_int_9, 9);
	 EXPECT_EQ(injector.m_int_10, 10);
	 EXPECT_EQ(injector.m_int_11, 11);
}

TEST(MsvInjectorTest, MSV_INJECTOR_12_Test)
{
	 MSV_INJECTOR_12(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7, int, m_int_8, int, m_int_9, int, m_int_10, int, m_int_11, int, m_int_12);

	 TestInjector injector(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
	 EXPECT_EQ(injector.m_int_7, 7);
	 EXPECT_EQ(injector.m_int_8, 8);
	 EXPECT_EQ(injector.m_int_9, 9);
	 EXPECT_EQ(injector.m_int_10, 10);
	 EXPECT_EQ(injector.m_int_11, 11);
	 EXPECT_EQ(injector.m_int_12, 12);
}

TEST(MsvInjectorTest, MSV_INJECTOR_13_Test)
{
	 MSV_INJECTOR_13(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7, int, m_int_8, int, m_int_9, int, m_int_10, int, m_int_11, int, m_int_12, int, m_int_13);

	 TestInjector injector(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
	 EXPECT_EQ(injector.m_int_7, 7);
	 EXPECT_EQ(injector.m_int_8, 8);
	 EXPECT_EQ(injector.m_int_9, 9);
	 EXPECT_EQ(injector.m_int_10, 10);
	 EXPECT_EQ(injector.m_int_11, 11);
	 EXPECT_EQ(injector.m_int_12, 12);
	 EXPECT_EQ(injector.m_int_13, 13);
}

TEST(MsvInjectorTest, MSV_INJECTOR_14_Test)
{
	 MSV_INJECTOR_14(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7, int, m_int_8, int, m_int_9, int, m_int_10, int, m_int_11, int, m_int_12, int, m_int_13, int, m_int_14);

	 TestInjector injector(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
	 EXPECT_EQ(injector.m_int_1, 1);
	 EXPECT_EQ(injector.m_int_2, 2);
	 EXPECT_EQ(injector.m_int_3, 3);
	 EXPECT_EQ(injector.m_int_4, 4);
	 EXPECT_EQ(injector.m_int_5, 5);
	 EXPECT_EQ(injector.m_int_6, 6);
	 EXPECT_EQ(injector.m_int_7, 7);
	 EXPECT_EQ(injector.m_int_8, 8);
	 EXPECT_EQ(injector.m_int_9, 9);
	 EXPECT_EQ(injector.m_int_10, 10);
	 EXPECT_EQ(injector.m_int_11, 11);
	 EXPECT_EQ(injector.m_int_12, 12);
	 EXPECT_EQ(injector.m_int_13, 13);
	 EXPECT_EQ(injector.m_int_14, 14);
}

TEST(MsvInjectorTest, MSV_INJECTOR_15_Test)
{
	MSV_INJECTOR_15(TestInjector, int, m_int_1, int, m_int_2, int, m_int_3, int, m_int_4, int, m_int_5, int, m_int_6, int, m_int_7, int, m_int_8, int, m_int_9, int, m_int_10, int, m_int_11, int, m_int_12, int, m_int_13, int, m_int_14, int, m_int_15);

	TestInjector injector(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	EXPECT_EQ(injector.m_int_1, 1);
	EXPECT_EQ(injector.m_int_2, 2);
	EXPECT_EQ(injector.m_int_3, 3);
	EXPECT_EQ(injector.m_int_4, 4);
	EXPECT_EQ(injector.m_int_5, 5);
	EXPECT_EQ(injector.m_int_6, 6);
	EXPECT_EQ(injector.m_int_7, 7);
	EXPECT_EQ(injector.m_int_8, 8);
	EXPECT_EQ(injector.m_int_9, 9);
	EXPECT_EQ(injector.m_int_10, 10);
	EXPECT_EQ(injector.m_int_11, 11);
	EXPECT_EQ(injector.m_int_12, 12);
	EXPECT_EQ(injector.m_int_13, 13);
	EXPECT_EQ(injector.m_int_14, 14);
	EXPECT_EQ(injector.m_int_15, 15);
}
