// My first program in C++

#include <iostream>

int main(){

  int integer = 1;
  float decimal = 1.0;
  bool flag = false;

  for(int i = 0; i < 5; ++i){
    // The "<<" in a print function for C++ operates like a "+" in java print outs

    std::cout << "Integer + i is " << integer+i << "\n";
    std::cout << "Decimal + i is " << decimal+i << "\n";

    // Boolean, when printed, returns 0 or 1! 0 = false, 1 = true

    std::cout << "The flag is " << flag << "\n\n";
    if(flag == false){
      flag = true;
    } else {
      flag = false;
    }
  }

}
