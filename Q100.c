def count_smaller(nums):
    n = len(nums)
    result = [0] * n

    # store (value, original_index)
    arr = list(enumerate(nums))

    def merge_sort(arr):
        if len(arr) <= 1:
            return arr

        mid = len(arr) // 2
        left = merge_sort(arr[:mid])
        right = merge_sort(arr[mid:])

        merged = []
        j = 0  # pointer for right

        # merge step
        for i in range(len(left)):
            while j < len(right) and right[j][1] < left[i][1]:
                merged.append(right[j])
                j += 1

            # count how many from right are smaller
            result[left[i][0]] += j
            merged.append(left[i])

        # add remaining
        merged.extend(right[j:])
        return merged

    merge_sort(arr)
    return result


# Example
nums = [5, 2, 6, 1]
print(count_smaller(nums))
