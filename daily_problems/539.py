# Q. Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
#24 h format 
#HH - 0-23 MM - 0-59
#difference between 23:59 and 00:00 is only 1 minute, even if its a different day


#approach: 
#convert time to minutes: ie. 15:10 becomes 15* 60 + 10 = 910 minutes
#SOrt the lists of time 
#check difference

#STEPS:
#1. Convert time to minutes
#2. Sort list of time (in minutes)
#3. Compare the difference between adjacent times
#4. Also compare the difference between last and first time to handle the wrap around case
#5. Return the minimum difference

def findMinDifference(timePoints):
    if len(timePoints) > 1440:
        return 0

    time_set = [False] * 1440

    def timeToMinutes(time):
        hours, minutes = map(int, time.split(':'))
        return hours * 60 + minutes
        
    for time in timePoints: 
        minutes = timeToMinutes(time)
        if time_set[minutes]:
            return 0
        
        time_set[minutes] = True

    prev = -1
    first = -1
    last = -1
    min_diff = floar('inf')

    for i in range(1440):
        if time_set[i]:
            if prev != -1:
                min_diff = min(min_diff, i - prev)
            else:
                first = i
            
            prev = i
            last = i

    
    min_diff = min(min_diff, 1440 - (last - first))

    return min_diff
