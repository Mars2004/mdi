#include "pch.h"

//#define MSV_INTERFACE_POINTER(msvIFaceName) msvIFaceName*
//#define MSV_INTERFACE_CREATE(msvIFaceName, msvIFaceCreate) msvIFaceCreate
#include "../MdiFactory.h"

MSV_DISABLE_ALL_WARNINGS

#include <memory>

MSV_ENABLE_WARNINGS


namespace MsvFactoryTestNamespace
{
	class ITestObject
	{
	public:
		virtual ~ITestObject() {  }
	};

	class TestObject0: public ITestObject { public: TestObject0() {} };
	class TestObject1: public ITestObject { public: TestObject1(int int1): m_int1(int1) {} int m_int1; };
	class TestObject2: public ITestObject { public: TestObject2(int int1, int int2): m_int1(int1), m_int2(int2) {} int m_int1; int m_int2; };
	class TestObject3: public ITestObject { public: TestObject3(int int1, int int2, int int3): m_int1(int1), m_int2(int2), m_int3(int3) {} int m_int1; int m_int2; int m_int3; };
	class TestObject4: public ITestObject { public: TestObject4(int int1, int int2, int int3, int int4): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4) {} int m_int1; int m_int2; int m_int3; int m_int4; };
	class TestObject5: public ITestObject { public: TestObject5(int int1, int int2, int int3, int int4, int int5): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; };
	class TestObject6: public ITestObject { public: TestObject6(int int1, int int2, int int3, int int4, int int5, int int6): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; };
	class TestObject7: public ITestObject { public: TestObject7(int int1, int int2, int int3, int int4, int int5, int int6, int int7): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6), m_int7(int7) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; int m_int7; };
	class TestObject8: public ITestObject { public: TestObject8(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6), m_int7(int7), m_int8(int8) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; int m_int7; int m_int8; };
	class TestObject9: public ITestObject { public: TestObject9(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8, int int9): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6), m_int7(int7), m_int8(int8), m_int9(int9) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; int m_int7; int m_int8; int m_int9; };
	class TestObject10: public ITestObject { public: TestObject10(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8, int int9, int int10): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6), m_int7(int7), m_int8(int8), m_int9(int9), m_int10(int10) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; int m_int7; int m_int8; int m_int9; int m_int10; };
}

class ITestObject
{
public:
	virtual ~ITestObject() {  }
};

class TestObject0: public ITestObject { public: TestObject0() {} };
class TestObject1: public ITestObject { public: TestObject1(int int1): m_int1(int1) {} int m_int1; };
class TestObject2: public ITestObject { public: TestObject2(int int1, int int2): m_int1(int1), m_int2(int2) {} int m_int1; int m_int2; };
class TestObject3: public ITestObject { public: TestObject3(int int1, int int2, int int3): m_int1(int1), m_int2(int2), m_int3(int3) {} int m_int1; int m_int2; int m_int3; };
class TestObject4: public ITestObject { public: TestObject4(int int1, int int2, int int3, int int4): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4) {} int m_int1; int m_int2; int m_int3; int m_int4; };
class TestObject5: public ITestObject { public: TestObject5(int int1, int int2, int int3, int int4, int int5): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; };
class TestObject6: public ITestObject { public: TestObject6(int int1, int int2, int int3, int int4, int int5, int int6): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; };
class TestObject7: public ITestObject { public: TestObject7(int int1, int int2, int int3, int int4, int int5, int int6, int int7): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6), m_int7(int7) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; int m_int7; };
class TestObject8: public ITestObject { public: TestObject8(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6), m_int7(int7), m_int8(int8) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; int m_int7; int m_int8; };
class TestObject9: public ITestObject { public: TestObject9(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8, int int9): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6), m_int7(int7), m_int8(int8), m_int9(int9) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; int m_int7; int m_int8; int m_int9; };
class TestObject10: public ITestObject { public: TestObject10(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8, int int9, int int10): m_int1(int1), m_int2(int2), m_int3(int3), m_int4(int4), m_int5(int5), m_int6(int6), m_int7(int7), m_int8(int8), m_int9(int9), m_int10(int10) {} int m_int1; int m_int2; int m_int3; int m_int4; int m_int5; int m_int6; int m_int7; int m_int8; int m_int9; int m_int10; };


TEST(MsvFactoryTest, MsvEmptyFactoryCanBeCreated)
{
	MSV_FACTORY_START(TestFactory)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_0_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_0(ITestObject, TestObject0)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject());
	
	EXPECT_TRUE(spTestObject != nullptr);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_0_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_0(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject0)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject());

	EXPECT_TRUE(spTestObject != nullptr);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_1_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_1(ITestObject, TestObject1, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1));
	
	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject1> spRealTestObject(std::static_pointer_cast<TestObject1>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_1_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_1(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject1, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject1> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject1>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_2_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_2(ITestObject, TestObject2, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2));
	
	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject2> spRealTestObject(std::static_pointer_cast<TestObject2>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_2_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_2(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject2, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject2> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject2>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_3_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_3(ITestObject, TestObject3, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3));
	
	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject3> spRealTestObject(std::static_pointer_cast<TestObject3>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_3_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_3(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject3, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject3> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject3>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_4_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_4(ITestObject, TestObject4, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4));
	
	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject4> spRealTestObject(std::static_pointer_cast<TestObject4>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_4_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_4(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject4, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject4> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject4>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_5_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_5(ITestObject, TestObject5, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5));
	
	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject5> spRealTestObject(std::static_pointer_cast<TestObject5>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_5_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_5(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject5, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject5> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject5>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_6_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_6(ITestObject, TestObject6, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject6> spRealTestObject(std::static_pointer_cast<TestObject6>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_6_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_6(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject6, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject6> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject6>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_7_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_7(ITestObject, TestObject7, int, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6, 7));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject7> spRealTestObject(std::static_pointer_cast<TestObject7>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
	EXPECT_EQ(spRealTestObject->m_int7, 7);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_7_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_7(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject7, int, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6, 7));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject7> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject7>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
	EXPECT_EQ(spRealTestObject->m_int7, 7);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_8_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_8(ITestObject, TestObject8, int, int, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6, 7, 8));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject8> spRealTestObject(std::static_pointer_cast<TestObject8>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
	EXPECT_EQ(spRealTestObject->m_int7, 7);
	EXPECT_EQ(spRealTestObject->m_int8, 8);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_8_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_8(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject8, int, int, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6, 7, 8));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject8> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject8>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
	EXPECT_EQ(spRealTestObject->m_int7, 7);
	EXPECT_EQ(spRealTestObject->m_int8, 8);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_9_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_9(ITestObject, TestObject9, int, int, int, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6, 7, 8, 9));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject9> spRealTestObject(std::static_pointer_cast<TestObject9>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
	EXPECT_EQ(spRealTestObject->m_int7, 7);
	EXPECT_EQ(spRealTestObject->m_int8, 8);
	EXPECT_EQ(spRealTestObject->m_int9, 9);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_9_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_9(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject9, int, int, int, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6, 7, 8, 9));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject9> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject9>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
	EXPECT_EQ(spRealTestObject->m_int7, 7);
	EXPECT_EQ(spRealTestObject->m_int8, 8);
	EXPECT_EQ(spRealTestObject->m_int9, 9);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_10_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_10(ITestObject, TestObject10, int, int, int, int, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<TestObject10> spRealTestObject(std::static_pointer_cast<TestObject10>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
	EXPECT_EQ(spRealTestObject->m_int7, 7);
	EXPECT_EQ(spRealTestObject->m_int8, 8);
	EXPECT_EQ(spRealTestObject->m_int9, 9);
	EXPECT_EQ(spRealTestObject->m_int10, 10);
}

TEST(MsvFactoryTest, MSV_FACTORY_GET_WITH_NAMESPACE_10_ReturnsValidPointers)
{
	MSV_FACTORY_START(TestFactory)
		MSV_FACTORY_GET_WITH_NAMESPACE_10(MsvFactoryTestNamespace, ITestObject, MsvFactoryTestNamespace::TestObject10, int, int, int, int, int, int, int, int, int, int)
	MSV_FACTORY_END

	std::shared_ptr<TestFactory> spTestFactory(TestFactory::Get());
	std::shared_ptr<MsvFactoryTestNamespace::ITestObject> spTestObject(spTestFactory->GetITestObject(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

	EXPECT_TRUE(spTestObject != nullptr);
	std::shared_ptr<MsvFactoryTestNamespace::TestObject10> spRealTestObject(std::static_pointer_cast<MsvFactoryTestNamespace::TestObject10>(spTestObject));
	EXPECT_EQ(spRealTestObject->m_int1, 1);
	EXPECT_EQ(spRealTestObject->m_int2, 2);
	EXPECT_EQ(spRealTestObject->m_int3, 3);
	EXPECT_EQ(spRealTestObject->m_int4, 4);
	EXPECT_EQ(spRealTestObject->m_int5, 5);
	EXPECT_EQ(spRealTestObject->m_int6, 6);
	EXPECT_EQ(spRealTestObject->m_int7, 7);
	EXPECT_EQ(spRealTestObject->m_int8, 8);
	EXPECT_EQ(spRealTestObject->m_int9, 9);
	EXPECT_EQ(spRealTestObject->m_int10, 10);
}
