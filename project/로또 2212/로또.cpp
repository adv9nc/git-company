#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 45
#define LOTTO_COUNT 6

// 배열에서 중복된 값을 찾는 함수
int isDuplicate(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1; // 중복된 값이 발견됨
        }
    }
    return 0; // 중복된 값이 없음
}

// 로또 번호를 생성하는 함수
void generateLottoNumbers(int lottoNumbers[], int count) {
    // 1부터 45까지의 숫자를 배열에 저장
    int numbers[MAX_NUMBER];
    for (int i = 0; i < MAX_NUMBER; i++) {
        numbers[i] = i + 1;
    }

    // 무작위 시드 초기화
    srand((unsigned int)time(NULL));

    // 중복을 피하기 위해 랜덤으로 6개의 숫자 선택
    for (int i = 0; i < count; i++) {
        int randomIndex;
        do {
            randomIndex = rand() % MAX_NUMBER;
        } while (isDuplicate(lottoNumbers, i, numbers[randomIndex]));

        lottoNumbers[i] = numbers[randomIndex];
    }

    // 오름차순으로 정렬
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (lottoNumbers[i] > lottoNumbers[j]) {
                int temp = lottoNumbers[i];
                lottoNumbers[i] = lottoNumbers[j];
                lottoNumbers[j] = temp;
            }
        }
    }
}

// 메인 함수
int main() {
    int lottoNumbers[LOTTO_COUNT];

    printf("로또 번호 생성기\n");

    // 로또 번호 생성
    generateLottoNumbers(lottoNumbers, LOTTO_COUNT);

    // 결과 출력
    printf("생성된 로또 번호: ");
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d ", lottoNumbers[i]);
    }
    printf("\n");

    return 0;
}

