#include <stdio.h>

// 버블 정렬 함수.
void BubbleSort(int* arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // 인접 요소 비교 후 swap.
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 선택 정렬 함수.
void SelectionSort(int* arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        int min_idx = i; // 이번 턴의 최소값 인덱스.

        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // 최소값을 현재 위치와 교환.
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// 삽입 정렬 함수.
void InsertionSort(int* arr, int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];     // 현재 삽입할 값.
        int j = i - 1;

        // key보다 큰 값들을 한 칸씩 뒤로 민다.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // 빈 자리에 key 삽입.
    }
}

// 배열 출력 함수.
void PrintArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 배열 복사 함수.
void CopyArray(int* src, int* dest, int length) {
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
}

// 실행 예제.
int main() {
    int original[] = {9, 5, 2, 7, 4, 1, 6, 10, 3, 8};
    int length = sizeof(original) / sizeof(original[0]);

    int arr1[length], arr2[length], arr3[length];

    CopyArray(original, arr1, length);
    CopyArray(original, arr2, length);
    CopyArray(original, arr3, length);

    BubbleSort(arr1, length);
    printf("Bubble Sort result: ");
    PrintArray(arr1, length);

    SelectionSort(arr2, length);
    printf("Selection Sort result: ");
    PrintArray(arr2, length);

    InsertionSort(arr3, length);
    printf("Insertion Sort result: ");
    PrintArray(arr3, length);

    return 0;
}

/*
포인트.
1. 삽입 정렬을 제외한 다른 정렬방법의 바깥 for문의 반복 횟수는 length - 1이다.
2. 삽입 정렬을 제외한 다른 정렬방법의 inner for문의 반복 횟수는 length - i - 1이다.
3. 삽입 정렬은 기준을 잡고 왼쪽부터 비교하며 값을 밀어낸다.
4. 버블 정렬은 inner for문에서 swap이 반복적으로 일어난다.
5. 선택 정렬은 inner for문에서 최소값을 찾고, 바깥 for문에서 swap은 한 번만 일어난다.
6. 삽입 정렬은 inner while에서 뒤로 밀어 공간을 확보하고, 바깥 for문이 이번 회차 대상을 지정한다.
*/
