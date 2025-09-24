#include <stdio.h>
#include <stdlib.h>

// 동적 2차원 배열 생성 및 학습 예제.
int main() {
    int ROWS = 3, COLS = 3;

    // 행 포인터 배열 동적 할당.
    int** matrix = (int**)malloc(sizeof(int*) * ROWS);
    if (matrix == NULL) {
        printf("Error! Memory allocation failed.\n");
        return 1;
    }

    // 각 행마다 열 크기 동적 할당.
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * COLS);
        if (matrix[i] == NULL) {
            printf("Error! Memory allocation failed.\n");
            return 1;
        }

        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = i + j; // 간단한 값 대입.
        }
    }

    // 포인터 연산 예제.
    int* ptr = matrix[2];             // 2번째 행 시작 주소.
    *(ptr - 2) = 99;                  // matrix[1][COLS-2] 위치 변경.
    *(*(matrix + 0) + 2) = *(*(matrix + 1) + 1) + *(*(matrix + 2) + 0); 
    // matrix[0][2] = matrix[1][1] + matrix[2][0].

    // 행렬 전체 출력.
    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 특정 값 확인 출력.
    printf("\nmatrix[0][0] = %d\n", matrix[0][0]);
    printf("matrix[0][2] = %d\n", matrix[0][2]);
    printf("matrix[2][0] = %d\n", matrix[2][0]);

    // 메모리 해제.
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

/*
동적 이차원 배열 포인트.
1. 이중 포인터를 이용해 행렬을 동적 생성할 수 있다.
2. malloc으로 행과 열을 각각 할당해야 한다.
3. 2차원 배열 접근은 matrix[i][j], *(*(matrix+i)+j) 두 가지 방식이 가능하다.
4. 포인터 연산을 활용해 원하는 위치를 직접 지정할 수 있다.
5. 사용이 끝난 후 free로 메모리 해제를 반드시 해야 한다.
*/
