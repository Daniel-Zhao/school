#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Teacher;

// 基类
//========================================
class Person
{
public:
	Person() {} //默认构造函数
	Person(string s, char c, int i)
	{
		age = i;
		name = s;
		sex = c;
	}
	virtual	void inputData()
	{
		cout << "Input name:";
		cin >> name;
		cout << "Input sex (M or F)";
		cin >> sex;
		cout << "Input age:";
		cin >> age;
	}
	virtual void outData()
	{
		cout << "Name:" << name << endl;
		cout << "Sex:" << sex << endl;
		cout << "Age:" << age << endl;
	}
	friend ostream &operator<< (ostream &os, Person &p);
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
	Student() { tutor = NULL; }
	void inputData()
	{
		cout << "Input SID:";
		cin >> sid;
		cout << "Input name:";
		cin >> name;
		cout << "Input sex: (M or F)";
		cin >> sex;
		cout << "Input age:";
		cin >> age;
		cout << "Input Class:";
		cin >> classX;
		cout << "Input Score" << endl;
		cout << "Input chinese:";
		cin >> chinese;
		cout << "Input english:";
		cin >> english;
		cout << "Input math:";
		cin >> math;
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
		cout << "------------------" << endl;
	}
	friend ostream &operator<< (ostream &os, Student &s);
private:
	string sid;
	int classX;
	double chinese;
	double english;
	double math;
	Teacher *tutor;
};


//老师类
//===============================================
class Teacher : public Person
{
public:
	Teacher() {}
	void inputData();
	void outData();
	virtual double getSalary() { return salary; }
	//工资 = 基本工资 + 课时费 * 课时
	virtual double getIncome() { return (getSalary() + (workHour * hourPrice)); }
	virtual void setSalary(double s) { salary = s; }
	void setWHour(int h) { workHour = h; }
	void setWHPrice(double p) { hourPrice = p; }
	friend ostream &operator<< (ostream &os, Teacher &t);
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
	cin >> tid;
	cout << "Input name:";
	cin >> name;
	cout << "Input sex: (M or F)";
	cin >> sex;
	cout << "Input age:";
	cin >> age;
	cout << "Input protitle:";
	cin >> protitle;
	cout << "Input department:";
	cin >> dept;
	cout << "Input salary:";
	cin >> salary;
	cout << "Input work hour(s):";
	cin >> workHour;
	cout << "Input price per hour:";
	cin >> hourPrice;
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
	cout << "------------------" << endl;
}


//院长类
//===============================================
class Chancellor : public Teacher
{
public:
	Chancellor() {}
	void inputData();
	void outData();
	void setSalary(double s) { salary = s; }
	//工资 = 基本工资 + 年薪
	double getIncome() { return getSalary() + yearSalary; }
	friend ostream &operator<< (ostream &os, Chancellor &c);
private:
	double yearSalary; //年薪
};
void Chancellor::inputData()
{
	cout << "Input TID:";
	cin >> tid;
	cout << "Input name:";
	cin >> name;
	cout << "Input sex: (M or F)";
	cin >> sex;
	cout << "Input age:";
	cin >> age;
	cout << "Input protitle:";
	cin >> protitle;
	cout << "Input department:";
	cin >> dept;
	cout << "Input year salary:";
	cin >> yearSalary;
	cout << "Input salary:";
	cin >> salary;
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
	cout << "------------------" << endl;
}


//系主任类
//===============================================
class Dean : public Teacher
{
public:
	Dean() {}
	void inputData();
	void outData();
	void setSalary(double s) { salary = s; }
	void setPerformance() //输入每个月的绩效
	{
		for (int i = 0; i < 12; i++)
		{
			cout << "Input month" << i + 1 << "'s performance:";
			cin >> performance[i];
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
	friend ostream &operator<< (ostream &os, Dean &d);
private:
	double performance[12]; //每个月的绩效
};
void Dean::inputData()
{
	cout << "Input TID:";
	cin >> tid;
	cout << "Input name:";
	cin >> name;
	cout << "Input sex: (M or F)";
	cin >> sex;
	cout << "Input age:";
	cin >> age;
	cout << "Input protitle:";
	cin >> protitle;
	cout << "Input department:";
	cin >> dept;
	cout << "Input salary:";
	cin >> salary;
	setPerformance();
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
	cout << "------------------" << endl;
}

//处理函数
//===============================================
void processFunc(Person *p)
{
	p->inputData(); //输入信息
	cout << "------------------" << endl;
	p->outData();  //输出信息
}

// <<运算符重载函数
//===============================================
//基类
ostream &operator<< (ostream &os, Person &p)
{
	os << "Name:" << p.name << endl
		<< "Sex:" << p.sex << endl
		<< "Age:" << p.age << endl;
	return os;
}
//学生类
ostream &operator<< (ostream &os, Student &s)
{
	os << "SID:" << s.sid << endl
		<< "Class:" << s.classX << endl
		<< "Name:" << s.name << endl
		<< "Sex:" << s.sex << endl
		<< "Age:" << s.age << endl
		<< "chinese:" << s.chinese << endl
		<< "english:" << s.english << endl
		<< "math:" << s.math << endl
		<< "------------------" << endl;
	return os;
}
//老师类
ostream &operator<< (ostream &os, Teacher &t)
{
	os << "TID:" << t.tid << endl
		<< "Name:" << t.name << endl
	    << "Sex:" << t.sex << endl
	    << "Age:" << t.age << endl
	    << "Protitle:" << t.protitle << endl
	    << "Department:" << t.dept << endl
	    << "Income:" << t.getIncome() << endl
	    << "------------------" << endl;
	return os;
}
//校长类
ostream &operator<< (ostream &os, Chancellor &c)
{
	os << "TID:" << c.tid << endl
		<< "Name:" << c.name << endl
		<< "Sex:" << c.sex << endl
		<< "Age:" << c.age << endl
		<< "Protitle:" << c.protitle << endl
		<< "Department:" << c.dept << endl
		<< "Income:" << c.getIncome() << endl
		<< "------------------" << endl;
	return os;
}
//系主任类
ostream &operator<< (ostream &os, Dean &c)
{
	os << "TID:" << c.tid << endl
		<< "Name:" << c.name << endl
		<< "Sex:" << c.sex << endl
		<< "Age:" << c.age << endl
		<< "Protitle:" << c.protitle << endl
		<< "Department:" << c.dept << endl
		<< "Income:" << c.getIncome() << endl
		<< "------------------" << endl;
	return os;
}


//主函数
//===============================================
int main()
{
	char end = ' ';
	int job;
	vector<Person*> person; //所有记录

	while (end != 'Q' && end != 'q') //当用户输入Q或q时循环结束
	{
		cout << "------------------" << endl;
		cout << "Input job" << endl;                       //提示输入职业
		cout << "1 for Student,    2 for Teacher" << endl;
		cout << "3 for Chancellor, 4 for Dean" << endl;
		cin >> job;
		cout << "------------------" << endl;

		if (job == 1)
		{
			Student *s = new Student; //创建对象s
			processFunc(s); //调用处理函数
			person.push_back(s); // 把s放到记录中
		}
		else if (job == 2)
		{
			Teacher *s = new Teacher; 
			processFunc(s);
			person.push_back(s);
		}
		else if (job == 3)
		{
			Chancellor *s = new Chancellor;  
			processFunc(s);
			person.push_back(s);
		}
		else if (job == 4)
		{
			Dean *s = new Dean;
			processFunc(s);
			person.push_back(s); 
		}
		else   //处理错误输入的职业序号
		{
			cout << "Please input number 1-4" << endl;
			continue;
		}

		cout << "Input Q to quit, input other letter to continue."; //提示按Q退出程序，按其他键继续
		cin >> end;
	}
	cout << "Bye!";
	return 0;
}
