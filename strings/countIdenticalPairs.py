"""
the task is to count total number of identical pair of strings possible

two strings are identical if both strings have same unique characters
eg in string \"good\" and \"god\" both have g o and d hence they are identical

python -> p y t h o n
yarn  -> y a r n      -> only y and n are matching hence not identical


"""

# the idea is
# we are given a list of strings
# since set is mutable hence it cannot be used as a key in the dictonary
# the only data structure that is immutable and stores only unique value is frozenset
#

def solution(lst:[str]):
    pair_counts =0
    char_set_counts={}
    # printing the list
    for i in lst:
        unique_chars=frozenset(i)
        if unique_chars in char_set_counts:
            pair_counts+=char_set_counts[unique_chars]
            char_set_counts[unique_chars]+=1
        else:
            char_set_counts[unique_chars]=1
    return pair_counts

solution(["good","god","bac","abc"])

# tc is
# o(n*l) n is the numer of strings , is the max length of the string
# sc is
# o(n*k) k is the number of unique characters in alphabet at max 26
# the dict stores atmost n unique character sets
