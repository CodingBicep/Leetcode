class MyCalendarTwo:

    def __init__(self):
        self.bookings = []
        self.overlaps = []

    def book(self, start: int, end: int) -> bool:
        for ostart, oend in self.overlaps:
            if max(start, ostart) < min(end, oend):
                return False
        
        for bstart, bend in self.bookings:
            if max(start, bstart) < min(end, bend): 
                overlap_start = max(start, bstart)
                overlap_end = min(end, bend)
                self.overlaps.append((overlap_start, overlap_end))  
        self.bookings.append((start, end))
        return True

# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)

# OPTIMAL SOLUTION / BETTER SOLUTION:

