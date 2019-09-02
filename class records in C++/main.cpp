//Declaring standard Libs
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include<bits/stdc++.h>
#include <string>
using namespace std;

struct student
{
    char fName[50], mName[50], lName[50]; int Mat[6];
};

//Created a Function that sorts Structure based on the Last Name
//Used strcmp which compares two strings together but in this case am comparing an array
//The Function takes the array and also the size of the array
//Created a Temp variable for swapping the original array with temp
void SortLname(student data[], int size )
{
    int j;
    student temp;
    for(int i = 1; i < size; i++)
    {
        j = i - 1;
        while( j >= 0 && strcmp( data[j+1].lName, data[j].lName ) < 0 )
        {
            temp =  data[j + 1];
            data[j+1] = data[j];
            data[j] = temp;
            j--;
        }
    }
}

int main()
{
     int input;int n; int i; int j;
    int last = 1;
    int num;
    while (last=num){
    cout << "What would you like to do ?" << endl;
    cout << "Option 1 : Add a Record" << endl;
    cout << "Option 2 : Sort records" << endl;
    cout << "Option 3 : Assign matric No" << endl;
    cout << "Option 4 : Show List of students" << endl;
    cin>>input;

    if(input == 1 || input == 2 || input == 3 || input == 4 ){
    if(input==1){
        cout<<"Option 1 Selected"<<endl;
        cout<<"How records do you want to enter ?"<<endl;
        cin>>n;
        cout << "Enter information" << endl;
        // Accepting User Information
            for(int j = 0; j < n; ++j)
            {
                struct student s[n];
                cout << "Input your First Name? ";
                cin >> s[j].fName;
                cout << "Input your Middle Name? ";
                cin >> s[j].mName;
                cout << "Input your Last Name? ";
                cin >> s[j].lName;
                cout << endl;
                if(j==n-1){
                    ofstream outfile;
                       outfile.open("studentsInfo.txt");
                       if (!outfile)
                            {
                                cout<<"Cannot load file"<<endl;
                            }
                        else{
                            cout << ".......Writing to the file........." << endl;

                            for (i = 0; i < n; ++i){
                                // write inputted data into the file.
                                outfile << s[i].lName << " " << s[i].mName <<  " " << s[i].fName << endl;
                                cout<<"Total Name successfully stored is "<< i << endl;
                            }
                            cout <<"All Names have been successfully saved"<<endl;
                            // close the opened file.
                            outfile.close();
                        }
                }
            }
    }else if(input ==2){
           cout<<"Option 2 Selected"<<endl;
           string line;
        ifstream outfile;
           outfile.open("studentsInfo.txt");
           if (!outfile)
                {
                    cout<<"Cannot load file"<<endl;
                }
            else{
                    int p = 1;
                   while(getline(outfile,line)){
                    cout<<line<<"\n";
                    SortLname(s,n);

     printf("\n\nStudent Records sorted by Last Name:\n");
    for (i = 0; i < n; i++) {
        printf("First Name = %s, Middle Name = %s, Last Name= %s \n",
               s[i].lName, s[i].mName, s[i].fName);
                   }outfile.close();
                }
    }
    else if(input == 3){
        cout<<"Option 3 Selected"<<endl;
        string line;
        ifstream outfile;
           outfile.open("studentsInfo.txt");
           if (!outfile)
                {
                    cout<<"Cannot load file"<<endl;
                }
            else{
                    int p = 1;
                   while(getline(outfile,line)){
                    cout<<line<<"\n";
                    srand((unsigned)time(0));
                    int low = 314580, high = 400000;
                    int range = (high,low)+1;

                    s[j].Mat = low + (range*rand()/RAND_MAX+1);
                    cout<<s[j].Mat;
                    p++;
                   }outfile.close();
                }
    }else if(input == 4){
        cout<<"Option 4 Selected"<<endl;
        string line;
        ifstream outfile;
           outfile.open("studentsInfo.txt");
           if (!outfile)
                {
                    cout<<"Cannot load file"<<endl;
                }
            else{
                   while(getline(outfile,line)){
                    cout<<line<<"\n";
                   }outfile.close();
                }
    }
    }else{
        cout<<"Wrong Option Selected ! ! !"<< endl;
    } cout<<"To perform any other operation \n Enter 1 \n else please enter any key"<<endl;
    cin>>num;
}cout<<"Thank you for using this program"<<endl;

}
