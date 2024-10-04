/*
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. 
Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
The chemistry of a team is equal to the product of the skills of the players on that team.
Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

The plan:
1. Sort the array.
2. Ensure that pairs of first and last element sum to the same value.
3. If they do, sum their product (chemistry). Otherwise, return -1.
*/

class Solution {
public:
    int dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int totalSum = skill[0] + skill[n - 1];
        int chemistrySum = 0;

        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n - 1 - i] != totalSum) {
                return -1;
            }
            chemistrySum += skill[i] * skill[n - 1 - i];
        }

        return chemistrySum;
    }
};
