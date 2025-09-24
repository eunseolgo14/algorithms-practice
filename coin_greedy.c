#include <stdio.h>

// 메인 실행 함수.
int main() {
    int coins[] = {500, 10, 50, 100}; // 사용 가능한 동전 단위.
    int price = 1260; // 거슬러 줄 금액.
    int count = 0;    // 동전 개수 총합.

    int size = sizeof(coins) / sizeof(coins[0]); // 동전 배열 크기.

    // 1. 동전을 내림차순으로 정렬한다.
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }

    // 2. 큰 단위 동전부터 사용해 금액을 채운다.
    for (int i = 0; i < size; i++) {
        int this_count = price / coins[i]; // 해당 동전 개수 계산.
        price %= coins[i];                 // 남은 금액 갱신.
        count += this_count;               // 동전 개수 합산.

        if (this_count > 0) {
            printf("동전 %d원: %d개 사용.\n", coins[i], this_count);
        }
    }

    // 최종 동전 개수 출력.
    printf("총 동전 개수: %d\n", count);

    return 0;
}

/*
직접 작성하며 느낀 점.
1. 버블 정렬에서 내부 반복문은 (size - i - 1)까지 돌아야 한다.
2. 동전 문제는 큰 단위부터 greedy하게 사용하는 방식이 최적해를 보장한다.
3. 출력 시 단계별 동전 개수를 확인하면 동작 원리를 쉽게 이해할 수 있다.
*/