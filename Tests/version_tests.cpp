#include <gtest/gtest.h>

// Make sure to include the header for the Version class
#include "Version.h"

TEST(VersionTest, Constructor)
{

    Version v0(1);
    EXPECT_EQ(1, v0.getMajor());
    EXPECT_EQ(0, v0.getMinor());
    EXPECT_EQ(0, v0.getPatch());

    Version v1(1, 1);
    EXPECT_EQ(1, v1.getMajor());
    EXPECT_EQ(1, v1.getMinor());
    EXPECT_EQ(0, v1.getPatch());

    Version v2( 1, 2, 3);
    EXPECT_EQ(1, v2.getMajor());
    EXPECT_EQ(2, v2.getMinor());
    EXPECT_EQ(3, v2.getPatch());
}


TEST(VersionTest, LiteralString)
{
    Version v2 = "1"_v;
    EXPECT_EQ(1, v2.getMajor());
    EXPECT_EQ(0, v2.getMinor());
    EXPECT_EQ(0, v2.getPatch());

    Version v3 = "1.2"_v;
    EXPECT_EQ(1, v3.getMajor());
    EXPECT_EQ(2, v3.getMinor());
    EXPECT_EQ(0, v3.getPatch());

    Version v4 = "1.2.3"_v;
    EXPECT_EQ(1, v4.getMajor());
    EXPECT_EQ(2, v4.getMinor());
    EXPECT_EQ(3, v4.getPatch());
}


TEST(VersionTest, LiteralFloat)
{
    Version v2 = 1_v;
    EXPECT_EQ(1, v2.getMajor());
    EXPECT_EQ(0, v2.getMinor());
    EXPECT_EQ(0, v2.getPatch());

    Version v3 = 1.2_v;
    EXPECT_EQ(1, v3.getMajor());
    EXPECT_EQ(2, v3.getMinor());
    EXPECT_EQ(0, v3.getPatch());
}

TEST(VersionTest, ComparisonOperators)
{
    Version v1 = "1.2.3"_v;
    Version v2 = "1.2.3"_v;
    Version v3 = "1.2.4"_v;
    Version v4 = "1.3.3"_v;
    Version v5 = "2.2.3"_v;

    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
    EXPECT_FALSE(v1 == v4);
    EXPECT_FALSE(v1 == v5);

    EXPECT_FALSE(v1 != v2);
    EXPECT_TRUE(v1 != v3);
    EXPECT_TRUE(v1 != v4);
    EXPECT_TRUE(v1 != v5);

    EXPECT_FALSE(v1 < v2);
    EXPECT_TRUE(v1 < v3);
    EXPECT_TRUE(v1 < v4);
    EXPECT_TRUE(v1 < v5);

    EXPECT_TRUE(v1 <= v2);
    EXPECT_TRUE(v1 <= v3);
    EXPECT_TRUE(v1 <= v4);
    EXPECT_TRUE(v1 <= v5);

    EXPECT_FALSE(v1 > v2);
    EXPECT_FALSE(v1 > v3);
    EXPECT_FALSE(v1 > v4);
    EXPECT_FALSE(v1 > v5);

    EXPECT_TRUE(v1 >= v2);
    EXPECT_FALSE(v1 >= v3);
    EXPECT_FALSE(v1 >= v4);
    EXPECT_FALSE(v1 >= v5);
}
