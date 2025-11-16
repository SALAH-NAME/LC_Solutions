#!/bin/python3

from typing import List
from dataclasses import dataclass

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        s_to_t= {}
        t_to_s= {}

        for cs, ct in zip(s, t):
            if cs in s_to_t:
                if s_to_t[cs] != ct:
                    return False
            else:
                s_to_t[cs] = ct

            if ct in t_to_s:
                if t_to_s[ct] != cs:
                    return False
            else:
                t_to_s[ct] = cs
        return True

@dataclass
class TestCase:
    s: str
    t: str

def main():
    tests : List[TestCase] = [
        TestCase("egg", "add"),
        TestCase("foo", "bar"),
        TestCase("paper", "title"),
    ]

    for t in tests:
        print(f"---\ns='{t.s}' t='{t.t}'")
        print(f"isIsomorphic: {Solution().isIsomorphic(t.s, t.t)}")

if __name__ == "__main__":
    main()
