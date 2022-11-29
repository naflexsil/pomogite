
              /*************************************
              *                                    *
              *      Старикова Алина Павловна      *
              *         "Частота повторений"       *
              *               ПИ-221               *
              *                                    *
              **************************************/
              
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int maxNumber; cout << " задайте максимум текста: ";
  cin >> maxNumber;
  int oneLetterArray[maxNumber];
  fstream oneLetterFile;
  char letter;
	
  oneLetterFile.open("anecdote");
  if(!oneLetterFile) {
  cout << " файл не найден";
  }
	
  for(int ooneIndex = 0; ooneIndex < maxNumber; ++ooneIndex) {
  oneLetterArray[ooneIndex] = 0;
  }
  letter = oneLetterFile.get();
  while(letter != EOF) {  // "EOF" - спрашивает, достигнут ли конец файла
    letter = toupper(letter);  // "toupper" - преобразовывает строчные буквы в прописные
    ++oneLetterArray[letter];
    letter = oneLetterFile.get();  // ".get" - чтение фулл строки
  }
	
  cout << "\n повторяющиеся буквы:" << endl << "\n";
    for(letter = 'A'; letter <= 'Z'; ++letter) {
	  if(oneLetterArray[letter] > 1) {
        cout << letter << ": " << oneLetterArray[letter] - 1 << "\n";
	  }
	}

  cout << "\n";

  int twoLetterArray[maxNumber][maxNumber];
  fstream twoLetterFile;
	
  twoLetterFile.open("anecdote");
  if(!twoLetterFile) {
    cout << " файл не найден";
  }
	
  for(int oneIndex = 0; oneIndex < maxNumber; ++oneIndex) {
	for(int twoIndex = 0; twoIndex < maxNumber; ++twoIndex) {
      twoLetterArray[oneIndex][twoIndex] = 0;
	}
  }
	
  char firstLetter, secondLetter;
	
  firstLetter = twoLetterFile.get();
  secondLetter = twoLetterFile.get();
	
  while(secondLetter != EOF) {
  firstLetter = toupper(firstLetter);
  secondLetter = toupper(secondLetter);
  ++twoLetterArray[firstLetter][secondLetter];
  firstLetter = twoLetterFile.get();
  secondLetter = twoLetterFile.get();
  }
	
  cout << " повторяющиеся двухбуквенные значения:" << endl << "\n";
  for(firstLetter = 'A'; firstLetter <= 'Z'; ++firstLetter) {
    for(secondLetter = 'A'; secondLetter <= 'Z'; ++secondLetter) {
	  if(twoLetterArray[firstLetter][secondLetter]) {
        cout << firstLetter << secondLetter << ": " << twoLetterArray[firstLetter][secondLetter] << "\n";
	  }
	}
  }
} 