#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 基类
//========================================
class Person
{
public:
	Person(){} //默认构造函数
	Person(string s, char c, int i)
	{
		age = i;
		name = s;
		sex = c;
	}
	void inputData()
	{
		cout << "Input name:";
		std::cin >> name;
		cout << "Input sex (M or F)";
		std::cin >> sex;
		cout << "Input age:";
		std::cin >> age;
	}
	void outData()
	{
		cout << "Name:" << name << endl;
		cout << "Sex:" << sex << endl;
		cout << "Age:" << age << endl;
	}
protected:
	int age;
	string name;
	char sex;
};


//学生类
//===============================================
class Student : public Person
{
public:
	Student(){}
	void inputData()
	{
		cout << "Input SID:";
		std::cin >> sid;
		cout << "Input name:";
		std::cin >> name;
		cout << "Input sex: (M or F)";
		std::cin >> sex;
		cout << "Input age:";
		std::cin >> age;
		cout << "Input Class:";
		std::cin >> classX;
		cout << "Input Score" << endl;
		cout << "Input chinese:";
		std::cin >> chinese;
		cout << "Input english:";
		std::cin >> english;
		cout << "Input math:";
		std::cin >> math;
	}
	void outData()
	{
		cout << "SID:" << sid << endl;
		cout << "Class:" << classX << endl;
		cout << "Name:" << name << endl;
		cout << "Sex:" << sex << endl;
		cout << "Age:" << age << endl;
		cout << "chinese:" << chinese << endl;
		cout << "english:" << english << endl;
		cout << "math:" << math << endl;
	}
private:
	string sid;
	int classX;
	double chinese;
	double english;
	double math;
};


//老师类
//===============================================
class Teacher : public Person
{
public:
	Teacher(){}
	void inputData();
	void outData();
	double getSalary() { return salary; }
	//工资 = 基本工资 + 课时费 * 课时
	double getIncome() { return (getSalary() + (workHour * hourPrice)); }
	void setSalary(double s) { salary = s; }
	void setWHour(int h) { workHour = h; }
	void setWHPrice(double p) { hourPrice = p; }
protected:
	string dept; //系
	double hourPrice; //课时费
	string protitle;  //职称
	double salary; //基本工资
	int tid; 
	int workHour; //课时
};
void Teacher::inputData()
{
	cout << "Input TID:";
	std::cin >> tid;
	cout << "Input name:";
	std::cin >> name;
	cout << "Input sex: (M or F)";
	std::cin >> sex;
	cout << "Input age:";
	std::cin >> age;
	cout << "Input protitle:";
	std::cin >> protitle;
	cout << "Input department:";
	std::cin >> dept;
}
void Teacher::outData()
{
	cout << "TID:" << tid << endl;
	cout << "Name:" << name << endl;
	cout << "Sex:" << sex << endl;
	cout << "Age:" << age << endl;
	cout << "Protitle:" << protitle << endl;
	cout << "Department:" << dept << endl;
	cout << "Income:" << getIncome() << endl;
}


//院长类
//===============================================
class Chancellor : public Teacher
{
public:
	Chancellor(){}
	void inputData();
	void outData();
	//工资 = 基本工资 + 年薪
	double getIncome() { return getSalary() + yearSalary; }
private:
	double yearSalary; //年薪
};
void Chancellor::inputData()
{
	cout << "Input TID:";
	std::cin >> tid;
	cout << "Input name:";
	std::cin >> name;
	cout << "Input sex: (M or F)";
	std::cin >> sex;
	cout << "Input age:";
	std::cin >> age;
	cout << "Input protitle:";
	std::cin >> protitle;
	cout << "Input department:";
	std::cin >> dept;
	cout << "Input year salary:";
	std::cin >> yearSalary;
}
void Chancellor::outData()
{
	cout << "TID:" << tid << endl;
	cout << "Name:" << name << endl;
	cout << "Sex:" << sex << endl;
	cout << "Age:" << age << endl;
	cout << "Protitle:" << protitle << endl;
	cout << "Department:" << dept << endl;
	cout << "Income:" << getIncome() << endl;
}


//系主任类
//===============================================
class Dean : public Teacher
{
public:
	Dean(){}
	void inputData();
	void outData();
	void setPerformance() //输入每个月的绩效
	{
		for (int i = 0; i < 12; i++)
		{
			cout << "Input month" << i + 1 << "'s performance:";
			std::cin >> performance[i];
		}
	}
	double getPerformance() //整年绩效之和
	{
		double p = 0;
		for (int i = 0; i < 12; i++)
		{
			p += performance[i];
		}
		return p;
	}
	double getIncome() { return getPerformance() + getSalary(); }
private:
	double performance[12]; //每个月的绩效
};
void Dean::inputData()
{
	cout << "Input TID:";
	std::cin >> tid;
	cout << "Input name:";
	std::cin >> name;
	cout << "Input sex: (M or F)";
	std::cin >> sex;
	cout << "Input age:";
	std::cin >> age;
	cout << "Input protitle:";
	std::cin >> protitle;
	cout << "Input department:";
	std::cin >> dept;
}
void Dean::outData()
{
	cout << "TID:" << tid << endl;
	cout << "Name:" << name << endl;
	cout << "Sex:" << sex << endl;
	cout << "Age:" << age << endl;
	cout << "Protitle:" << protitle << endl;
	cout << "Department:" << dept << endl;
	cout << "Income:" << getIncome() << endl;
}

//主函数
//===============================================
int main()
{
	char end = ' ';
	int job;
	double salary, price;
	int hour;
	vector<Student> student; //所有学生记录
	vector<Teacher> teacher; //所有老师记录
	vector<Chancellor> chancellor;//所有院长记录
	vector<Dean> dean; //所有系主任记录
	while (end != 'Q' && end != 'q') //当用户输入Q或q时循环结束
	{
		cout << "------------------" << endl;
		cout << "Input job" << endl;                       //提示输入职业
		cout << "1 for Student,    2 for Teacher" << endl;
		cout << "3 for Chancellor, 4 for Dean" << endl;
		std::cin >> job;

		if (job == 1)
		{
			Student s; //创建学生对象s
			s.inputData(); //输入信息
			cout << "------------------" << endl;
			s.outData();  //输出信息
			student.push_back(s); // 把s放到学生组中
		}
		else if (job == 2)
		{
			Teacher t; //基本操作同上
			t.inputData();
			cout << "Set salary:";
			std::cin >> salary;
			cout << "Set work hour(s):";
			std::cin >> hour;
			cout << "Set price per hour:";
			std::cin >> price;
			t.setSalary(salary);
			t.setWHour(hour);
			t.setWHPrice(price);
			cout << "------------------" << endl;
			t.outData();
			teacher.push_back(t);
		}
		else if (job == 3) 
		{
			Chancellor c;  //基本操作同上
			c.inputData();
			cout << "Set salary:";
			std::cin >> salary;
			c.setSalary(salary);
			cout << "------------------" << endl;
			c.outData();
			chancellor.push_back(c);
		}
		else if (job == 4)
		{
			Dean d;   //基本操作同上
			d.inputData();
			cout << "Set salary:";
			std::cin >> salary;
			d.setSalary(salary);
			d.setPerformance();
			cout << "------------------" << endl;
			d.outData();
			dean.push_back(d);
		}
		else   //处理错误输入的职业序号
		{
			cout << "Please input number 1-4" << endl;
			continue;
		}

		cout << "Press Q to quit, press any letter to continue."; //提示按Q退出程序，按其他键继续
		std::cin >> end;
	}
	cout << "Bye!";
	return 0;
}
