//Name: Ahmet Sabri MERT
//Course: Programming for Engineering. 64170031, Fall, 2020
//Purpose:The purpose of this program is to print the information of doctors and
//patients and desired features using the necessary structures,
//functions and file operations.
//Written in C++ language.

#include<iostream>
#include<string.h>
#include<fstream>
#include <sstream>

using namespace std;

//structs for patient and doctor
struct patient{
   string name;
   int ID;
   int noOfDoctors;
};

struct doctor{
   string name;
   string specialty;
   int officeNumber;
   int age;
};

// read patient data from user.
void readPatients(patient p[3]){
   cout <<"3 Patients Data: " <<endl;
   cout << endl;
   for(int i=0;i<3;i++){
       cout <<"Enter Patient Name: ";
       cin >> p[i].name;
       cout <<"\nEnter Patient ID: ";
       cin >> p[i].ID;
       cout <<"\nEnter number of doctors treating the patient: ";
       cin >> p[i].noOfDoctors;
       cout << endl<<endl;
   }  
}

void displayPatients(patient p[3]){
   cout <<"\nPatient Information: "<<endl;
   cout <<endl;
   for(int i=0;i<3;i++){
   cout << "Patient Name: "<<p[i].name<<endl;
   cout << "Patient ID: "<<p[i].ID<<endl;
   cout << "Number of doctors that treating the patient: "<<p[i].noOfDoctors<<endl;
   cout <<endl;
   }
}

//read doctor data from user.
void readDoctors(doctor d[7]){
   cout <<"7 Doctors Data: " <<endl;
   cout << endl;
   for(int i=0;i<7;i++){
       cout <<"Enter Doctor's Name: ";
       cin >> d[i].name;
       cout <<"\nEnter Doctor's Specialty': ";
       cin >> d[i].specialty;
       cout <<"\nEnter Doctor's Office Number: ";
       cin >> d[i].officeNumber;
       cout <<"\nEnter Doctor's Age: "<<endl;
       cin >> d[i].age;
   }
}

void displayDoctors(doctor d[7]){
   cout <<"\nDoctor Information: "<<endl;
   cout <<endl;
   for(int i=0;i<7;i++){
   cout << "Doctor Name: "<<d[i].name<<endl;
   cout << "Doctor's Specialty: "<<d[i].specialty<<endl;
   cout << "Doctor's Office Number: "<<d[i].officeNumber<<endl;
   cout << "Doctor's Age: "<<d[i].age<<endl;
   cout <<endl;
   }
}

//doctors equality checking function.
void equalityDoctor(doctor d1,doctor d2){
   int res=0;
  
   if(d1.officeNumber == d2.officeNumber){
       res = (d1.name).compare(d2.name);
       if(res==0)
           cout << "Doctor's is equal."<<endl;
   }
}

//function to define which patient should be treated first.
void checkPatients(patient p1,patient p2){
   if(p1.ID > p2.ID){
       if(p1.noOfDoctors>p2.noOfDoctors){
           cout <<"Patient Name "<<p1.name<<" is in the first." <<endl;
       }
       else{
           cout <<"They can be treated in any order"<<endl;
       }
   }
   else if(p2.ID>p1.ID){
       if(p1.noOfDoctors<p2.noOfDoctors){
           cout <<"Patient Name "<<p2.name<<" is in the first." <<endl;
       }
       else{
               cout <<"They can be treated in any order"<<endl;
       }
   }
}

//Function that read data from text file.Also, creating text file.
void readData(char *s,patient p1[3],doctor d1[7]){
   ifstream file;
   string line;
   int checkDoctor=-1,checkPatient=-1,temp=0;
   file.open(s);
   while (!file.eof())
{
   getline(file, line);
   checkDoctor = line.compare("Doctors:");
   checkPatient = line.compare("Patients:");
if(checkDoctor==0){
  
   for(int i=0;i<7;i++){
       getline(file,line);
       d1[i].name=line;
       getline(file,line);
       d1[i].specialty=line;
       getline(file,line);
       stringstream offNum(line);
       offNum>>temp;
       d1[i].officeNumber=temp;
       getline(file,line);
       stringstream Age(line);
       Age>>temp;
       d1[i].age=temp;
           }
       }
       else if(checkPatient==0){
           for(int i =0;i<3;i++){
                   getline(file,line);
                   p1[i].name=line;
                   getline(file,line);
                   stringstream id(line);
           id>>temp;
                   p1[i].ID=temp;
                   getline(file,line);
                   stringstream nod(line);
           nod>>temp;
                   p1[i].noOfDoctors=temp;
           }
       }
}
file.close();
  
ofstream myfileOne,myfileTwo;
myfileOne.open("doctors.txt");
myfileOne<<"Doctors: \n"<<endl;
for(int i =0;i<7;i++){
   myfileOne <<"Doctor Name: "<< d1[i].name <<endl;
   myfileOne<<"Doctor Specialty: "<< d1[i].specialty<<endl;
   myfileOne<<"Doctor OfficeNumber: "<<d1[i].officeNumber<<endl;
   myfileOne<<"Doctor Age: "<<d1[i].age<<endl;
   myfileOne<<endl;
   }
   myfileOne.close();
   myfileTwo.open("patients.txt");
   myfileTwo <<"Patients: \n"<<endl;
   for(int i=0;i<3;i++){
       myfileTwo<<"Patient Name: "<<p1[i].name<<endl;
       myfileTwo<<"Patient ID: "<<p1[i].ID<<endl;
       myfileTwo<<"Patient's attending doctor count: "<<p1[i].noOfDoctors<<endl;
       myfileTwo<<endl;
   }
}

int main(){
   patient patData[3];
   doctor docData[7];
   char *s=(char *)"data.txt";
   cout <<"Output for the values from text file"<<endl<<endl;
   readData(s,patData,docData);
   displayPatients(patData);
   displayDoctors(docData);
  
   cout<<"Patient Checker: "<<patData[0].name<<" & "<<patData[1].name<<endl;
   checkPatients(patData[0],patData[1]);
  
   cout <<"Equality Checker for doctors: "<<docData[0].name<<" & "<<docData[0].name<<endl;
   equalityDoctor(docData[0],docData[1]);
  
   cout << "\n\nPrompt function to read the data: "<<endl<<endl;
   readDoctors(docData);
   readPatients(patData);
   cout <<"\nDisplay output for prompt data: "<<endl<<endl;
   displayPatients(patData);
   displayDoctors(docData);
   
   cout<<"Patient Checker: "<<patData[0].name<<" & "<<patData[1].name<<endl;
   checkPatients(patData[0],patData[1]);
  
   cout <<"Equality Checker for doctors: "<<docData[0].name<<" & "<<docData[0].name<<endl;
   equalityDoctor(docData[0],docData[1]);
  
}
