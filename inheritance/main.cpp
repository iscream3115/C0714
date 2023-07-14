#include <iostream>
using namespace std;

class Weapon
{
//�ڽ� Ŭ���������� ������ �Ұ���
private:
	int level;
	int power;

//�ܺο��� ������ �Ұ����ϳ� �ڽ� Ŭ�����������δ� ���� ����
protected:
	int range;
	int atk;
	int dur;
public:
	Weapon()
	{
		cout << "Weapon ������" << endl;
	}
	~Weapon()
	{
		cout << "Weapon �Ҹ���" << endl;
	}

	void attack()
	{
		cout << "����� ����" << endl;
	}

	void reinforce(int value)
	{
		cout << value << "��ŭ ��ȭ�ߴ�." << endl;
	}

};

//class �ڿ� : -> ����� ���� ��� �Է�
class Sword : public Weapon
{
private:
public:
	Sword() { cout << "�� ������" << endl; }
	~Sword() { cout << "�� �Ҹ��� " << endl; }

	void parry()
	{
		cout << "�и��� �ߴ�" << endl;
	}
};

class Bow : public Weapon
{
private:
public:
	Bow() { cout << "Ȱ ������" << endl; }
	~Bow() { cout << "Ȱ �Ҹ���" << endl; }

	void attack()
	{
		fireProjectile();
	}
	
	void fireProjectile()
	{
		cout << "ȭ���� ����." << endl;
	}
};

class Dagger : public Weapon
{
private:
	float critical;
public:
	Dagger(): critical(2.0f) { cout << "�ܰ� ������" << endl; }
	~Dagger() { cout << "�ܰ� �Ҹ���" << endl; }

	void dual()
	{
		cout << "�ܰ� �ּ��� ��� ����" << endl;
	}
};

int main()
{

	//��ü�� �ٸ��� ������ �ڽ� Ŭ���� ȣ��ÿ��� �θ� Ŭ������ �����ڸ� ��� ȣ���Ѵ�.
	Weapon w;
	w.attack();

	Sword* s = new Sword;
	s->attack();
	s->reinforce(5);

	Bow b;
	b.attack();

	//���� �Ҵ��� sword�� ���� �Ҹ�����ش�.
	delete s;


	return 0;
}