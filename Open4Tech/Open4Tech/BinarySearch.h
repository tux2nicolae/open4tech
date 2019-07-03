#pragma once

#include<iostream> 
#include<vector>
#include<algorithm>

int BinarySearch(const std::vector<int>& data, int x)
{
  int l = 0;
  int r = data.size() - 1;

  while (l <= r) {
    int m = l + (r - l) / 2;

    if (data[m] == x)
      return m;

    if (data[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }

  // not found
  return -1;
}

void SearchTest()
{
  const std::vector<int>& data{
    5,
    34,
    21,
    45,
    78,
    84,
    93,
    100,
    109,
    120,
    188,
    215,
    235,
    247,
    342,
  };

  std::cout << BinarySearch(data, 6) << std::endl;
}
