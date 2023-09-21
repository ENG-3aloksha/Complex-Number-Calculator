// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: complex.cpp
// Program Description: Program that calculate complex numbers
// Last Modification Date: 29/03/2022
// Author1 and ID and Group: Ali Mahmoud Mahmoud Awad - 20210249 - S9,S10
// Author2 and ID and Group: Abdelfattah Mohamed Abdelbaset Mousa - 20210215 - S9,S10
// Author3 and ID and Group: Maria Mohamed Bassam Badran - 20210786 - S9,S10
// Teaching Assistant: ENG.Afaf
// Purpose: ciphering and deciphering
#include <iostream>
#include <complex>
#include <string>
#include<algorithm>
using namespace std;


void complexxx(double rel1 , double rel2,double img1,double img2, string op){
    std::complex <double>  first(rel1 , img1);
    std::complex <double>  second( rel2 , img2);
    std::complex <double>  third;

    if(op == "*"){
        third = (first * second);
    }

   else if(op == "+"){
        third = (first + second);
    }
    else if(op == "-"){
        third = (first - second);
    }
    else if(op == "/"){
        third = (first / second);
    }
if (imag(third) >= 0)
{
    cout <<"("<< real(third) << "+" << imag(third) << "i"<<")" << endl;
}
else {
    cout <<"("<< real(third) << imag(third) << "i" <<")" << endl;
}

}
int main()
{
    string comp1,comp2,numbers1,numbers2,op;
    char sign;
    double rel1,rel2,img1,img2;
    int flag;
    int validation_num =1;
    bool check = true;
    bool flag1 = true;
    while(check){
        cout<<"please enter the statement:  ";
        if(validation_num == 1){
            cin.clear();
            cin.sync();
            getline(cin,comp1,')');
            comp1.erase(remove(comp1.begin(), comp1.end(), '('), comp1.end());
            for (int i =0; i<comp1.size(); i++){
                if((i == 0) && (comp1[i] == '-'))
                {
                    numbers1 += comp1[i];
                }

                else if(isdigit(comp1[i])){
                    numbers1 += comp1[i];
                }
                else if (comp1[i] == '.')
                {
                    numbers1 += comp1[i];
                }
                else if((comp1[i]=='+') || (comp1[i]=='-')){
                    numbers2 = comp1[i];
                    flag = i+1;
                    break;
                }
                else{
                    cout << "invalid number please try again."<<endl;
                    comp1 = "";
                    numbers1 ="";
                    flag1 =false;
                    break;
                }


            }


            if(!flag1){

                flag1 = true;
                continue;
            }



            for (int i =flag; i<comp1.size(); i++){
                if(isdigit(comp1[i])){
                    numbers2 += comp1[i];
                }
                else if (comp1[i] == '.')
                {
                    numbers2 += comp1[i];
                }
                 else if ((comp2[i] == 'i')&&(flag == i)){
                    numbers2 += '1';
                }
                else if(comp1[i]=='i'){

                    break;
                }
                else{
                    cout << "invalid number please try again."<<endl;
                    comp1 = "";
                    numbers1 ="";
                    numbers2 ="";
                    flag1 =false;
                    break;
                }
            }

            if(!flag1){
                flag1 = true;
                continue;


            }
        }
        rel1 = stod(numbers1);
        img1 = stod(numbers2);

        numbers1 = "";
        numbers2 = "";
        validation_num = 2;
        getline(cin,op,'(');

        if(validation_num == 2){
            getline(cin,comp2,')');
            for (int i =0; i<comp2.size(); i++){
                if((i == 0) && (comp2[i] == '-')){
                    numbers1 += comp2[i];
                }

                else if(isdigit(comp2[i])){
                    numbers1 += comp2[i];
                }
                else if (comp2[i] == '.')
                {
                    numbers1 += comp2[i];
                }
                else if((comp2[i]=='+') || (comp2[i]=='-')){
                    numbers2 = comp2[i];
                    flag = i+1;
                    break;
                }
                else{
                    cout << "invalid number please try again."<<endl;
                    comp2 = "";
                    numbers1 ="";
                    flag1 =false;
                    break;
                }


            }


            if(!flag1){

                flag1 = true;
                continue;
            }


            for (int i =flag; i<comp2.size(); i++){
                if(isdigit(comp2[i])){
                    numbers2 += comp2[i];
                }
                else if (comp2[i] == '.')
                {
                    numbers2 += comp2[i];
                }
                else if ((comp2[i] == 'i')&&(flag == i)){
                    numbers2 += '1';
                }
                else if(comp2[i]=='i'){

                    break;
                }
                else{
                    cout << "invalid number please try again."<<endl;
                    comp2 = "";
                    numbers1 ="";
                    numbers2 ="";
                    flag1 =false;
                    break;
                }
            }
            if(!flag1){
                flag1 = true;
                continue;


            }

        }


        rel2 = stod(numbers1);
        img2 = stod(numbers2);
        numbers1 = "";
        numbers2 = "";
        validation_num = 1;
        complexxx(rel1,rel2,img1,img2,op );
        cin.clear();
        cin.sync();
        cout << "if you want to do another operation press any button & if you want to exit press N\n";
        cin >> sign;
        if (tolower(sign) == 'n'){
            check = false;
            cout << "Good Bye!";
        }
    }

}

