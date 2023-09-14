#include <iostream>
#include<vector>
using namespace std;

class Course {
protected:			//encapsulation
    string courseName;
    string teacherName;
    double obtainMarks;

public:
    Course(const string& name, const string& teacher, double marks)
        : courseName(name), teacherName(teacher), obtainMarks(marks) {}

// Abstruction

    virtual void display() = 0;
    virtual double calculatePoints() = 0;
};

//inheritance

class ObjectOrientedProgram : public Course {
public:
    ObjectOrientedProgram()
        : Course("Object Oriented Program", "Mahadi Hasan", 4.00) {}

    void display() {
        cout << "Course name: " << courseName << "\n";
        cout << "Teacher name: " << teacherName << "\n";
        cout << "Obtain marks: " << obtainMarks << "\n";
    }

    double calculatePoints()  {
        return obtainMarks;
    }
};

//inheritance

class DataStructure : public Course {
public:
    DataStructure()
      : Course("Data Structure", "Sezan Mahmud", 3.75) {}

//polymorphism

    void display() {
        cout << "Course name: " << courseName << "\n";
        cout << "Teacher name: " << teacherName << "\n";
        cout << "Obtain marks: " << obtainMarks << "\n";
    }

    double calculatePoints()  {
        return obtainMarks;
    }
};


//inheritance

class DiscreteMath : public Course {
public:
    DiscreteMath()
         :Course("Discrete Math", "Rumana Khatun", 4.00) {}

//polymorphism

    void display() override {
        cout << "Course name: " << courseName << "\n";
        cout << "Teacher name: " << teacherName << "\n";
        cout << "Obtain marks: " << obtainMarks << "\n";
    }

    double calculatePoints()  {
        return obtainMarks;
    }
};

//inheritance

class Math : public Course {
public:
    Math()
        : Course("Math", "Fatema Khatun", 3.00) {}
//polymorphism

    void display() override {
        cout << "Course name: " << courseName << "\n";
        cout << "Teacher name: " << teacherName << "\n";
        cout << "Obtain marks: " << obtainMarks << "\n";
    }

    double calculatePoints() {
        return obtainMarks;
    }
};

class Student {
private:			//encapsulation
    string studentName;
    int id;
    double cgpa;
   vector<Course*> courses;

public:

//consreuctor

    Student(const string& name, int studentId, double studentCgpa)
        : studentName(name), id(studentId), cgpa(studentCgpa) {}

    void addCourse(Course* course) {
        courses.push_back(course);
    }

    void displayResultSheet() {
        cout << "I am a student. In Northern University\n";
        cout << "Student Name: " << studentName << "\n";
        cout << "Id: " << id << "\n";
        cout << "Previous cgpa: " << cgpa << "\n";
        cout << "Program: CSE\n";
        cout << "_______________________\n";

        double totalPoints = 0.0;
        for (Course* course : courses) {
            course->display();
            totalPoints += course->calculatePoints();
        }

        double average = totalPoints / courses.size();
        cout << "Total Point: " << average << "\n";

        if (average >= 3) {
            cout << "Good Student\n";
        } else {
            cout << "Bad Student\n";
        }
    }

//destructor

    ~Student() {
        for (Course* course : courses) {
            delete course;
        }
    }
};
class result{
    public:
virtual void resultQuality()=0;

};
class Final : public result{
public:
    void resultQuality(){
    cout<<"pass"<<endl;
    }

};
int main() {
    Student student("SAMIUL HOSSAIN",415, 3.81);
    student.addCourse(new ObjectOrientedProgram());
    student.addCourse(new DataStructure());
    student.addCourse(new DiscreteMath());
    student.addCourse(new Math());

    student.displayResultSheet();
    result *r;
    Final f;
    r=&f;
    r->resultQuality();
    return 0;
}
