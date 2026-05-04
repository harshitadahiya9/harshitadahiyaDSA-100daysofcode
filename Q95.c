def bucket_sort(arr):
    n = len(arr)
    if n == 0:
        return arr

    # Step 1: Create buckets
    buckets = [[] for _ in range(n)]

    # Step 2: Distribute elements into buckets
    for x in arr:
        index = int(n * x)  # since x in [0,1)
        buckets[index].append(x)

    # Step 3: Sort individual buckets
    for i in range(n):
        buckets[i].sort()

    # Step 4: Concatenate buckets
    output = []
    for bucket in buckets:
        output.extend(bucket)

    return output
