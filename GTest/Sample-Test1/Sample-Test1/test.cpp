#include "pch.h"
class ArraySorter {
private:
	int* arr;
	int size;

public:
	ArraySorter(int array[], int arraySize) : arr(array), size(arraySize) {}

	void BubbleSort() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (arr[j] > arr[j + 1]) {
					// Hoán đổi giá trị của hai phần tử
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	void PrintArray() {
		for (int i = 0; i < size; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};
TEST(BubbleSort, BubbleSortTest) {
		int inputArray[] = { 6,8,1,3,2};
		int expectedArray[] = { 1, 2, 3, 6, 8 };
		int arraySize = sizeof(inputArray) / sizeof(inputArray[0]);
		// Khởi tạo đối tượng ArraySorter
		ArraySorter sorter(inputArray, arraySize);
		// Gọi phương thức BubbleSort để sắp xếp mảng
		sorter.BubbleSort();
		// Kiểm tra xem mảng đã được sắp xếp đúng hay chưa
		for (int i = 0; i < arraySize; ++i) {
			EXPECT_EQ(inputArray[i], expectedArray[i]);
		}
	}