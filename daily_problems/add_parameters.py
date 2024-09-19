#class Solution:
#    def diffWaysToCompute(self, expression: str) -> List[int]:
#        if expression.isdigit():
#            return [int(expression)]
#        results = []
#
#        for i, char in enumerate(expression):
#            if char in "+-*":
#                left_results = self.diffWaysToCompute(expression[:i])
#                right_results = self.diffWaysToCompute(expression[i+1:])
#
#                for left in left_results:
#                    for right in right_results:
#                        if chat == '+':
#                            results.append(left+right)
#                        elif char == '-':
#                            results.append(left-right)
#                        elif char == '*':
#                            results.append(left * right)
#            return results.[]
#
#OPTIMIZED SOLUTION

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        memo = {}

        def compute(expression):
            if expression in memo:
                return memo[expression]

            if expression.isdigit():
                return [int(expression)]
            
            results = []

            for i, char in enumerate(expression):
                if char in "+-*":
                    left_results = compute(expression[:i])
                    right_results = compute(expression[i+1:])

                    for left in left_results:
                        for right in right_results:
                            if char == '+':
                                results.append(left + right)
                            elif char == '-':
                                results.append(left - right)
                            elif char == '*':
                                results.append(left * right)

            memo[expression] = results
            return results
        return compute(expression)