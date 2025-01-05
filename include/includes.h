//
// Created by root on 12/27/24.
//

#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <limits>
#include <memory>
#include <ranges>
#include <cassert>
#include <functional>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

using namespace std;
#endif //INCLUDES_H
