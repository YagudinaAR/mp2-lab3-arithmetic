#include <gtest.h>
#include "arithmetic.h"

TEST(arithmetic, can_input_multi_digit)
{
	char s[] = "4-200";
	int i = 0;
	bool flag=false;
	while (s[i] != '\0')
	{
		if ((isalpha(s[i])) && (isalpha(s[i + 1])))
		{
			flag = true;
			break;
		}

		i++;
	}
	EXPECT_TRUE(flag);
}

TEST(arithmetic, can_input_negative_digit)
{
	char s[] = "150 + (-3)";
	int i = 0;
	bool flag = false;
	if (s[0] == '-' && isalpha(s[1]))
		flag = true;
	while (s[i] != '\0')
	{
		if (s[i] == '(' && s[i + 1] == '-' && isalpha(s[i + 2]))
		{
			flag = true;
			break;
		}
		i++;
	}
	EXPECT_TRUE(flag);
}

TEST(arithmetic, can_input_negative_multi_digit)
{
	char s[] = "150 + (-32)";
	int i = 0;
	bool flag = false;
	if (s[0] == '-' && isalpha(s[1]) && isalpha(s[2]))
		flag = true;
	while (s[i] != '\0')
	{
		if (s[i] == '(' && s[i + 1] == '-' && isalpha(s[i + 2]) && isalpha(s[i + 3]))
		{
			flag = true;
			break;
		}
		i++;
	}
	EXPECT_TRUE(flag);
}

TEST(arithmetic, throws_then_input_too_large_digit)
{
	char s[] = "10000000+34";
	char s1[8] = { 0 };
	ASSERT_ANY_THROW(isdigit(0,s,s1));
}

TEST(arithmetic,can_add_digits)
{
	char s[] = "202+303";
	char s2[20] = { 0 };
	opn(s,s2);
	double res=result(s2);
	EXPECT_EQ(505, res);
}
TEST(arithmetic, can_subtract_digits)
{
	char s[] = "10-2";
	char s2[20] = { 0 };
	opn(s, s2);
	double res = result(s2);
	EXPECT_EQ(8, res);
}

TEST(arithmetic, can_multiply_digits)
{
	char s[] = "12*11";
	char s2[10] = { 0 };
	opn(s, s2);
	double res = result(s2);
	EXPECT_EQ(132, res);
}


TEST(arithmetic, can_divide_digits)
{
	char s[] = "1000/25";
	char s2[20] = { 0 };
	opn(s, s2);
	double res = result(s2);
	EXPECT_EQ(40, res);
}

TEST(arithmetic, can_to_the_extent)
{
	char s[] = "5^3";
	char s1[10] = {};
	opn(s, s1);
	double res = result(s1);
	EXPECT_EQ(125,res);
}

TEST(arithmetic, can_to_a_negative_degree)
{
	char s[] = "10^(-3)";
	char s1[10] = { 0 };
	opn(s, s1);
	double res = result(s1);
	EXPECT_EQ(0.001,res);
}

TEST(arithmetic, throws_then_division_by_zero)
{
	char s[] = "10/0";
	char s1[10] = { 0 };
	opn(s, s1);
	ASSERT_ANY_THROW(result(s1));
}

TEST(arithmetic, throws_then_incorrect_input)
{
	char s[] = "+32-432-";
	ASSERT_ANY_THROW(correct(s));
}

TEST(arithmetic, throws_then_incorrect_input_brackets)
{
	char s[] = ")23-43+()";
	ASSERT_ANY_THROW(check_brackets(s));
}

TEST(arithmetic, can_calculate_expression_without_brackets)
{
	char s[] = "20+45-50*2";
	char s1[30] = { 0 };
	opn(s, s1);
	double res = result(s1);
	EXPECT_EQ(-35, res);
}

TEST(arithmetic, can_calculate_expression_with_brackets)
{
	char s[] = "(20+45)-50*(-2+4)";
	char s1[30] = { 0 };
	opn(s, s1);
	double res = result(s1);
	EXPECT_EQ(-35, res);
}