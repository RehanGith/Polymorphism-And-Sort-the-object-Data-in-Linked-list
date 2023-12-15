#include <iostream>
#include <string>
#define MAX 100
using namespace std;
class Person {
protected:
	string name;
	string cnic;
	Person* next;
public:
	Person(string n = "", string c = "");
	virtual void setter();
	virtual void getter();
	Person*& get_next();
	void set_next(Person*& source);
	virtual void isoutstanding() = 0;
	virtual ~Person() { }
};
Person::Person(string n, string c)
	: name(n), cnic(c), next(nullptr) {

}

void Person::setter() {
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter cnic: ";
	cin.ignore();
	getline(cin, cnic);
}
void Person::getter() {
	cout << "Name: " << name << "  cnic: " << cnic << endl;
}
Person*& Person::get_next() {
	return next;
}
void Person::set_next(Person*& source) {
	next = source;
}
class Student : virtual public Person {
	string degree_program;
	float cgpa;
public:
	Student(string n = "", string c = "", string d = "", float g = 0.0);
	void setter();
	void getter();
	void isoutstanding() override;
	~Student() { }
};
Student::Student(string n, string c, string d, float g)
	: Person(n, c), degree_program(d), cgpa(g) {

}
void Student::setter() {
	Person::setter();
	cout << "Enter degree Program: ";
	getline(cin, degree_program);
	while (true) {
		cout << "Enter cgpa: ";
		cin >> cgpa;
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "Inncorrect Input\n";
		cin.ignore(10, '\n');
	}
}
void Student::getter() {
	Person::getter();
	cout << "Degree Program: " << degree_program << " cgpa: " << cgpa << endl;
}
void Student::isoutstanding() {
	if (cgpa > 3.0) {
		cout << "***Outstanding****" << endl;
	}
}
class Teacher : virtual public Person {
	string deperatment;
	int no_of_publication;
public:
	Teacher(string n = "", string c = "", string d = "", int no = 0);
	void setter();
	void getter();
	void isoutstanding() override;
	~Teacher() {

	}
};
Teacher::Teacher(string n, string c, string d, int no)
	: Person(n, c), deperatment(d), no_of_publication(no) {

}
void Teacher::setter() {
	Person::setter();
	cout << "Enter Department: ";
	getline(cin, deperatment);
	while (true) {
		cout << "NO of Publication: ";
		cin >> no_of_publication;
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "Inncorrect Input\n";
		cin.ignore(10, '\n');
	}
}
void Teacher::getter() {
	Person::getter();
	cout << "Department: " << deperatment << "  no of Publication: " << no_of_publication << endl;
}
void Teacher::isoutstanding() {
	if (no_of_publication > 10) {
		cout << "***OutStanding***" << endl;
	}
}

int main() {
	int choice{}, n{}, nt{}, ns{};
	Person* head{ nullptr }, * prev{ nullptr }, * cur{ nullptr };

	while (true) {
		cout << "Menu\n"
			<< "1: Create Teacher\n"
			<< "2: Create Student\n"
			<< "3: Display All\n"
			<< "4: Dispaly number\n"
			<< "5: Display Teacher\n"
			<< "6: Display Student\n"
			<< "7: Exit" << endl;
		while (true) {
			cout << "Which option you wants to choose: ";
			cin >> choice;
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "Inncorrect Input\n";
			cin.ignore(10, '\n');
		}
		switch (choice) {
		case 1: {// Create a Teacher
			cur = new Teacher;
			cur->setter();
			if (prev)
				prev->set_next(cur);
			prev = cur;
			if (!head)
				head = cur = prev;
			n++;
			nt++;
			break;
		}
		case 2: { //Create a Student
			cur = new Student;
			cur->setter();

			if (prev)
				prev->set_next(cur);
			prev = cur;
			if (!head)
				head = cur;
			n++;
			ns++;
			break;
		}
		case 3:  //Display all
			cur = head;
			while (cur) {
				//if (typeid(cur).name() == Student) {
					cur->getter();
					cur->isoutstanding();
				//}
				cur = cur->get_next();

			}
			break;
		case 4:
			cout << "Number of teachers: " << nt << endl;
			cout << "Number of Student: " << ns << endl;
			break;
		case 5: 
			cur = head;
			while (cur) {
				string cl;
				cl = typeid(*cur).name();
				cout << "Class name: " << cl << endl;
				if (cl == "class Teacher") {
					cur->getter();
					cur->isoutstanding();
				}
				cur = cur->get_next();
			}
			break;
		case 6:
			cur = head;
			while (cur) {
				string cl;
				cl = typeid(*cur).name();
				cout << "Class name: " << cl << endl;
				if (cl == "class Student") {
					cur->getter();
					cur->isoutstanding();
				}
				cur = cur->get_next();
			}
			break;
		case 7:
			while (!head) {
				Person* next = head->get_next();
				delete head;
				head = next;
			}
			return 0;
		default:
			cout << "You enter wrong choice" << endl;
			break;
		}
	}

	return 0;
}