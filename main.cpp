//Name: Jose Castro
//Course: 23SPR-CIS-7-23821
//Professor: PhD, Kasey Nguyen
//Date: 5/30/2023

#include <iostream>
using namespace std; 

string message;
string mappedKey;

void messageAndKey()
{
  string msg;
  cout << " Input message: ";
  getline(cin,msg);
  cin.ignore();

  //message to uppercase
  for(int i = 0; i < msg.length(); i++) {
    msg[i] = toupper(msg[i]);
    }

  string key;
  cout << " Keyword: ";
  getline(cin,key);
  cin.ignore();

  //key to uppercase
  for(int i = 0; i < key.length(); i++)
  {
    key[i] = toupper(key[i]);
  }
  //mapping key to message 
  string keyMap = "" ;
  for (int i = 0, j = 0; i < msg.length(); i++)
    {
      if (msg[i] == 32)
      {
        keyMap += 32;
      } 
      else
      {
        if(j<key.length())
        {
          keyMap += key[j]; 
          j++;
        }
        else
        {
          j = 0;
          keyMap += key [j];
          j++;
        }
      }
    }
  cout << msg << "\n" << keyMap;
  message = msg;
  mappedKey = keyMap;
}

int tableArr[26][26];
void creatVigenereTable()
{
  for(int i = 0; i < 26; i++)
    {
    for(int j = 0; j < 26; j++)
      {
      int temp;
      if((i+65)+j > 90)
        {
        temp = ((i+65)+j) - 26;
          
          //adding ASCII of aphabet letter
          tableArr[i][j] = temp;
        }
      else
      {
        temp = (i + 65 ) + j;
        //adding ASCII of aphabet letter 
        tableArr[i][j] = temp;
      }
      }
    }
}
void cipherEncryption(string message, string mappedKey)
{
  creatVigenereTable();
  string encryptedText = "";
  for(int i = 0; i < message.length(); i++)
    {
      if(message[i] == 32 && mappedKey[i] == 32)
      {
        encryptedText += "";
      }
      else
      {
        int x = (int) message [i] - 65;
        int y = (int) mappedKey [i] - 65;
        encryptedText += (char)tableArr[x][y];
      }
    }
  cout <<" Encrypted Text: " << encryptedText;
}
int itrCount(int key, int msg)
{
  int counter = 0;
  string result = "";

  //beginning with the ASCII letter of the key and ending with the letter of the message
  //to obtain all 26 letters of the alphabet
  for (int i = 0; i < 26; i++)
    {
      if(key + i > 90)
      {
        result += (char) (key + (i - 26));
      }
      else
      {
        result += (char) (key + i);
      }
    }
  for (int i = 0; i < result.length(); i++)
    {
      if(result[i] == msg)
      {
        break;
      }
      else
      {
        counter++;
      }
    }
  return counter;
}

void cipherDecryption (string message, string mappedKey)
{
  string decryptedText = "";
  for(int i = 0; i < message.length(); i++)
    {
      if(message[i] == 32 && mappedKey[i] == 32)
      {
        decryptedText += " ";
      }
      else
      {
        int temp = itrCount((int)mappedKey[i], (int)message[i]);
        decryptedText += (char) (65 + temp);
      }
    }
  cout << " Decrypted Text: " << decryptedText;
}
int main()
{
  cout << " Hello, Welcome to Encryption & Decryption program. \n Please enter the following selection." << endl;
  int choice;
  cout <<" 1. Encryption\n 2. Decryption\n Please chosse option(1 or 2): ";
  cin >> choice;
  cin.ignore();

  if (choice == 1)
  {
    cout << "You have selceted Encryption" << endl;
    messageAndKey();
    cipherEncryption(message, mappedKey);
    
  }
  else if (choice == 2) 
  {
    cout << "You have selceted Decryption" << endl;
    messageAndKey();
    cipherDecryption(message, mappedKey);
  }
  else
  {
    cout << "incorrect choice" << endl;
  }
  return 0;
}
