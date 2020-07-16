from typing import List

def reorderLogFiles(logs: List[str]) -> List[str]:
    letters = []
    digits = []
    for log in logs:
        br = log.split()
        if br[1].isalpha():
            letters.append(" ".join(br[1:]) + " " + br[0])
        else:
            digits.append(log)
    # print(letters)
    letters = sorted(letters)
    # print(letters)
    for i in range(len(letters)):
        br = letters[i].split()
        letters[i] = br[-1] + " " + " ".join(br[:-1])

    return letters + digits

def generateParenthesis(n: int) -> List[str]:
    result = []
    def temp(lefts, rights, curr):
        if lefts > rights:
            return
        if lefts == 0 and rights == 0:
            result.append(curr)
        elif lefts == 0 and rights > 0:
            temp(0, rights-1, curr+")")
        else:
            temp(lefts-1, rights, curr+"(")
            temp(lefts, rights-1, curr+")")
    temp(n, n, "")
    return result

if __name__ == "__main__":
    print(reorderLogFiles(["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]))
    print(generateParenthesis(3))