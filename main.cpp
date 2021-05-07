#include <iostream>
using std::string;

class iEmployee{
    virtual void askForPromotion() = 0;

};

class Employee:iEmployee {
protected:
    string name;
    string company;
    int age;

public:
    Employee(string name, string company, int age){
        setAge(age);
        setName(name);
        setCompany(company);
    }

    void setName(string name){
        this->name = name;

    }
    void setCompany(string company){
        this->company = company;

    }
    void setAge(int age){
        if(age < 18)
            return;
        this->age = age;
    }

    string getName(){return name;}
    string getCompany(){return company;}
    int getAge(){return age;}

    void introduction(){
        std::cout << name << company << age<< std::endl;
    }

    void askForPromotion() {
        if(age < 30){
            std::cout << getName() <<": plz gibe monis" << std::endl;
            std::cout << "Boss: lol no" << std::endl;
        } else {
            std::cout << getName() <<": plz gibe monis" << std::endl;
            std::cout << "Boss: sure my beloved" << std::endl;}
    }

    virtual void work(){
        std::cout << "Working..." << std::endl;
    }
};

class Developer:public Employee{
public:
    string especialitt;
    Developer(string name, string company, int age, string especialitt):Employee(name, company, age){
        this->especialitt = especialitt;
    }

    void work(){
        std::cout << "Documenting..." << std::endl;
    }
};

class Teacher:public Employee{
public:
    string subject;
    Teacher(string name, string company, int age, string subject):Employee(name, company, age){
        this->subject= subject;
    }
    void prepareLesson(){
        std::cout << "Class: " << subject  << std::endl;
        std::cout << "Teacher: " << name << std::endl;
    }


    void work(){
        std::cout << "Teaching..." << std::endl;
    }
};

int main(int argc, char **argv) {
    std::cout << "--------Employee--------" << std::endl;

    Employee empregado = Employee("nameOne", "comper", 21);

    empregado.introduction();

    empregado.setAge(32);

    empregado.askForPromotion();

    empregado.work();

    std::cout << "--------Developer--------" << std::endl;

    Developer deve = Developer("nametwo", "comperet", 25, "jaba");

    deve.introduction();

    deve.setAge(66);

    deve.askForPromotion();

    deve.work();

    std::cout << "--------Teacher--------" << std::endl;

    Teacher tech = Teacher("namereww", "compereterer", 31, "Maths");

    tech.prepareLesson();

    tech.askForPromotion();

    tech.work();

    std::cout << "--------End--------" << std::endl;

    Employee* ed = &deve;
    Employee* et = &tech;

    ed->work();
    et->work();

    return 0;
}
