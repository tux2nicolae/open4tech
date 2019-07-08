#pragma once

#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int Search(const string& str, const string& substr)
{
  static const int kPrime = 31991;
  static const int kBase = 256;

  if (substr.size() > str.size())
    return 0;

  // calculate the pattern and first window hash 
  int strHash = 0;
  int substrHash = 0;

  for (size_t i = 0; i < substr.size(); i++)
  {
    strHash = (strHash * kBase + str[i]) % kPrime;
    substrHash = (substrHash * kBase + substr[i]) % kPrime;
  }

  // the height would be "pow(kBase, substr.size() - 1) % kPrime"  
  // in our case 256 ^ 7
  int height = 1;
  for (size_t i = 0; i < substr.size() - 1; i++)
    height = (height * kBase) % kPrime;

  // move the window one by one
  for (size_t i = 0; i <= str.size() - substr.size(); i++)
  {
    // check the hash match
    // if we have a match we sould check if it's our string
    if (strHash == substrHash)
    {
      size_t j = 0;
      for (j = 0; j < substr.size(); j++)
      {
        if (str[i + j] != substr[j])
          break;
      }

      if (j == substr.size())
        return i;
    }

    // calculate the hash value for the next window of text
    // 1. remove first digit
    // 2. add second digit
    if (i < str.size() - substr.size())
    {
      strHash -= (str[i] * height) % kPrime;
      if (strHash < 0)
        strHash += kPrime;

      strHash = (strHash * kBase + str[i + substr.size()]) % kPrime;
    }
  }

  return -1;
}
