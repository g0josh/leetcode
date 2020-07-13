def climbStairs(n: int) -> int:
    # https://www.youtube.com/watch?v=NFJ3m9a1oJQ
    if n < 2:
        return 1
    result = 1
    prv_result = 1
    for i in range(2, n+1):
        r = result+prv_result
        prv_result = result
        result = r
    return result

def maxProfit(prices: List[int]) -> int:
    pass

if __name__ == "__main__":
    print(climbStairs(6))