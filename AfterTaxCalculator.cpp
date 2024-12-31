#include <iostream>


int CalculateFedTax(int pretax){
    int afterTax;
    if(pretax <= 55867){
        afterTax = pretax*0.15;
    }else if (pretax <= 111733){
        afterTax = 55867*0.15;
        afterTax += (pretax - 55867)*0.205;
    }
    else if(pretax <= 173205){
        afterTax = 55867*0.15;
        afterTax += (111733 - 55867)*0.205;
        afterTax += (pretax - 111733)*0.26; 
    }
    else if(pretax <= 246752){
        afterTax = 55867*0.15;
        afterTax += (111733 - 55867)*0.205;
        afterTax += (173205 - 111733)*0.26; 
        afterTax += (pretax - 173205)*0.29; 
    }
    else{
        afterTax = 55867*0.15;
        afterTax += (111733 - 55867)*0.205;
        afterTax += (173205 - 111733)*0.26; 
        afterTax += (246752 - 173205)*0.29; 
        afterTax += (pretax - 246752)*0.33;
    }
    std::cout<<"Your total federal tax burden is: " << afterTax <<std::endl;
    return afterTax;
}

int CalculateBCTax(int pretax){
    //todo 
    return 0;
}

int main(){
    int pretax = 0;
    std::cout << "Please enter your pre-tax include (to the nearest whole dollar)" << std::endl;
    std::cin >> pretax; 
    std::cout << "Your pre-tax income is " <<pretax << std::endl; 
    int totalTax = 0;
    totalTax = CalculateFedTax(pretax) + CalculateBCTax(pretax);
    int afterTax = pretax - totalTax; 

}

//todo: 
//Incorperate EI payments
//Incorperate the basic personal ammount tax credit 