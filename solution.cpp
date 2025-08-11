#include <iostream>
#include <algorithm> //max 함수 사용
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
		cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n" << "현재 HP: " << *currentHP << endl;
		cout << "남은 포션 수: " << *currentCount_HPPotion << endl;
	}
	else
		cout << "포션이 부족합니다.\n";
}

void HealMp(int* currentCount_MPPotion, int* currentMP)
{
	if (*currentCount_MPPotion != 0)
	{
		*currentCount_MPPotion -= 1;
		*currentMP += 20;
		cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n" << "현재 MP: " << *currentMP << endl;
		cout << "남은 포션 수: " << *currentCount_MPPotion << endl;
	}
	else
		cout << "포션이 부족합니다.\n";
}

void HpReinforce(int* currentHP)
{
	*currentHP *= 2;
	cout << "* HP가 2배로 증가되었습니다.\n" << "현재 HP: " << *currentHP << endl;
}

void MpReinforce(int* currentMP)
{
	*currentMP *= 2;
	cout << "* MP가 2배로 증가되었습니다.\n" << "현재 MP: " << *currentMP << endl;
}

void AttackSkill(int* currentMP)
{
	if (*currentMP >= 50)
	{
		*currentMP -= 50;
		cout << "* 스킬을 사용하여 MP가 50 소모되었습니다.\n" << "현재 MP: " << *currentMP << endl;
	}
	else
		cout << "스킬 사용이 불가합니다.\n";
}

void SpecialAttack(int* currentMP)
{
	if (*currentMP != 0)
	{
		*currentMP /= 2;
		cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다.\n" << "현재 MP: " << *currentMP << endl;
	}
	else
		cout << "스킬 사용이 불가합니다.\n";
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
		cout << "HP와 MP를 입력해주세요: ";
		cin >> status[0] >> status[1];
		if (status[0] <= 50 || status[1] <= 50)
		{
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
		}
	} while (status[0] <= 50 || status[1] <= 50);

	do
	{
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> status[2] >> status[3];
		if (status[2] <= 0 || status[3] <= 0)
		{
			cout << "공격력과 방어력은 양의 정수여야합니다. 다시 입력해주세요.\n";
		}
	} while (status[2] <= 0 || status[3] <= 0);



	//Print Status Manage System
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";
	cout << "=============================================" << endl;
	cout << "<스탯 관리 시스템>\n" << "1. HP 회복\n" << "2. MP 회복\n" << "3. HP 강화\n" << "4. MP 강화\n" << "5. 공격 스킬 사용\n";
	cout << "6. 필살기 사용\n" << "7. 나가기\n";


	do 
	{
		cout << "번호를 선택해주세요 : ";
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
			cout << "입력한 행동이 존재하지 않습니다 다시 입력해 주십시오\n";
		}

	} while (actionNumber != 7);

	cout << "프로그램을 종료합니다.\n";

    return 0;
}