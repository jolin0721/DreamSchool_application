def minSubsequence(source, target):
    source_len = len(source)
    target_len = len(target)
    count = 0
    num = 0
    last = -1

    for i in range(target_len):
        included = -1  # Initialize to -1 to indicate not found
        notinbehind = 1

        # Find the index of the current target character in the source string
        for j in range(source_len):
            if target[i] == source[j]:
                included = j
                num += 1
                break

        # If the character is not found in the source string, return -1
        if included == -1:
            return -1

        # Check if the character is not behind the last occurrence
        if included > last:
            notinbehind = 0
            last = included

        # If the character is not behind the last occurrence, increment count
        if notinbehind == 1 or (notinbehind == 0 and i == target_len - 1):
            count += 1
            num = 0

    return count

def main():
    source1 = "abc"
    target1 = "acbacb"
    print(minSubsequence(source1, target1))

if __name__ == "__main__":
    main()
