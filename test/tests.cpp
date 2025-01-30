#include <gtest/gtest.h>

extern "C" {
#include "main.h"
}

/*******************************************************************************
 * Fixtures
 ******************************************************************************/
class MathFixture : public ::testing::Test {
	protected:
		void SetUp() override {
			/*printf("Running setup code\n");*/
		}

		void TearDown() override {
			/*printf("Running teardown code\n");*/
		}
};

class TEEFixture : public ::testing::Test {
	protected:
		void SetUp() override {
			EXPECT_EQ(TEEC_InitializeContext("good", &ctx), TEEC_SUCCESS);
		}

		void TearDown() override {
			TEEC_FinalizeContext(&ctx);
		}

		TEEC_Context ctx;
};

/*******************************************************************************
 * Test cases
 ******************************************************************************/

/* Math tests */
TEST_F(MathFixture, AddFunction) {
	EXPECT_EQ(add(2, 3), 5);
	EXPECT_EQ(add(-1, 1), 0);
	EXPECT_EQ(add(0, 0), 0);
}

TEST_F(MathFixture, SubtractFunction) {
	EXPECT_EQ(subtract(5, 3), 2);
	EXPECT_EQ(subtract(0, 1), -1);
	EXPECT_EQ(subtract(0, 0), 0);
}

TEST_F(MathFixture, MultiplyFunction) {
	EXPECT_EQ(multiply(5, 3), 15);
	EXPECT_EQ(multiply(0, 1), 0);
	EXPECT_EQ(multiply(0, 0), 0);
}

TEST_F(MathFixture, BadMultiplyFunction) {
	EXPECT_EQ(multiply(5, 3), 0);
	EXPECT_EQ(multiply(0, 1), 0);
	EXPECT_EQ(multiply(0, 0), 0);
}

/* TEE tests */
TEST_F(TEEFixture, Cmd0) {
	EXPECT_EQ(TEEC_InvokeCommand(0), 1);
}

TEST_F(TEEFixture, Cmd1) {
	EXPECT_EQ(TEEC_InvokeCommand(1), 2);
}

TEST_F(TEEFixture, Cmd2) {
	EXPECT_EQ(TEEC_InvokeCommand(2), 3);
}

TEST_F(TEEFixture, Cmd3) {
	EXPECT_EQ(TEEC_InvokeCommand(3), 3);
}

TEST_F(TEEFixture, BadCmdLoop) {
	for (int i = 0; i < 4; i++) {
		EXPECT_EQ(TEEC_InvokeCommand(i), i+1);
	}
}

/*******************************************************************************
 * Main 
 ******************************************************************************/
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
