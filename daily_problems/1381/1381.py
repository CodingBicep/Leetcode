class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.maxSize = maxSize
        self.incArr = [0] * maxSize

    def push(self, x: int) -> None:
        if len(self.stack) < self.maxSize:
            self.stack.append(x)

    def pop(self) -> int:
        if not self.stack:
            return -1
        index = len(self.stack) - 1
        if index > 0:
            self.incArr[index - 1] += self.incArr[index]
        res = self.stack.pop() + self.incArr[index]
        self.incArr[index] = 0
        return res

    def increment(self, k: int, val: int) -> None:
        limit = min(k, len(self.stack)) - 1
        if limit >= 0:
            self.incArr[limit] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)