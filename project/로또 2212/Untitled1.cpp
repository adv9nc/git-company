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
		cout << "��";
		break;
	case 1:
		cout << "��";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
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

		cout << "\n\t\t\t������: " << playerMoney << endl;

		int openCards[2];

		int destIdx = idx + 2;
		int i = 0;
		for (idx; idx < destIdx; idx++)
		{
			openCards[i++] = cards[idx].number;
			printCard(cards[idx]);
		}

		// 0: ���� ��, 1: ū ���� �����ؼ� ���� ���� �� �ְԲ�
		if (openCards[0] > openCards[1])
		{
			int temp;
			temp = openCards[0];
			openCards[0] = openCards[1];
			openCards[1] = temp;
		}

		while (true)
		{
			cout << "\n������ �ּ���. (�ּ� �ݾ�: 1,000) > ";
			cin >> dealMoney;
			if (dealMoney < 1000)
			{
				cout << "�߸� �Է��ϼ̽��ϴ�. " << endl;
				continue;
			}
			else if (dealMoney > playerMoney)
			{
				cout << "�����ݺ��� ���� �ݾ��� ������ �� �����ϴ�. " << endl;
				continue;
			}
			break;
		}

		cout << endl;
		cout << "ī�带 �����մϴ�." << endl;

		tagCard newOpenCard{ cards[idx].shape, cards[idx++].number };
		printCard(newOpenCard);

		if (newOpenCard.number > openCards[0] && newOpenCard.number < openCards[1])
		{
			cout << dealMoney * 2 << "�� ȹ���ϼ̽��ϴ�! �����մϴ�!" << endl;
			playerMoney += dealMoney;
		}
		else
		{
			//cout << newOpenCard.number << " " << openCards[0] << " " << openCards[1];
			cout << "�����Ͻ� " << dealMoney << "�� �����̽��ϴ�." << endl;
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
			cout << "ī�带 ���� ����Ͽ����ϴ�." << endl;
			break;
		}
	}

	cout << "\n >> ���� ����!! ����� ������: " << playerMoney << " <<" << endl;

	return 0;
}
