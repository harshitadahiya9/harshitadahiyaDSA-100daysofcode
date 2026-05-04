def merge_intervals(intervals):
    if not intervals:
        return []

    # Step 1: Sort by start time
    intervals.sort(key=lambda x: x[0])

    merged = [intervals[0]]

    # Step 2: Traverse and merge
    for current in intervals[1:]:
        last = merged[-1]

        # Check overlap
        if current[0] <= last[1]:
            # Merge intervals
            last[1] = max(last[1], current[1])
        else:
            # No overlap → add new interval
            merged.append(current)

    return merged


# Example
intervals = [[1,3], [2,6], [8,10], [15,18]]
print(merge_intervals(intervals))
