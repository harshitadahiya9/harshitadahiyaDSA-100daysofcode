def bucket_sort(arr):
    n = len(arr)
    if n == 0:
        return arr

    # Step 1: Create n empty buckets
    buckets = [[] for _ in range(n)]

    # Step 2: Put array elements into buckets
    for x in arr:
        index = int(n * x)   # bucket index
        buckets[index].append(x)

    # Step 3: Sort individual buckets
    for i in range(n):
        buckets[i].sort()   # you can also use insertion sort

    # Step 4: Concatenate all buckets
    result = []
    for bucket in buckets:
        result.extend(bucket)

    return result


# Example usage
arr = [0.42, 0.32, 0.23, 0.52, 0.25]
sorted_arr = bucket_sort(arr)
print(sorted_arr)
