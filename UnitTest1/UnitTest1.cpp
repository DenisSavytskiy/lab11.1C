#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
#include "../AP_Lab№11.1C.c/AP_Lab№11.1 C.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
    TEST_CLASS(WhileOccurrencesTest) {
public:
    TEST_METHOD(TestWhileOccurrencesInFile) {
        FILE* testFile = nullptr;
        errno_t err = fopen_s(&testFile, "test_input.txt", "w");
        Assert::AreEqual(0, (int)err);
        fputs("while loop is common\nAnother while example\nNo occurrences here\n", testFile);
        fclose(testFile);

        int result = count_substring_occurrences("test_input.txt", "while");
        Assert::AreEqual(2, result);
    }

    TEST_METHOD(TestNoOccurrences) {
        FILE* testFile = nullptr;
        errno_t err = fopen_s(&testFile, "test_no_occurrences.txt", "w");
        Assert::AreEqual(0, (int)err);
        fputs("No searched word here\nAnother line\n", testFile);
        fclose(testFile);

        int result = count_substring_occurrences("test_no_occurrences.txt", "while");
        Assert::AreEqual(0, result);
    }

    TEST_METHOD(TestNonExistentFile) {
        int result = count_substring_occurrences("non_existent_file.txt", "while");
        Assert::AreEqual(-1, result);
    }
    };
}