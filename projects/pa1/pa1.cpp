#include <iostream>
// Assignment 1 
// Luke Pfeiffer 
// 43634185

// Swap the two values so that the pointers point
// to the other's value
void swap(int & a, int & b){
  int temp = a;
  a = b;
  b = temp;
}

// Takes in a 1 D just prints out the contents
void printArray(int * array, int length){
  std::string returnString = "";

  for(int i = 0; i < length; ++i){
    std::cout << array[i] << " ";
  }

  std::cout << std::endl;
}


// Method prints the magic square
// Takes in a 2 D array and the length of the arrays
void printSquare(int ** magicSquare, int length){
  for(int i = 0; i < length; ++i){
    for(int j = 0; j < length; ++j){
      std::cout << magicSquare[i][j] << " ";

    }
    std::cout << std::endl;
  }
}

//Per this project's rules, if the length of the magic
//square does not meet these conditions, return false.
//Takes in the length of the array
bool isValidNum(int length){
  return length%2 != 0 && (length <=15 && length >= 3) ;
}

// Returns the diagonal sum of the magicSquare
// Takes in a two d array and the lenght of the arrays
int * diagonalSums(int ** magicSquare, int length){
  // There will only ever be two diagonals...
  int * diagonalSums = new int[2];
  int sumOne = 0;
  int sumTwo = 0;

  // Loop once, adding array[0][0], array[1][1]...
  // This will be the "\" diagonal
  for(int i = 0; i < length; ++i){
    sumOne += magicSquare[i][i];
  }
  diagonalSums[0] = sumOne;

  // Loop once, assuming n = 3, array[2][2], array[1][1]...
  // This will be the "/" diagonal
  for(int i = 0; i < length; ++i){
    int index = length - i - 1;
    sumTwo += magicSquare[index][index];
  }
  diagonalSums[1] = sumTwo;

  return diagonalSums;
}

// Returns the row sum of the magicSquare
// Takes in a two d array and the lenght of the arrays

int * rowSums(int ** magicSquare, int length){
  // Num rows will equal the length the user inputs
  int * rowSums = new int [length];

  // Sum each row
  for(int i = 0; i < length; ++i){

    // Sum will reset every i'th iteration
    int sum = 0;

    for(int j = 0; j < length; ++j){
      // Iterate accros row and add the values at each index
      sum += magicSquare[i][j];
    }
    // Add the sum to the returned array
    rowSums[i] = sum;
  }

  return rowSums;
}

// Returns the col sum of the magicSquare
// Takes in a two d array and the lenght of the arrays
int * colSums(int ** magicSquare, int length){
  // Num rows will equal the length the user inputs
  int * colSums = new int [length];

  for(int i = 0; i < length; ++i){
    // Sum will reset every i'th iteration
    int sum = 0;

    for(int j = 0; j < length; ++j){
      // Iterate accros col and add the values at each index
      sum += magicSquare[j][i];
    }
    
    // Add the sum to the returned array
    colSums[i] = sum;
  }

  return colSums;
}

// Set the numbers inside of the magic square
// Takes in a 2 D array, and the length of the arrays
void setMagicSquare(int ** magicSquare, int length){
  // Declare variables
  int termOne, termTwo;

  for(int i = 0; i < length; ++i){
    for(int j = 0; j < length; ++j){
      // This is the algorithm for calculating perfect square
      termOne = length * ( (i+1 + j  + (length/2) ) % length );
      termTwo = ( ( (i+1) + (2 * (j+1)) - 2) % length ) + 1;
      magicSquare[i][j] = termOne + termTwo;
    }
  }
}

//Not quite a rotation of 90 degress, it reflects the array across
//the y = -x axis.
//Takes in a magic square and the length of the array
void diagonalReflect(int ** magicSquare, int length){
  for(int i = 0; i < length; ++i){
    for(int j = i+1; j < length; ++j){
      // This causes a reflection across the line I mentioned above
      swap(magicSquare[i][j], magicSquare[j][i]);
    }
  }
}

//Will rotate the array 180 degrees
//Takes in a magic square and the length of the array
void rotate180(int ** magicSquare, int length){
  for(int i = 0; i < (length/2); ++i){
    int * temp = magicSquare[i];
    magicSquare[i] = magicSquare[length-1-i];
    magicSquare[length-1-i] = temp;
  }
}

// This will reflect the square across the y axis
// takes in a two d array and the length of square
void reflectSquare(int ** magicSquare, int length){
  for(int i = 0; i < length; ++i){
    for(int j = 0; j < (length/2); ++j){
      int col = length - 1 - j;
      swap(magicSquare[i][j], magicSquare[i][col]);
    }
  }
}

int main(){
  int length;
  std::cout << "Please input size of magic square:" << std::endl;
  std::cin >> length;

  if( isValidNum(length) ){


    int ** magicSquare = new int *[length];

    // Populate magic square to be array of pointers pointing to 
    // array of size N.

    for(int i = 0; i < length; ++i){
      magicSquare[i] = new int[length];
    }

    // Scenario 1 (default)
    std::cout << "Magic Square #1 is:" << std::endl << std::endl;
    setMagicSquare(magicSquare, length );
    printSquare(magicSquare, length);

    std::cout << std::endl;

    int * sumRow = rowSums(magicSquare, length);
    int * sumCol = colSums(magicSquare, length);
    int * sumDiagonal = diagonalSums(magicSquare, length);

    // Print out the corresponding sums for Scenario 1
    std::cout << "Checking sum of every row: ";
    printArray(sumRow, length);

    std::cout << "Checking sum of every column: ";
    printArray(sumCol, length);

    std::cout << "Checking sum of every diagonal: ";
    printArray(sumDiagonal, 2);

    std::cout << std::endl;

    //Scenario 2 (rotate 180 degrees)
    std::cout << "Magic Square #2 is:" << std::endl << std::endl;

    rotate180(magicSquare, length);
    printSquare(magicSquare, length);

    std::cout << std::endl;

    // Print out the corresponding sums for Scenario 2
    sumCol = colSums(magicSquare, length);
    sumDiagonal = diagonalSums(magicSquare, length);
    sumDiagonal = diagonalSums(magicSquare, length);

    std::cout << "Checking sum of every row: ";
    printArray(sumRow, length);

    std::cout << "Checking sum of every column: ";
    printArray(sumCol, length);

    std::cout << "Checking sum of every diagonal: ";
    printArray(sumDiagonal, 2);

    std::cout << std::endl;

    //Sceneario 3 (rotation + reflection)
    std::cout << "Magic Square #3 is:" << std::endl << std::endl;

    reflectSquare(magicSquare, length);
    printSquare(magicSquare, length);

    std::cout << std::endl;

    // Print out the corresponding sums for Scenario 3

    sumCol = colSums(magicSquare, length);
    sumDiagonal = diagonalSums(magicSquare, length);
    sumDiagonal = diagonalSums(magicSquare, length);

    std::cout << "Checking sum of every row: ";
    printArray(sumRow, length);

    std::cout << "Checking sum of every column: ";
    printArray(sumCol, length);

    std::cout << "Checking sum of every diagonal: ";
    printArray(sumDiagonal, 2);

    std::cout << std::endl;

    //Scenario 4 (Just a reflection)
    std::cout << "Magic Square #4 is:" << std::endl << std::endl;

    rotate180(magicSquare, length); //This will revert array to normal orientation
    printSquare(magicSquare, length);

    std::cout << std::endl;

    // Print out the corresponding sums for Scenario 4
    sumCol = colSums(magicSquare, length);
    sumDiagonal = diagonalSums(magicSquare, length);
    sumDiagonal = diagonalSums(magicSquare, length);

    std::cout << "Checking sum of every row: ";
    printArray(sumRow, length);

    std::cout << "Checking sum of every column: ";
    printArray(sumCol, length);

    std::cout << "Checking sum of every diagonal: ";
    printArray(sumDiagonal, 2);

    std::cout << std::endl;

    //Scenario 5 diagonal reflection
    std::cout << "Magic Square #5 is:" << std::endl << std::endl;

    diagonalReflect(magicSquare, length);
    printSquare(magicSquare, length);

    std::cout << std::endl;

    // Print out the corresponding sums for Scenario 5
    sumCol = colSums(magicSquare, length);
    sumDiagonal = diagonalSums(magicSquare, length);
    sumDiagonal = diagonalSums(magicSquare, length);

    std::cout << "Checking sum of every row: ";
    printArray(sumRow, length);

    std::cout << "Checking sum of every column: ";
    printArray(sumCol, length);

    std::cout << "Checking sum of every diagonal: ";
    printArray(sumDiagonal, 2);

  } else {
    std::cout << "The number was too large, too small, or was even!" << std::endl;
  }
}
