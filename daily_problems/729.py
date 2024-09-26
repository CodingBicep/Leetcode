class MyCalendar:

    def __init__(self):
        # List to store all booked events as tuples (start, end)
        self.bookings = []

    def book(self, start: int, end: int) -> bool:
        # Check if the new event overlaps with any existing event
        for s, e in self.bookings:
            if max(s, start) < min(e, end):
                # There is an overlap if the intervals intersect
                return False
        
        # If no overlap, add the event to the bookings list
        self.bookings.append((start, end))
        return True