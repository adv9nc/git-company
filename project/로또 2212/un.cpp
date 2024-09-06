#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 45
#define LOTTO_COUNT 6

// �迭���� �ߺ��� ���� ã�� �Լ�
int isDuplicate(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1; // �ߺ��� ���� �߰ߵ�
        }
    }
    return 0; // �ߺ��� ���� ����
}

// �ζ� ��ȣ�� �����ϴ� �Լ�
void generateLottoNumbers(int lottoNumbers[], int count) {
    // 1���� 45������ ���ڸ� �迭�� ����
    int numbers[MAX_NUMBER];
    for (int i = 0; i < MAX_NUMBER; i++) {
        numbers[i] = i + 1;
    }

    // ������ �õ� �ʱ�ȭ
    srand((unsigned int)time(NULL));

    // �ߺ��� ���ϱ� ���� �������� 6���� ���� ����
    for (int i = 0; i < count; i++) {
        int randomIndex;
        do {
            randomIndex = rand() % MAX_NUMBER;
        } while (isDuplicate(lottoNumbers, i, numbers[randomIndex]));

        lottoNumbers[i] = numbers[randomIndex];
    }

    // ������������ ����
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

// ���� �Լ�
int main() {
    int lottoNumbers[LOTTO_COUNT];

    printf("�ζ� ��ȣ ������\n");

    // �ζ� ��ȣ ����
    generateLottoNumbers(lottoNumbers, LOTTO_COUNT);

    // ��� ���
    printf("������ �ζ� ��ȣ: ");
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d ", lottoNumbers[i]);
    }
    printf("\n");

    return 0;
}

