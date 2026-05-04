def counting_sort(arr):
    if not arr:
        return arr

    max_val = max(arr)

    # Step 1: Frequency array
    count = [0] * (max_val + 1)
    for num in arr:
        count[num] += 1

    # Step 2: Prefix sums
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Step 3: Build output array
    output = [0] * len(arr)
    for num in reversed(arr):  # traverse backward for stability
        count[num] -= 1
        output[count[num]] = num

    return output
