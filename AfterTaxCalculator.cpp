#include <iostream>


int CalculateFedTax(int pretax){
    int FedTax;
    if(pretax <= 55867){
        FedTax = pretax*0.15;
    }else if (pretax <= 111733){
        FedTax = 55867*0.15;
        FedTax += (pretax - 55867)*0.205;
    }
    else if(pretax <= 173205){
        FedTax = 55867*0.15;
        FedTax += (111733 - 55867)*0.205;
        FedTax += (pretax - 111733)*0.26; 
    }
    else if(pretax <= 246752){
        FedTax = 55867*0.15;
        FedTax += (111733 - 55867)*0.205;
        FedTax += (173205 - 111733)*0.26; 
        FedTax += (pretax - 173205)*0.29; 
    }
    else{
        FedTax = 55867*0.15;
        FedTax += (111733 - 55867)*0.205;
        FedTax += (173205 - 111733)*0.26; 
        FedTax += (246752 - 173205)*0.29; 
        FedTax += (pretax - 246752)*0.33;
    }
    std::cout<<"Your total federal tax burden is: " << FedTax <<std::endl;
    return FedTax;
}

int CalculateBCTax(int pretax){
    int BCTax; 
    if(pretax <= 47937){
        BCTax = 47937 * 0.0506;  
    }else if (pretax <= 95875){
        BCTax = 47937 * 0.0506; 
        BCTax += (pretax-47937) * 0.077;
    }
    else if (pretax <= 110076){
        BCTax = 47937 * 0.0506; 
        BCTax += (95875-47937) * 0.077;
        BCTax += (pretax-95875) * 0.105;
    }
    else if (pretax <= 133664){
        BCTax = 47937 * 0.0506; 
        BCTax += (95875-47937) * 0.077;
        BCTax += (110076-95875) * 0.105;
        BCTax += (pretax-110076) * 0.1229;
    }
    else if (pretax <= 181232){
        BCTax = 47937 * 0.0506; 
        BCTax += (95875-47937) * 0.077;
        BCTax += (110076-95875) * 0.105;
        BCTax += (133664-110076) * 0.1229;
        BCTax += (pretax-133664) * 0.147;
    }
    else if (pretax <= 252752){
        BCTax = 47937 * 0.0506; 
        BCTax += (95875-47937) * 0.077;
        BCTax += (110076-95875) * 0.105;
        BCTax += (133664-110076) * 0.1229;
        BCTax += (181232-133664) * 0.147;
        BCTax += (pretax-181232) * 0.168;
    }
    else{
        BCTax = 47937 * 0.0506; 
        BCTax += (95875-47937) * 0.077;
        BCTax += (110076-95875) * 0.105;
        BCTax += (133664-110076) * 0.1229;
        BCTax += (181232-133664) * 0.147;
        BCTax += (252752-181232) * 0.168;
        BCTax += (pretax-252752) * 0.205;
    }
    std::cout<<"Your total BC tax burden is: " << BCTax <<std::endl;
    return BCTax;
}

int CalculateEICPP(int pretax){
    int EIPay = 0;
    int CPPPay = 0;
    int totalEICPP = 0;
    if (pretax <= 65700){
        EIPay =  pretax * 0.0164; //using 2025 numbers
    }else{
        EIPay = 65700*0.0164; 
    }
    if(pretax <= 3500){
        CPPPay = 0; 
    }else if (pretax <= 71300){ //2025 numbers from https://www.canada.ca/en/revenue-agency/services/tax/businesses/topics/payroll/payroll-deductions-contributions/canada-pension-plan-cpp/cpp-contribution-rates-maximums-exemptions.html#dt2
        CPPPay = (pretax-3500)*0.0596; 
    }else{
        CPPPay = 67800*0.0595;
    }
    std::cout << "Your total EI contribution is " << EIPay << " And your total CPP contribution is " << std::endl;
    totalEICPP = CPPPay + EIPay;
    return totalEICPP; 
}

int main(){
    int pretax = 0;
    std::cout << "Please enter your pre-tax include (to the nearest whole dollar)" << std::endl;
    std::cin >> pretax; 
    std::cout << "Your pre-tax income is " <<pretax << std::endl; 
    int totalTax = 0;
    totalTax = CalculateFedTax(pretax) + CalculateBCTax(pretax) + CalculateEICPP(pretax);
    int afterTax = pretax - totalTax; 
    std::cout << "Your total tax burden is " << totalTax << " and your after tax income is " << afterTax << std::endl;

}

//todo: 
//Incorperate the basic personal ammount tax credit 