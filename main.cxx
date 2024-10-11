#include <iostream>
#include <string>

int usage(){
    std::cout << "=========" << std::endl;
    std::cout << "Wrong number of arguments!" << std::endl;
    std::cout << "You need to provide 2 (two) arguments!" << std::endl;
    std::cout << "Example: <programName> <argument 1> <argument 2>" << std::endl;
    std::cout << "=========" << std::endl;

    return 1;
}

int compCharSum(const std::string &input){
    int charSum = 0;
    for (int index = 0; index < static_cast<int>(input.size()); ++index){
    charSum += input[index];}
    return charSum;
}

int calcKey(int charSum, char arg1, int programNameLen){
    return (charSum ^ arg1 * 3) << (programNameLen & 0x1f);
}

int main(int argCount, char *argValues[]) {
bool reqArgCount = (argCount == 3);
  if (reqArgCount) {
    std::string programName{argVals[0]};
    auto arg1{*(argVals[1])};
    auto programNameLen{programName.size()};
    auto arg2{std::atoi(argVals[2])};
    std::string arg1text{argVals[1]};
    
    int charSum = compCharSum(arg1text);
    std::cout << "Calculated checksum:" << charSum << std::endl;

    int compKey = calcKey(charSum, arg1, programNameLen);
    std::cout << "Calculated key:" << compKey << std::endl;

    std::cout << "Expected key:" << arg2 << std::endl;

    if (compKey == arg2) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
  else{
    usage();
  }
}
