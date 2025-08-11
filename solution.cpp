#include <iostream>
#include <algorithm> //max �Լ� ���
#include <string>
using namespace std;

void setPotion (int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void HealHp (int* currentCount_HPPotion, int* currentHP)
{
	if (*currentCount_HPPotion != 0)
	{
		*currentCount_HPPotion -= 1;
		*currentHP += 20;
		cout << "* HP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�.\n" << "���� HP: " << *currentHP << endl;
		cout << "���� ���� ��: " << *currentCount_HPPotion << endl;
	}
	else
		cout << "������ �����մϴ�.\n";
}

void HealMp(int* currentCount_MPPotion, int* currentMP)
{
	if (*currentCount_MPPotion != 0)
	{
		*currentCount_MPPotion -= 1;
		*currentMP += 20;
		cout << "* MP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�.\n" << "���� MP: " << *currentMP << endl;
		cout << "���� ���� ��: " << *currentCount_MPPotion << endl;
	}
	else
		cout << "������ �����մϴ�.\n";
}

void HpReinforce(int* currentHP)
{
	*currentHP *= 2;
	cout << "* HP�� 2��� �����Ǿ����ϴ�.\n" << "���� HP: " << *currentHP << endl;
}

void MpReinforce(int* currentMP)
{
	*currentMP *= 2;
	cout << "* MP�� 2��� �����Ǿ����ϴ�.\n" << "���� MP: " << *currentMP << endl;
}

void AttackSkill(int* currentMP)
{
	if (*currentMP >= 50)
	{
		*currentMP -= 50;
		cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�.\n" << "���� MP: " << *currentMP << endl;
	}
	else
		cout << "��ų ����� �Ұ��մϴ�.\n";
}

void SpecialAttack(int* currentMP)
{
	if (*currentMP != 0)
	{
		*currentMP /= 2;
		cout << "* ��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�.\n" << "���� MP: " << *currentMP << endl;
	}
	else
		cout << "��ų ����� �Ұ��մϴ�.\n";
}

int main() 
{
	// HP MP ATK DEF Setting
    int status[4] = { 0,0,0,0 };


	//Potion Setting
	int hpPotion;
	int mpPotion;
	setPotion(5, &hpPotion, &mpPotion);

	int actionNumber;



	//Status Setting
	do
	{
		cout << "HP�� MP�� �Է����ּ���: ";
		cin >> status[0] >> status[1];
		if (status[0] <= 50 || status[1] <= 50)
		{
			cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n";
		}
	} while (status[0] <= 50 || status[1] <= 50);

	do
	{
		cout << "���ݷ°� ������ �Է����ּ���: ";
		cin >> status[2] >> status[3];
		if (status[2] <= 0 || status[3] <= 0)
		{
			cout << "���ݷ°� ������ ���� ���������մϴ�. �ٽ� �Է����ּ���.\n";
		}
	} while (status[2] <= 0 || status[3] <= 0);



	//Print Status Manage System
	cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)\n";
	cout << "=============================================" << endl;
	cout << "<���� ���� �ý���>\n" << "1. HP ȸ��\n" << "2. MP ȸ��\n" << "3. HP ��ȭ\n" << "4. MP ��ȭ\n" << "5. ���� ��ų ���\n";
	cout << "6. �ʻ�� ���\n" << "7. ������\n";


	do 
	{
		cout << "��ȣ�� �������ּ��� : ";
		cin >> actionNumber;
		
		//Additional Function : actionNunber Must be 1~7
		if (1 <= actionNumber && actionNumber <= 7) 
		{
			switch (actionNumber)
			{
				case 1:
					HealHp(&hpPotion, &status[0]);
					break;
				case 2:
					HealMp(&mpPotion, &status[1]);
					break;
				case 3:
					HpReinforce(&status[0]);
					break;
				case 4:
					MpReinforce(&status[1]);
					break;
				case 5:
					AttackSkill(&status[1]);
					break;
				case 6:
					SpecialAttack(&status[1]);
					break;
				case 7:
					HealHp(&hpPotion, &status[0]);
					break;

			}
		}
		else
		{
			cout << "�Է��� �ൿ�� �������� �ʽ��ϴ� �ٽ� �Է��� �ֽʽÿ�\n";
		}

	} while (actionNumber != 7);

	cout << "���α׷��� �����մϴ�.\n";

    return 0;
}