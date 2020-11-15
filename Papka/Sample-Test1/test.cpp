#include "pch.h"
#include "../laba3last/MofINT.h"


TEST(Constructors, defaultconstructor) {
    maximka::MofINT object;

    ASSERT_EQ(0, object.getSIZE());
}
TEST(Constructors, constructor) {
    maximka::MofINT object1(5);

    ASSERT_EQ(5, object1.getSIZE());

    maximka::MofINT object2(object1);

    ASSERT_EQ(5, object2.getSIZE());

    int m[] = { 1, 2 ,3 };
    maximka::MofINT object3(3, m);

    ASSERT_EQ(3, object3.getSIZE());
    ASSERT_ANY_THROW(maximka::MofINT object4(-1));
}
TEST(operators, size) {
    int m[] = { 7, 8 ,9 };
    maximka::MofINT object1(5);
    maximka::MofINT object2(3, m);
    maximka::MofINT object3;

    object3 = object1 + object2;

    ASSERT_EQ(8, object3.getSIZE());

    object3 = object1 * object2;

    ASSERT_EQ(0, object3.getSIZE());

    object3 = object1 - object2;

    ASSERT_EQ(5, object3.getSIZE());

    int number = 10;

    object1 += number;

    ASSERT_EQ(6, object1.getSIZE());


}

TEST(operators, value) {
    int m[] = { 7, 8 ,9 };
    maximka::MofINT object1(5);
    maximka::MofINT object2(3, m);
    maximka::MofINT object3;

    object3 = object1 + object2;

    ASSERT_EQ(1, object3.getPILE(1));

    object3 = object1 * object2;

    ASSERT_ANY_THROW(object3.getPILE(1));

    object3 = object1 - object2;

    ASSERT_EQ(4, object3.getPILE(4));

    int number = 10;

    object1 += number;

    ASSERT_EQ(2, object3.getPILE(2));

    ASSERT_EQ(10, object1.getPILE(5));

}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}