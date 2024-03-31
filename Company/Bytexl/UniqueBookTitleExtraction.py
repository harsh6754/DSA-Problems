from collections import Counter
from itertools import groupby

n = int(input())

survey_responses = [input().split(', ') for _ in range(n)]

book_titles = [book_title for response in survey_responses for book_title in response]

book_freq = Counter(book_titles)

sorted_book_freq = sorted(book_freq.items())

for title, freq in sorted_book_freq:
    print(f'{title}: {freq}')
