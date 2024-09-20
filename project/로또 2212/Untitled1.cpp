#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

enum SHAPE
{
	SPADE,
	DIAMOND,
	HEART,
	CLOVER
};

struct tagCard
{
	int shape;
	int number;
};

void printCard(tagCard card)
{
	cout << "|";
	switch (card.shape)
	{
	case 0:
		cout << "♠";
		break;
	case 1:
		cout << "◆";
		break;
	case 2:
		cout << "♥";
		break;
	case 3:
		cout << "♣";
	}
	cout << "  |\n|    |\n|  ";
	switch (card.number)
	{
	case 1:
		cout << " A";
		break;
	case 11:
		cout << " J";
		break;
	case 12:
		cout << " Q";
		break;
	case 13:
		cout << " K";
		break;
	default:
		if (card.number != 10)
			cout << " ";
		cout << card.number;
	}
	cout << "|" << endl << endl;
}

int main()
{
	srand(time(NULL));

	int playerMoney = 100000;
	tagCard cards[52];

	{
		int count = 0;
		for (int i = 0; i < 52; i++)
		{
			if (i != 0 && i % 13 == 0)
				count++;
			switch (count)
			{
			case 0:
				cards[i].shape = SPADE;
				break;
			case 1:
				cards[i].shape = DIAMOND;
				break;
			case 2:
				cards[i].shape = HEART;
				break;
			case 3:
				cards[i].shape = CLOVER;
			}
			cards[i].number = i % 13 + 1;
		}
	}

	int destIdx, sourIdx;
	tagCard temp;

	for (int i = 0; i < 100; i++)
	{
		destIdx = rand() % 52;
		sourIdx = rand() % 52;

		temp = cards[destIdx];
		cards[destIdx] = cards[sourIdx];
		cards[sourIdx] = temp;
	}

	int idx = 0;
	while (true)
	{
		system("cls");
		int dealMoney = 0;

		cout << "\n\t\t\t소지금: " << playerMoney << endl;

		int openCards[2];

		int destIdx = idx + 2;
		int i = 0;
		for (idx; idx < destIdx; idx++)
		{
			openCards[i++] = cards[idx].number;
			printCard(cards[idx]);
		}

		// 0: 작은 수, 1: 큰 수로 정렬해서 쉽게 비교할 수 있게끔
		if (openCards[0] > openCards[1])
		{
			int temp;
			temp = openCards[0];
			openCards[0] = openCards[1];
			openCards[1] = temp;
		}

		while (true)
		{
			cout << "\n배팅해 주세요. (최소 금액: 1,000) > ";
			cin >> dealMoney;
			if (dealMoney < 1000)
			{
				cout << "잘못 입력하셨습니다. " << endl;
				continue;
			}
			else if (dealMoney > playerMoney)
			{
				cout << "소지금보다 많은 금액을 배팅할 수 없습니다. " << endl;
				continue;
			}
			break;
		}

		cout << endl;
		cout << "카드를 오픈합니다." << endl;

		tagCard newOpenCard{ cards[idx].shape, cards[idx++].number };
		printCard(newOpenCard);

		if (newOpenCard.number > openCards[0] && newOpenCard.number < openCards[1])
		{
			cout << dealMoney * 2 << "를 획득하셨습니다! 축하합니다!" << endl;
			playerMoney += dealMoney;
		}
		else
		{
			//cout << newOpenCard.number << " " << openCards[0] << " " << openCards[1];
			cout << "배팅하신 " << dealMoney << "을 잃으셨습니다." << endl;
			playerMoney -= dealMoney;
		}

		if (playerMoney <= 0)
		{
			playerMoney = 0;
			break;
		}

		Sleep(3000);
		if (idx >= 50)
		{
			cout << "카드를 전부 사용하였습니다." << endl;
			break;
		}
	}

	cout << "\n >> 게임 종료!! 당신의 소지금: " << playerMoney << " <<" << endl;

	return 0;
}
