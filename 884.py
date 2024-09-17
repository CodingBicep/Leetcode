class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> list[str]:
        words = A.split() + B.split()
        count = Counter(words)

        return [word for word, freq in count.items() if freq ==1]