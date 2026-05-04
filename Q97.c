import heapq

def min_meeting_rooms(intervals):
    if not intervals:
        return 0

    # Step 1: Sort by start time
    intervals.sort(key=lambda x: x[0])

    # Step 2: Min-heap to store end times
    heap = []

    # Add first meeting
    heapq.heappush(heap, intervals[0][1])

    # Process remaining meetings
    for i in range(1, len(intervals)):
        start, end = intervals[i]

        # If earliest meeting ended, reuse room
        if heap[0] <= start:
            heapq.heappop(heap)

        # Allocate room (push end time)
        heapq.heappush(heap, end)

    # Heap size = number of rooms needed
    return len(heap)


# Example
intervals = [(0, 30), (5, 10), (15, 20)]
print(min_meeting_rooms(intervals))
