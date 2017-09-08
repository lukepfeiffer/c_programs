#include <iostream>

using namespace std;

bool isPerfectScore(int score, int maxScore){
  if( maxScore == score ){
    return true;
  } else {
    return false;
  }
}

char getGrade(int score, int maxScore){
  char grade;
  if( score >= maxScore*0.90 ){
    grade = 'A';
  } else if( score >= maxScore*.80){
    grade = 'B';
  } else if( score >= maxScore*0.70){
    grade = 'C';
  } else if( score >= maxScore*0.60){
    grade = 'D';
  } else {
    grade = 'F';
  }
  return grade;
}

int main(){
  char answer = 'y';
  bool moreScores = true;
  int numStudents;
  int maxScore;

  cout << "How many students are there?" << endl;
  cin >> numStudents;

  cout << "What is the max score?" << endl;
  cin >> maxScore;

  for(int i = 0; i < numStudents; ++i){
    int score;

    cout << "Enter a score" << endl;
    cin >> score;

    cout << "The student receive an " << getGrade(score, maxScore) << endl;

    if( isPerfectScore(score, maxScore) ){
      cout << "That student received a perfect score!" << endl;
    }
  }

  cout << "All scores successfully scored" << endl;

}
