#include <iostream>
using namespace std;

class Weapon
{
//자식 클래스에서도 접근이 불가능
private:
	int level;
	int power;

//외부에서 접근이 불가능하나 자식 클래스한정으로는 접근 가능
protected:
	int range;
	int atk;
	int dur;
public:
	Weapon()
	{
		cout << "Weapon 생성자" << endl;
	}
	~Weapon()
	{
		cout << "Weapon 소멸자" << endl;
	}

	void attack()
	{
		cout << "무기로 공격" << endl;
	}

	void reinforce(int value)
	{
		cout << value << "만큼 강화했다." << endl;
	}

};

//class 뒤에 : -> 상속을 받을 대상 입력
class Sword : public Weapon
{
private:
public:
	Sword() { cout << "검 생성자" << endl; }
	~Sword() { cout << "검 소멸자 " << endl; }

	void parry()
	{
		cout << "패링을 했다" << endl;
	}
};

class Bow : public Weapon
{
private:
public:
	Bow() { cout << "활 생성자" << endl; }
	~Bow() { cout << "활 소멸자" << endl; }

	void attack()
	{
		fireProjectile();
	}
	
	void fireProjectile()
	{
		cout << "화살을 쐈다." << endl;
	}
};

class Dagger : public Weapon
{
private:
	float critical;
public:
	Dagger(): critical(2.0f) { cout << "단검 생성자" << endl; }
	~Dagger() { cout << "단검 소멸자" << endl; }

	void dual()
	{
		cout << "단검 쌍수로 들고 공격" << endl;
	}
};

int main()
{

	//객체가 다르기 때문에 자식 클래스 호출시에도 부모 클래스의 생성자를 계속 호출한다.
	Weapon w;
	w.attack();

	Sword* s = new Sword;
	s->attack();
	s->reinforce(5);

	Bow b;
	b.attack();

	//동적 할당한 sword는 직접 소멸시켜준다.
	delete s;


	return 0;
}