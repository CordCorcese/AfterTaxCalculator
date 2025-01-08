#include <iostream>


int CalculateFedTax(int pretax){
    int fedbasicammount = 16129;
    int FedTax;
    int fedbracket1 = 57375; 
    int fedbracket2 = 114750;
    int fedbracket3 = 177882; 
    int fedbracket4 = 253414;

    //Amounts and rates are set for the 2025 tax year

    if(pretax <= fedbracket1){
        FedTax = (pretax-fedbasicammount)*0.15;
    }else if (pretax <= fedbracket2){
        FedTax = fedbracket1*0.15;
        FedTax += (pretax - fedbracket1)*0.205;
    }
    else if(pretax <= fedbracket3){
        FedTax = fedbracket1*0.15;
        FedTax += (fedbracket2 - fedbracket1)*0.205;
        FedTax += (pretax - fedbracket2)*0.26; 
    }
    else if(pretax <= fedbracket4){
        FedTax = fedbracket1*0.15;
        FedTax += (fedbracket2 - fedbracket1)*0.205;
        FedTax += (fedbracket3 - fedbracket2)*0.26; 
        FedTax += (pretax - fedbracket3)*0.29; 
    }
    else{
        fedbasicammount = 14538; 
        FedTax = fedbracket1*0.15;
        FedTax += (fedbracket2 - fedbracket1)*0.205;
        FedTax += (fedbracket3 - fedbracket2)*0.26; 
        FedTax += (fedbracket4 - fedbracket3)*0.29; 
        FedTax += (pretax - fedbracket4)*0.33;
    }
    FedTax = FedTax - (fedbasicammount*0.15); 
    if (FedTax < 0){
        FedTax = 0; 
    }
    std::cout<<"Your total federal tax burden is: " << FedTax <<std::endl;
    return FedTax;
}

int CalculateBCTax(int pretax){
    int BCTax; 
    int BCBasicAmmount = 12932; 
    int BCBracket1 = 49279; 
    float BCRate1 = 0.0506; 
    int BCBracket2 = 98560;
    float BCRate2 = 0.077;
    int BCBracket3 = 113158; 
    float BCRate3 = 10.50;
    int BCBracket4 = 137407; 
    float BCRate4 = 0.1229; 
    int BCBracket5 = 186306;
    float BCRate5 = 0.147; 
    int BCBracket6 = 259829;
    float BCRate6 = 0.168;
    float BCRate7 = 0.205; 

    //All ammounts are for the 2025 tax year

    if(pretax <= BCBracket1){
        BCTax = pretax * BCRate1;  
    }
    else if (pretax <= BCBracket2){
        BCTax = BCBracket1 * BCRate1; 
        BCTax += (pretax-BCBracket1) * BCRate2;
    }
    else if (pretax <= BCBracket3){
        BCTax = BCBracket1 * BCRate1; 
        BCTax += (BCBracket2-BCBracket1) * BCRate2;
        BCTax += (pretax-BCBracket2) * BCRate3;
    }
    else if (pretax <= BCBracket4){
        BCTax = BCBracket1 * BCRate1; 
        BCTax += (BCBracket2-BCBracket1) * BCRate2;
        BCTax += (BCBracket3-BCBracket2) * BCRate3;
        BCTax += (pretax-BCBracket3) * BCRate4;
    }
    else if (pretax <= BCBracket5){
        BCTax = BCBracket1 * BCRate1; 
        BCTax += (BCBracket2-BCBracket1) * BCRate2;
        BCTax += (BCBracket3-BCBracket2) * BCRate3;
        BCTax += (BCBracket4-BCBracket3) * BCRate4;
        BCTax += (pretax-BCBracket4) * BCRate5;
    }
    else if (pretax <= BCBracket6){
        BCTax = BCBracket1 * BCRate1; 
        BCTax += (BCBracket2-BCBracket1) * BCRate2;
        BCTax += (BCBracket3-BCBracket2) * BCRate3;
        BCTax += (BCBracket4-BCBracket3) * BCRate4;
        BCTax += (BCBracket5-BCBracket4) * BCRate5;
        BCTax += (pretax-BCBracket5) * BCRate6;
    }
    else{
        BCTax = BCBracket1 * BCRate1; 
        BCTax += (BCBracket2-BCBracket1) * BCRate2;
        BCTax += (BCBracket3-BCBracket2) * BCRate3;
        BCTax += (BCBracket4-BCBracket3) * BCRate4;
        BCTax += (BCBracket5-BCBracket4) * BCRate5;
        BCTax += (BCBracket6-BCBracket5) * BCRate6;
        BCTax += (pretax-BCBracket6) * BCRate7;
    }
    BCTax = BCTax - BCBasicAmmount*BCRate1; 
    if(BCTax < 0){
        BCTax = 0;
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
    std::cout << "Your total EI contribution is " << EIPay << " And your total CPP contribution is " << CPPPay << std::endl;
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