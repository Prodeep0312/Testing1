#include "StringCalci.h"
#include <gtest/gtest.h>

class StringCalculatorAddTestSuiteFixture :public testing::Test {

public:
    //Execute Before All TestCases
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() { }
protected:

    //Execute After All TestCases
    StringCalculator objUnderTest;
    // You can define per-test set-up logic as usual.
    //Execute Before Each TestCase
    void SetUp() {  }

    // You can define per-test tear-down logic as usual.
    //Execute After Each TestCase
    void TearDown() { }


};


TEST_F(StringCalculatorAddTestSuiteFixture, ReturnsZeroForEmptyString) {
    //Arrange
    //Setup();
    int expectedValue = 0;
    string input = "";
    //Act
    int actualVaue = objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualVaue, expectedValue);
    //TearDown();
}
TEST_F(StringCalculatorAddTestSuiteFixture, ReturnsZeroForZero) {
    //Arrange
    int expectedValue = 0;
    string input = "0";
    //Act
    int actualVaue = objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualVaue, expectedValue);
}
TEST(StringCalculatorAddTestSuite, ReturnsSameValurForSinglDigitInputValue) {
    //Arrange
    StringCalculator objUnderTest;
    int expectedValue = 1;
    string input = "1";
    //Act
    int actualVaue = objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualVaue, expectedValue);
}

struct Parameter {
    string input;
    int expectedResult;
};

class StringCalculatorAddValueParameterizedTestFixture :
    public StringCalculatorAddTestSuiteFixture,
    public testing::WithParamInterface<Parameter> {


};

Parameter createParameter(string inputArg, int erValue) {
    struct Parameter paramObj = { inputArg,erValue };
    return paramObj;
}

//value Generator
INSTANTIATE_TEST_SUITE_P(DataDrivenTest1,
    StringCalculatorAddValueParameterizedTestFixture,
    testing::Values(
        createParameter("", 0),
        createParameter("0", 0),
        createParameter("1", 1),
        createParameter("1,2", 3)
    )
);
INSTANTIATE_TEST_SUITE_P(DataDrivenTest2,
    StringCalculatorAddValueParameterizedTestFixture,
    testing::Values(
        createParameter("1,2,3", 6)
    )
);

TEST_P(StringCalculatorAddValueParameterizedTestFixture, AssertAll) {
    //Arrange
    string input = GetParam().input;
    int expectedResult = GetParam().expectedResult;
    //Act
    int actualResult = objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualResult, expectedResult);
}




