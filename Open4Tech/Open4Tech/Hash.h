#pragma once

#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>

int hash(const std::string& key)
{
  int value{ 0 };
  for (auto c : key)
    value += c;

  return value;
}
