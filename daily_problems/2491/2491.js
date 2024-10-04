/*
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player.
Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
The chemistry of a team is equal to the product of the skills of the players on that team.
Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

Explanation:
1. Sort the skill array.
2. Check if the sum of the first and last player is equal to the total sum of other possible teams.
3. If the sum is consistent for all pairs, calculate the chemistry (product of skill pairs).
4. If any pair does not match, return -1 as teams cannot be formed equally.
5. Return the total chemistry sum for valid teams.
*/

var dividePlayers = function(skill) {
    skill.sort((a, b) => a - b);
    let n = skill.length;
    let totalSum = skill[0] + skill[n - 1];
    let chemistrySum = 0;

    for (let i = 0; i < n / 2; i++) {
        if (skill[i] + skill[n - 1 - i] !== totalSum) {
            return -1;
        }
        chemistrySum += skill[i] * skill[n - 1 - i];
    }
    return chemistrySum;
};
