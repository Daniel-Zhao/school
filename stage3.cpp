#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
class Student;

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


// 老师类
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
	set<int> studentList;
	int getTID() { return tid; }
protected:
	string dept; //系
	double hourPrice; //课时费
	string protitle;  //职称
	double salary; //基本工资
	int tid;
	int workHour; //课时
};


//学生类
//===============================================
class Student : public Person
{
public:
	Student() { tutor = NULL; }
	void inputData();
	void outData();
	friend ostream &operator<< (ostream &os, Student &s);
	//处理导师相关函数
	void setTutor(Teacher *t) { tutor = t; }
	Teacher* getTutor() { return tutor; }

	int getSID() { return sid; }
private:
	int sid;
	int classX;
	double chinese;
	double english;
	double math;
	Teacher *tutor; //导师
};


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


//相关类的outdata/inputdata函数
//===============================================
void Student::inputData()
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
void Student::outData()
{
	cout << "SID:" << sid << endl;
	cout << "Class:" << classX << endl;
	cout << "Name:" << name << endl;
	cout << "Sex:" << sex << endl;
	cout << "Age:" << age << endl;
	cout << "chinese:" << chinese << endl;
	cout << "english:" << english << endl;
	cout << "math:" << math << endl;
	if (tutor != NULL)
	{
		cout << "tutor's TID:" << tutor->getTID() << endl;
	}
	cout << "------------------" << endl;
}
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
	if (studentList.begin() != studentList.end())
	{
		cout << "Student List:" << endl;
		for (auto iter = studentList.begin(); iter != studentList.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
}
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
	if (studentList.begin() != studentList.end())
	{
		cout << "Student List:" << endl;
		for (auto iter = studentList.begin(); iter != studentList.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
}
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
	if (studentList.begin() != studentList.end())
	{
		cout << "Student List:" << endl;
		for (auto iter = studentList.begin(); iter != studentList.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
}


//处理函数
//===============================================
int selectPosition()                     //选择是老师还是学生
{
	int flag;
	cout << "1 for Student,  2 for Teacher" << endl;
	cin >> flag;
	return flag;
}

int inputStudent(map<int, Student*> &mapStudent, const map<int, Teacher*> &mapTeacher)
{
	char flag = ' ';
	int tid;
	int tutorIsNull = 0;
	Student *s = new Student;

	s->inputData(); //输入信息
	cout << "------------------" << endl;
	cout << *s;

	auto iterstu = mapStudent.find(s->getSID());         //指向map中现有的同sid的记录
	cout << "Would you like to update tutor info (y/n)" << endl;   //询问是否需要修改导师信息
	cin >> flag;
	if (flag == 'y' || flag == 'Y')
	{
		cout << "Input tutor's TID:";
		cin >> tid;
		auto iter = mapTeacher.find(tid);
		if (iter == mapTeacher.end())
		{
			cout << "TID NOT EXIST!" << endl;
		}
		else
		{
			//如果现在存在sid相同的学生记录且这条记录存在导师信息，则在更改导师信息时需要删除掉原导师的学生列表中的此学生
			if (iterstu != mapStudent.end() && (iterstu->second)->getTutor() != NULL)
			{
				((iterstu->second)->getTutor())->studentList.erase(s->getSID());
			}

			s->setTutor(iter->second);
			(iter->second)->studentList.insert(s->getSID());
			cout << "DONE" << endl;
		}
	}
	else 
	{
		s->setTutor((iterstu->second)->getTutor());
	}
	//使用下标操作替代insert操作，在key已存在时修改value，在key不存在时创建。teacher中使用了相同的操作
	mapStudent[s->getSID()] = s;
	return 0;
}
void tutorFunc(Teacher* t, map<int, Student*> &mapStudent)
{
	char flag = ' ';
	int process;
	int sid;
	cout << "Would you like to update tutor info (y/n)" << endl;  //询问是否要更改指导学生的信息
	cin >> flag;
	while (flag == 'y' || flag == 'Y')
	{

		cout << "Student List:" << endl;
		for (auto iter = t->studentList.begin(); iter != t->studentList.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;

		cout << "Input job" << endl                       //提示输入职业
			<< "1 for insert,    2 for delete" << endl;
		cin >> process;
		cout << "Input SID:";
		cin >> sid;
		auto iter = mapStudent.find(sid);
		if (process == 1)
		{
			if (iter == mapStudent.end())
			{
				cout << "Student Not Found" << endl;
				goto a;
			}
			t->studentList.insert(sid);
			if ((iter->second)->getTutor() != NULL)
				(iter->second)->getTutor()->studentList.erase((iter->second)->getSID());
			(iter->second)->setTutor(t);
		}
		if (process == 2)
		{
			if (t->studentList.find(sid) == t->studentList.end())
			{
				cout << "Student Not Found" << endl;
				goto a;
			}
			(iter->second)->setTutor(NULL);
			t->studentList.erase(sid);
		}
		a : cout << "Continue updating tutor info? (y/n)" << endl;
		cin >> flag;
	}
}
int inputTeacher(map<int, Teacher*> &mapTeacher, map<int, Student*> &mapStudent)   //职业为老师的输入函数
{
	int job;
	cout << "------------------" << endl;
	cout << "Input job" << endl                       //提示输入职业
		<< "1 for Teacher,    2 for Chancellor" << endl
		<< "3 for Dean" << endl;
	cin >> job;
	cout << "------------------" << endl;

	if (job == 1)      //普通教师
	{
		Teacher *s = new Teacher;
		s->inputData(); 
		cout << "------------------" << endl;
		cout << *s;
		auto iterTea = mapTeacher.find(s->getTID());
		if (iterTea != mapTeacher.end() && iterTea->second->studentList.size() != 0)
		{
			s->studentList = iterTea->second->studentList;
		}
		tutorFunc(s, mapStudent);
		mapTeacher[s->getTID()] = s;
	}
	else if (job == 2)
	{
		Chancellor *s = new Chancellor;
		s->inputData();
		cout << "------------------" << endl;
		cout << *s;
		auto iterTea = mapTeacher.find(s->getTID());
		if (iterTea != mapTeacher.end() && iterTea->second->studentList.size() != 0)
		{
			s->studentList = iterTea->second->studentList;
		}
		tutorFunc(s, mapStudent);
		mapTeacher[s->getTID()] = s;
	}
	else if (job == 3)
	{
		Dean *s = new Dean;
		s->inputData();
		cout << "------------------" << endl;
		cout << *s;
		auto iterTea = mapTeacher.find(s->getTID());
		if (iterTea != mapTeacher.end() && iterTea->second->studentList.size() != 0)
		{
			s->studentList = iterTea->second->studentList;
		}
		tutorFunc(s, mapStudent);
		mapTeacher[s->getTID()] = s;
	}
	else   //处理错误输入的职业序号
	{
		cout << "Please input number 1-3" << endl;
		return -1;
	}

	return 0;
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
		<< "math:" << s.math << endl;
		if (s.tutor != NULL)
		{
			cout << "tutor's TID:" << s.tutor->getTID() << endl;
		}
		cout << "------------------" << endl;
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
		<< "Income:" << t.getIncome() << endl;
		if (t.studentList.begin() != t.studentList.end())
		{
			cout << "Student List:" << endl;
			for (auto iter = t.studentList.begin(); iter != t.studentList.end(); iter++)
			{
				cout << *iter << " ";
			}
			cout << endl;
		}
		cout << "------------------" << endl;
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
		<< "Income:" << c.getIncome() << endl;
		if (c.studentList.begin() != c.studentList.end())
		{
			cout << "Student List:" << endl;
			for (auto iter = c.studentList.begin(); iter != c.studentList.end(); iter++)
			{
				cout << *iter << " ";
			}
			cout << endl;
		}
		cout << "------------------" << endl;
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
		<< "Income:" << c.getIncome() << endl;
		if (c.studentList.begin() != c.studentList.end())
		{
			cout << "Student List:" << endl;
			for (auto iter = c.studentList.begin(); iter != c.studentList.end(); iter++)
			{
				cout << *iter << " ";
			}
			cout << endl;
		}
		cout << "------------------" << endl;
	return os;
}


//主函数
//===============================================
int main()
{
	char end = ' ';
	int operate, position, flag, id;
	int numStu = 0;
	int numT = 0;
	int numD = 0;
	int numC = 0;
	map<int, Student*> mapStudent;
	map<int, Teacher*> mapTeacher;

	while (end != 'Q' && end != 'q') //当用户输入Q或q时循环结束
	{
		cout << "------------------" << endl;
		cout << "1 for input or update,  2 for search" << endl
			<< "3 for delete" << endl;
		cin >> operate;             //询问需要执行的操作
		cout << "------------------" << endl;

		if (operate == 1)										//输入或修改
		{
			position = selectPosition();    //选择是老师还是学生
			if (position == 1)
			{
				flag = inputStudent(mapStudent, mapTeacher);
			}
			if (position == 2)
			{
				flag = inputTeacher(mapTeacher, mapStudent);
			}
		}
		else if (operate == 2)									//查询
		{
			position = selectPosition();
			cout << "Input " << ((position == 1) ? "S" : "T") << "ID:";
			cin >> id;
			if (position == 1)
			{
				auto iter = mapStudent.find(id);     //查找对应记录
				if (iter != mapStudent.end())        //找到则输出对应记录，找不到则输出没有找到
				{
					cout << *(iter->second);
				}
				else
				{
					cout << "Not Found!" << endl;
					cout << "------------------" << endl;
				}
			}
			if (position == 2)
			{
				auto iter = mapTeacher.find(id);
				if (iter != mapTeacher.end())
				{
					cout << *(iter->second);
				}
				else
				{
					cout << "Not Found!" << endl;
					cout << "------------------" << endl;
				}	
			}
		}
		else if (operate == 3)									//删除
		{
			position = selectPosition();
			cout << "Input " << ((position == 1) ? "S" : "T") << "ID:";
			cin >> id;
			if (position == 1)
			{
				auto iter = mapStudent.find(id);
				if (iter == mapStudent.end())
				{
					cout << "Not Found!" << endl;
					continue;
				}
				if((iter->second)->getTutor() != NULL)
				{
					((iter->second)->getTutor())->studentList.erase(id);
				}
				mapStudent.erase(id);
				cout << "DONE" << endl;
			}
			if (position == 2)
			{
				auto iter = mapTeacher.find(id);
				if (iter == mapTeacher.end())
				{
					cout << "Not Found!" << endl;
					continue;
				}
				if ((iter->second)->studentList.size() != 0)
				{
					for (auto x : (iter->second)->studentList)
					{
						mapStudent.find(x)->second->setTutor(NULL);
					}
				}
				mapTeacher.erase(id);
				cout << "DONE" << endl;
			}
			cout << "------------------" << endl;
		}
		else   //处理错误输入
		{
			cout << "Please input number 1-3" << endl;
			continue;
		}

		cout << "Input Q to quit, input other letter to continue."; //提示按Q退出程序，按其他键继续
		cin >> end;
	}
	cout << "Bye!";
	return 0;
}