def count_13(num_dig):
    nums = [f'{i:020}'[-1*num_dig:] for i in range(0, 10**num_dig) if '13' not in f'{i:020}'[-1*num_dig:]]
    return len(nums)