#include "gtest/gtest.h"
#include "StringCalculator.h"
#include<string>

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
	//Arrange
	int expectedResult = 0;
	string input = "";


	//act
	 StringCalculator calculator; 
	int actualresult = calculator.Add(input);

	//assert
	ASSERT_EQ(expectedResult,actualresult);
	

}


TEST(StringCalculatorAddTests, ExpectZeroForZeroString) {
	//Arrange
	int expectedResult = 0;
	string input = "0";


	//act
	StringCalculator calculator; 
	int actualresult = calculator.Add(input);

	//assert
	ASSERT_EQ(expectedResult, actualresult);


}

TEST(StringCalculatorAddTests, ExpectOneForOne) {

	//Arrange
	int expectedResult = 1;
	string input = "1";


	//act
	StringCalculator calculator;
	int actualresult = calculator.Add(input);

	//assert
	ASSERT_EQ(expectedResult, actualresult);


	

}

TEST(StringCalculatorTests, GivenMultiple_comma_delimited_numbersSumIsExpected) {
	//Arrange
	StringCalculator obj;
	string input = "1,2,3";
	int expectedResult = 6;
	//Act
	int actual = obj.Add(input);
	//Assert
	ASSERT_EQ(expectedResult, actual);

}

